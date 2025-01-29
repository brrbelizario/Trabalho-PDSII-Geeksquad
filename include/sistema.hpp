#pragma once

#include <unordered_map>
#include <string>
#include "Usuario.hpp"
#include "Carteira.hpp"
#include "Historico.hpp"
#include "Logger.hpp"
#include "Cadastro.hpp"
#include "Login.hpp"
#include "Transferencia.hpp"
#include "Saldo.hpp"
#include "Deposito.hpp"
#include "Retirada.hpp"
#include "Notificacao.hpp"
#include "Validador.hpp"
#include "Relatorio.hpp"

class Sistema {
private:
    std::unordered_map<std::string, Usuario> usuarios;
    Usuario* usuarioAtual = nullptr;
    std::string senhaAdmin = "00000";

    std::string gerarChaveUsuario(const std::string& nome, const std::string& sobrenome);

public:
    void carregarUsuarios();
    void salvarUsuarios();
    void adicionarUsuario(const std::string& nome, const std::string& sobrenome, const std::string& senha, int idade, bool administrador = false);
    bool logarUsuario(const std::string& nome, const std::string& sobrenome, const std::string& senha);
    void logout();
    Usuario* getUsuarioAtual();
    Usuario* buscarUsuario(const std::string& nome, const std::string& sobrenome);
    void acessarLogAdministrador();
    void alterarSenhaAdmin();
    std::string getSenhaAdmin() const;
    void exibirMenuInicial();
    void registrarConta();
    void fazerLogin();
};
