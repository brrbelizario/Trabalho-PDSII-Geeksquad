#include "Validador.hpp"
#include "Usuario.hpp" // 

bool Validador::validarIdade(int idade) {
    return idade >= 18;
}

bool Validador::validarNomeResponsavel(const std::string& nome, const std::string& sobrenome, const std::unordered_map<std::string, Usuario>& usuarios) {
    std::string chave = nome + "_" + sobrenome;
    return usuarios.find(chave) != usuarios.end();
}
