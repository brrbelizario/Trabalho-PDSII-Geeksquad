#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
using namespace std;

class Usuario {
private:
    string nome;
    string sobrenome;
    string senha;
    int idade;
    bool administrador;
    Usuario* responsavel;

public:
    Usuario(string nome, string sobrenome, string senha, int idade, bool administrador = false);

    string getNomeCompleto() const;
    string getSenha() const;
    int getIdade() const;
    bool isAdministrador() const;
    bool verificarSenha(const string& senhaEntrada) const;
    void setResponsavel(Usuario* responsavelUsuario);
    Usuario* getResponsavel() const;
    void setAdministrador(bool valor);
};

#endif // USUARIO_HPP
