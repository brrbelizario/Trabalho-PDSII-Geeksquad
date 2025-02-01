#include "../include/Validador.hpp"

bool Validador::validarIdade(int idade)
{
    return idade >= 18;
}

bool Validador::validarNomeResponsavel(const string &nome, const string &sobrenome, const unordered_map<string, Usuario> &usuarios)
{
    string chave = nome + "_" + sobrenome;
    return usuarios.find(chave) != usuarios.end();
}
