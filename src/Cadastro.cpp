#include "../include/Cadastro.hpp"

Usuario Cadastro::criarConta(const string &nome, const string &sobrenome, const string &senha, int idade, bool administrador)
{
    return Usuario(nome, sobrenome, senha, idade, administrador);
}
