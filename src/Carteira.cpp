#include "../include/Carteira.hpp"

Carteira::Carteira() : saldo(0.0), doge(0.0), btc(0.0) {}

double Carteira::getSaldo() const
{
    return saldo;
}

void Carteira::adicionarSaldo(double valor)
{
    if (valor < 0)
    {
        cout << "valor invalido" << endl;
    }
    else
    {
        saldo += valor;
    }
}

bool Carteira::retirarSaldo(double valor)
{
    if (valor > saldo)
        return false;
    if (valor < 0)
    {
        cout << "valor invalido" << endl;
        return false;
    }
    else
    {
        saldo -= valor;
        return true;
    }
}

double Carteira::getSaldoD() const
{
    return doge;
}

void Carteira::adicionarSaldoD(double valor)
{
    if (valor < 0)
    {
        cout << "valor invalido" << endl;
    }
    else
    {
        doge += valor;
    }
}

double Carteira::getSaldoB() const
{
    return btc;
}

void Carteira::adicionarSaldoB(double valor)
{
    if (valor < 0)
    {
        cout << "valor invalido" << endl;
    }
    else
    {
        btc += valor;
    }
}