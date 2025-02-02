#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include "Usuario.hpp"
using namespace std;
#pragma once

class Cadastro
{
public:
    static Usuario criarConta(const string &nome, const string &sobrenome, const string &senha, int idade, bool administrador = false);
};

#endif // CADASTRO_HPP
