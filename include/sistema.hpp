#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "Usuario.hpp"
#include "Cadastro.hpp"
#include "Login.hpp"
#include "Logger.hpp"
#include "Deposito.hpp"
#include "Retirada.hpp"
#include "Saldo.hpp"
#include "Historico.hpp"
#include "Transacao.hpp"
#include <unordered_map>
#include <fstream>
#include <iostream>
using namespace std;

class Sistema {
private:
    unordered_map<string, Usuario> usuarios;
    Usuario* usuarioAtual = nullptr;
    string senhaAdmin = "00000";

    string gerarChaveUsuario(const string& nome, const string& sobrenome);

public:
    void carregarUsuarios();
    void salvarUsuarios();
    void adicionarUsuario(const string& nome, const string& sobrenome, const string& senha, int idade, bool administrador = false);
    bool logarUsuario(const string& nome, const string& sobrenome, const string& senha);
    void logout();
    Usuario* getUsuarioAtual();
    Usuario* buscarUsuario(const string& nome, const string& sobrenome);
    void acessarLogAdministrador();
    void alterarSenhaAdmin();
    string getSenhaAdmin() const;
    void exibirMenuInicial();
    void registrarConta();
    void fazerLogin();
};

#endif // SISTEMA_HPP
