#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include "Carteira.hpp" // Incluindo a carteira

using namespace std;

class Usuario
{
private:
    string nome;
    string sobrenome;
    string senha;
    int idade;
    bool administrador;
    Usuario *responsavel;
    Carteira carteira; // Adicionando a carteira ao usuário

public:
    Usuario(string nome, string sobrenome, string senha, int idade, bool administrador = false);

    string getNomeCompleto() const;
    string getSenha() const;
    int getIdade() const;
    bool isAdministrador() const;
    bool verificarSenha(const string &senhaEntrada) const;

    void setResponsavel(Usuario *responsavelUsuario);
    Usuario *getResponsavel() const;

    // Métodos para acessar a carteira
    Carteira &getCarteira();
    void setCarteira(const Carteira &novaCarteira);

    void setAdministrador(bool valor);
};

#endif // USUARIO_HPP
