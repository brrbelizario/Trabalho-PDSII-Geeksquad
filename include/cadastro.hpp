#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include "Usuario.hpp"
#include <string>
using namespace std;

class Cadastro {
public:
    static Usuario* criarConta(const string& nome, const string& sobrenome, const string& senha, int idade, bool administrador = false);
};

#endif
