#include "..src/Cadastro.hpp"

// Método estático para criar uma conta e retornar um ponteiro para o usuário
Usuario* Cadastro::criarConta(const string& nome, const string& sobrenome, const string& senha, int idade, bool administrador) {
    // Cria um novo usuário dinamicamente e retorna o ponteiro
    return new Usuario(nome, sobrenome, senha, idade, administrador);
}
