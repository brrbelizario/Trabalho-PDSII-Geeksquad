#ifndef VALIDADOR_HPP
#define VALIDADOR_HPP

#include <string>
#include <unordered_map>
#include "Usuario.hpp"
using namespace std;

class Validador
{
public:
    static bool validarIdade(int idade);
    static bool validarNomeResponsavel(const string &nome, const string &sobrenome, const unordered_map<string, Usuario> &usuarios);
};

#endif // VALIDADOR_HPP
