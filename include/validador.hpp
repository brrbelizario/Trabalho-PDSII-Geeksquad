#pragma once
#include <string>
#include <unordered_map>

class Usuario; 

class Validador {
public:
    static bool validarIdade(int idade);
    static bool validarNomeResponsavel(const std::string& nome, const std::string& sobrenome, const std::unordered_map<std::string, Usuario>& usuarios);
};
