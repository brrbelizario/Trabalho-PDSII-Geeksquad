#include "../include/Sistema.hpp"
#include "../include/ComprarCripto.hpp"

string Sistema::gerarChaveUsuario(const string &nome, const string &sobrenome)
{
    return nome + "_" + sobrenome;
}

void Sistema::carregarUsuarios()
{
    ifstream inputFile("usuarios.txt");
    if (inputFile.is_open())
    {
        string nome, sobrenome, senha;
        int idade;
        bool administrador;
        double saldo, saldoD, saldoB;
        while (inputFile >> nome >> sobrenome >> senha >> idade >> administrador >> saldo >> saldoD >> saldoB)
        {
            string chave = gerarChaveUsuario(nome, sobrenome);
            Usuario usuario = Cadastro::criarConta(nome, sobrenome, senha, idade, administrador);

            // Criar carteira e associá-la ao usuário
            Carteira carteira;
            carteira.adicionarSaldo(saldo);
            carteira.adicionarSaldoD(saldoD);
            carteira.adicionarSaldoB(saldoB);
            usuario.setCarteira(carteira);
            usuarios.emplace(chave, usuario);
        }
        inputFile.close();
    }
}

void Sistema::salvarUsuarios()
{
    ofstream outputFile("usuarios.txt");
    if (outputFile.is_open())
    {
        for (auto &pair : usuarios)
        {
            Usuario &usuario = pair.second;
            Carteira &carteira = usuario.getCarteira();
            outputFile << usuario.getNomeCompleto() << " " << usuario.getSenha() << " " << usuario.getIdade() << " " << usuario.isAdministrador() << " " << carteira.getSaldo() << " " << carteira.getSaldoB() << " " << carteira.getSaldoD() << " " << endl;
        }
        outputFile.close();
    }
}

void Sistema::adicionarUsuario(const string &nome, const string &sobrenome, const string &senha, int idade, bool administrador)
{
    string chave = gerarChaveUsuario(nome, sobrenome);
    if (usuarios.find(chave) == usuarios.end())
    {
        Usuario usuario = Cadastro::criarConta(nome, sobrenome, senha, idade, administrador);
        usuarios.emplace(chave, usuario);
        Logger::log("Usuario " + nome + " " + sobrenome + " registrado com sucesso.");
        salvarUsuarios();
    }
    else
    {
        Logger::log("Usuario " + nome + " " + sobrenome + " ja existe.");
    }
}

bool Sistema::logarUsuario(const string &nome, const string &sobrenome, const string &senha)
{
    string chave = gerarChaveUsuario(nome, sobrenome);
    auto it = usuarios.find(chave);
    if (it != usuarios.end() && Login::validarCredenciais(it->second, senha))
    {
        usuarioAtual = &it->second;
        Logger::log("Usuario " + nome + " " + sobrenome + " logado com sucesso.");
        return true;
    }
    Logger::log("Falha no login para o usuario " + nome + " " + sobrenome + ".");
    return false;
}

void Sistema::logout()
{
    if (usuarioAtual)
    {
        Logger::log("Usuario " + usuarioAtual->getNomeCompleto() + " deslogado.");
        salvarUsuarios(); // Salva os dados antes de sair
        usuarioAtual = nullptr;
    }
    else
    {
        Logger::log("Nenhum usuario esta logado.");
    }
}

Usuario *Sistema::getUsuarioAtual() { return usuarioAtual; }

Usuario *Sistema::buscarUsuario(const string &nome, const string &sobrenome)
{
    string chave = gerarChaveUsuario(nome, sobrenome);
    auto it = usuarios.find(chave);
    return (it != usuarios.end()) ? &it->second : nullptr;
}

void Sistema::acessarLogAdministrador()
{
    if (usuarioAtual && usuarioAtual->isAdministrador())
    {
        ifstream arquivoLog("log.txt");
        if (arquivoLog.is_open())
        {
            string linha;
            Logger::log("Log Geral de Transacoes:");
            while (getline(arquivoLog, linha))
            {
                Logger::log(linha);
            }
            arquivoLog.close();
        }
        else
        {
            Logger::log("Erro ao acessar o log geral.");
        }
    }
    else
    {
        Logger::log("Acesso negado. Apenas administradores podem acessar o log geral.");
    }
}

void Sistema::alterarSenhaAdmin()
{
    string novaSenha;
    Logger::log("Digite a nova senha de administrador: ");
    cin >> novaSenha;
    senhaAdmin = novaSenha;
    Logger::log("Senha de administrador alterada com sucesso.");
}

string Sistema::getSenhaAdmin() const { return senhaAdmin; }

void Sistema::exibirMenuInicial()
{
    string entrada;
    int opcao = -1;

    do
    {
        Logger::log("\nMenu Inicial:\n1. Registrar Conta\n2. Fazer Login\n3. Acessar Log Administrador\n4. Alterar Senha Administrador\n0. Sair\nEscolha: ");
        cin >> entrada;

        if (entrada.size() == 1 && isdigit(entrada[0]))
        {
            opcao = entrada[0] - '0';
        }
        else
        {
            opcao = -1;
        }

        switch (opcao)
        {
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

void Sistema::registrarConta()
{
    string nome, sobrenome, senha;
    int idade;

    Logger::log("Digite o nome: ");
    cin.ignore();
    getline(cin, nome);
    Logger::log("Digite o sobrenome: ");
    getline(cin, sobrenome);
    Logger::log("Digite a senha: ");
    cin >> senha;
    Logger::log("Digite sua idade: ");
    cin >> idade;

    bool administrador = false;
    if (idade >= 18)
    {
        char adminOpcao;
        Logger::log("O usuario sera administrador? (s/n): ");
        cin >> adminOpcao;
        if (adminOpcao == 's' || adminOpcao == 'S')
        {
            string senhaAdmin;
            Logger::log("Digite a senha de permissao para administrador: ");
            cin >> senhaAdmin;
            if (senhaAdmin == getSenhaAdmin())
            {
                administrador = true;
            }
            else
            {
                Logger::log("Senha de permissao incorreta. O usuario nao sera administrador.");
            }
        }
    }

    if (idade < 18)
    {
        string nomeResponsavel, sobrenomeResponsavel;
        Logger::log("Voce eh menor de idade. Informe o nome do responsavel: ");
        cin.ignore();
        getline(cin, nomeResponsavel);
        Logger::log("Informe o sobrenome do responsavel: ");
        getline(cin, sobrenomeResponsavel);

        Usuario *responsavel = buscarUsuario(nomeResponsavel, sobrenomeResponsavel);
        if (responsavel && responsavel->getIdade() >= 18)
        {
            adicionarUsuario(nome, sobrenome, senha, idade, administrador);
            buscarUsuario(nome, sobrenome)->setResponsavel(responsavel);
            Logger::log("Responsavel vinculado com sucesso.");
        }
        else
        {
            Logger::log("Responsavel invalido ou nao encontrado.");
        }
    }
    else
    {
        adicionarUsuario(nome, sobrenome, senha, idade, administrador);
    }
}

void Sistema::fazerLogin()
{
    string nome, sobrenome, senha;
    Logger::log("Digite o nome: ");
    cin.ignore();
    getline(cin, nome);
    Logger::log("Digite o sobrenome: ");
    getline(cin, sobrenome);
    Logger::log("Digite a senha: ");
    cin >> senha;

    if (logarUsuario(nome, sobrenome, senha))
    {
        if (usuarioAtual->isAdministrador())
        {
            Logger::log("Logado como administrador do sistema.");
        }

        Carteira &carteira = usuarioAtual->getCarteira(); // Pegando a carteira do usuário
        Historico historico;
        ComprarCripto comprar(carteira.getSaldoB(), carteira.getSaldoD(), carteira);

        int opcaoUsuario;
        do
        {
            Logger::log("\nMenu:\n1. Depositar\n2. Retirar\n3. Exibir Saldo\n4. Exibir Historico\n5. Comprar CriptoMoeda\n6. Logout\nEscolha: ");
            cin >> opcaoUsuario;

            if (cin.fail())
            {
                Logger::log("Entrada inválida. Digite um número entre 1 e 6.");
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (opcaoUsuario == 1)
            {
                double valor;
                Logger::log("Valor a depositar: ");
                cin >> valor;
                Deposito::realizarDeposito(carteira, valor);
                historico.adicionarTransacao(Transacao(valor, "Deposito"));
            }
            else if (opcaoUsuario == 2)
            {
                double valor;
                Logger::log("Valor a retirar: ");
                cin >> valor;
                Retirada::realizarRetirada(carteira, valor);
                historico.adicionarTransacao(Transacao(valor, "Retirada"));
            }
            else if (opcaoUsuario == 3)
            {
                Saldo::exibirSaldo(carteira);
            }
            else if (opcaoUsuario == 4)
            {
                historico.exibirHistorico();
            }
            else if (opcaoUsuario == 5)
            {
                comprar.menu();
            }
            else if (opcaoUsuario == 6)
            {
                logout();
                Logger::log("Saindo...");
            }
            else
            {
                Logger::log("Opcao invalida. Tente novamente.");
            }
        } while (opcaoUsuario != 6);
    }
}
