#include "../include/Usuario.hpp"

Usuario::Usuario(string nome, string sobrenome, string senha, int idade, bool administrador)
    : nome(nome), sobrenome(sobrenome), senha(senha), idade(idade), administrador(administrador), responsavel(nullptr) {}

string Usuario::getNomeCompleto() const
{
    return nome + " " + sobrenome;
}

string Usuario::getSenha() const
{
    return senha;
}

int Usuario::getIdade() const
{
    return idade;
}

bool Usuario::isAdministrador() const
{
    return administrador;
}

bool Usuario::verificarSenha(const string &senhaEntrada) const
{
    return senha == senhaEntrada;
}

void Usuario::setResponsavel(Usuario *responsavelUsuario)
{
    responsavel = responsavelUsuario;
}

Usuario *Usuario::getResponsavel() const
{
    return responsavel;
}

Carteira &Usuario::getCarteira()
{
    return carteira;
}

void Usuario::setAdministrador(bool valor)
{
    administrador = valor;
}

void Usuario::setCarteira(const Carteira &novaCarteira)
{
    carteira = novaCarteira;
}