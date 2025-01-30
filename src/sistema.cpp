#include "Sistema.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

std::string Sistema::gerarChaveUsuario(const std::string& nome, const std::string& sobrenome) {
    return nome + "_" + sobrenome;
}

void Sistema::carregarUsuarios() {
    std::ifstream inputFile("usuarios.txt");
    if (inputFile.is_open()) {
        std::string nome, sobrenome, senha;
        int idade;
        bool administrador;
        while (inputFile >> nome >> sobrenome >> senha >> idade >> administrador) {
            std::string chave = gerarChaveUsuario(nome, sobrenome);
            usuarios.emplace(chave, Cadastro::criarConta(nome, sobrenome, senha, idade, administrador));
        }
        inputFile.close();
    }
}

void Sistema::salvarUsuarios() {
    std::ofstream outputFile("usuarios.txt");
    if (outputFile.is_open()) {
        for (const auto& pair : usuarios) {
            const Usuario& usuario = pair.second;
            outputFile << usuario.getNomeCompleto() << " " << usuario.getSenha() << " " << usuario.getIdade() << " " << usuario.isAdministrador() << std::endl;
        }
        outputFile.close();
    }
}

void Sistema::adicionarUsuario(const std::string& nome, const std::string& sobrenome, const std::string& senha, int idade, bool administrador) {
    std::string chave = gerarChaveUsuario(nome, sobrenome);
    if (usuarios.find(chave) == usuarios.end()) {
        usuarios.emplace(chave, Cadastro::criarConta(nome, sobrenome, senha, idade, administrador));
        Logger::log("Usuario " + nome + " " + sobrenome + " registrado com sucesso.");
        salvarUsuarios();
    } else {
        Logger::log("Usuario " + nome + " " + sobrenome + " ja existe.");
    }
}

bool Sistema::logarUsuario(const std::string& nome, const std::string& sobrenome, const std::string& senha) {
    std::string chave = gerarChaveUsuario(nome, sobrenome);
    auto it = usuarios.find(chave);
    if (it != usuarios.end() && Login::validarCredenciais(it->second, senha)) {
        usuarioAtual = &it->second;
        Logger::log("Usuario " + nome + " " + sobrenome + " logado com sucesso.");
        return true;
    }
    Logger::log("Falha no login para o usuario " + nome + " " + sobrenome + ".");
    return false;
}

void Sistema::logout() {
    if (usuarioAtual) {
        Logger::log("Usuario " + usuarioAtual->getNomeCompleto() + " deslogado.");
        usuarioAtual = nullptr;
    } else {
        Logger::log("Nenhum usuario esta logado.");
    }
}

Usuario* Sistema::getUsuarioAtual() {
    return usuarioAtual;
}

Usuario* Sistema::buscarUsuario(const std::string& nome, const std::string& sobrenome) {
    std::string chave = gerarChaveUsuario(nome, sobrenome);
    auto it = usuarios.find(chave);
    return (it != usuarios.end()) ? &it->second : nullptr;
}

void Sistema::acessarLogAdministrador() {
    if (usuarioAtual && usuarioAtual->isAdministrador()) {
        std::ifstream arquivoLog("log.txt");
        if (arquivoLog.is_open()) {
            std::string linha;
            Logger::log("Log Geral de Transacoes:");
            while (std::getline(arquivoLog, linha)) {
                Logger::log(linha);
            }
            arquivoLog.close();
        } else {
            Logger::log("Erro ao acessar o log geral.");
        }
    } else {
        Logger::log("Acesso negado. Apenas administradores podem acessar o log geral.");
    }
}

void Sistema::alterarSenhaAdmin() {
    std::string novaSenha;
    Logger::log("Digite a nova senha de administrador: ");
    std::cin >> novaSenha;
    senhaAdmin = novaSenha;
    Logger::log("Senha de administrador alterada com sucesso.");
}

std::string Sistema::getSenhaAdmin() const {
    return senhaAdmin;
}

void Sistema::exibirMenuInicial() {
    std::string entrada;
    int opcao = -1;

    do {
        Logger::log("\nMenu Inicial:\n1. Registrar Conta\n2. Fazer Login\n3. Acessar Log Administrador\n4. Alterar Senha Administrador\n0. Sair\nEscolha: ");
        std::cin >> entrada;

        if (entrada.size() == 1 && isdigit(entrada[0])) {
            opcao = entrada[0] - '0';
        } else {
            opcao = -1;
        }

        switch (opcao) {
            case 1:
                registrarConta();
                break;
            case 2:
                fazerLogin();
                break;
            case 3:
                acessarLogAdministrador();
                break;
            case 4:
                alterarSenhaAdmin();
                break;
            case 0:
                Logger::log("Encerrando o sistema. Ate a proxima!");
                break;
            default:
                Logger::log("Opcao invalida. Por favor, escolha uma das opcoes fornecidas.");
        }
    } while (opcao != 0);
}

void Sistema::registrarConta() {
    std::string nome, sobrenome, senha;
    int idade;

    Logger::log("Digite o nome: ");
    std::cin.ignore();
    std::getline(std::cin, nome);
    Logger::log("Digite o sobrenome: ");
    std::getline(std::cin, sobrenome);
    Logger::log("Digite a senha: ");
    std::cin >> senha;
    Logger::log("Digite sua idade: ");
    std::cin >> idade;

    bool administrador = false;
    if (idade >= 18) {
        char adminOpcao;
        Logger::log("O usuario sera administrador? (s/n): ");
        std::cin >> adminOpcao;
        if (adminOpcao == 's' || adminOpcao == 'S') {
            std::string senhaAdmin;
            Logger::log("Digite a senha de permissao para administrador: ");
            std::cin >> senhaAdmin;
            if (senhaAdmin == getSenhaAdmin()) {
                administrador = true;
            } else {
                Logger::log("Senha de permissao incorreta. O usuario nao sera administrador.");
            }
        }
    }

    if (idade < 18) {
        std::string nomeResponsavel, sobrenomeResponsavel;
        Logger::log("Voce eh menor de idade. Informe o nome do responsavel: ");
        std::cin.ignore();
        std::getline(std::cin, nomeResponsavel);
        Logger::log("Informe o sobrenome do responsavel: ");
        std::getline(std::cin, sobrenomeResponsavel);

        Usuario* responsavel = buscarUsuario(nomeResponsavel, sobrenomeResponsavel);
        if (responsavel && responsavel->getIdade() >= 18) {
            adicionarUsuario(nome, sobrenome, senha, idade);
            buscarUsuario(nome, sobrenome)->setResponsavel(responsavel);
            Logger::log("Responsavel vinculado com sucesso.");
        } else {
            Logger::log("Responsavel invalido ou nao encontrado.");
        }
    } else {
        adicionarUsuario(nome, sobrenome, senha, idade, administrador);
    }
}

void Sistema::fazerLogin() {
    std::string nome, sobrenome, senha;
    Logger::log("Digite o nome: ");
    std::cin.ignore();
    std::getline(std::cin, nome);
    Logger::log("Digite o sobrenome: ");
    std::getline(std::cin, sobrenome);
    Logger::log("Digite a senha: ");
    std::cin >> senha;

    if (logarUsuario(nome, sobrenome, senha)) {
        if (usuarioAtual->isAdministrador()) {
            Logger::log("Logado como administrador do sistema.");
        }
        Carteira carteira;
        Historico historico;

        int opcaoUsuario;
        do {
            Logger::log("\nMenu:\n1. Depositar\n2. Retirar\n3. Exibir Saldo\n4. Exibir Historico\n5. Logout\n0. Sair\nEscolha: ");
            std::cin >> opcaoUsuario;

            if (opcaoUsuario == 1) {
                std::string valorStr;
                Logger::log("Valor a depositar: ");
                std::cin >> valorStr;
                double valor = std::stod(valorStr);
                Deposito::realizarDeposito(carteira, valor);
                historico.adicionarTransacao(Transacao(valor, "Deposito"));
            } else if (opcaoUsuario == 2) {
                std::string valorStr;
                Logger::log("Valor a retirar: ");
                std::cin >> valorStr;
                double valor = std::stod(valorStr);
                if (Retirada::realizarRetirada(carteira, valor)) {
                    historico.adicionarTransacao(Transacao(valor, "Retirada"));
                    Logger::log("Retirada de " + std::to_string(valor) + " realizada com sucesso!");
                } else {
                    Logger::log("Saldo insuficiente para realizar a retirada.");
                }
            } else if (opcaoUsuario == 3) {
                Saldo::exibirSaldo(carteira);
            } else if (opcaoUsuario == 4) {
                historico.exibirHistorico();
            } else if (opcaoUsuario == 5) {
                historico.salvarLog(usuarioAtual->getNomeCompleto());
                if (usuarioAtual->getResponsavel()) {
                    std::string logTransacoes = "Transacoes do menor " + usuarioAtual->getNomeCompleto() + ":\n";
                    std::ofstream arquivoResponsavelLog(usuarioAtual->getResponsavel()->getNomeCompleto() + "_log.txt", std::ios::app);
                    if (arquivoResponsavelLog.is_open()) {
                        arquivoResponsavelLog << logTransacoes;
                        for (const auto& transacao : historico.getTransacoes()) {
                            arquivoResponsavelLog << transacao.formatarParaLog() << std::endl;
                        }
                        arquivoResponsavelLog.close();
                    }
                }

                Logger::log("Deslogando usuario...");
                logout();
                break;
            }
        } while (opcaoUsuario != 0);
    }
}
