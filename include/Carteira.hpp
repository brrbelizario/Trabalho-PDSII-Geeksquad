#ifndef CARTEIRA_HPP
#define CARTEIRA_HPP

#include <iostream>
using namespace std;

#pragma once
class Carteira
{
private:
    double saldo;
    double doge;
    double btc;

public:
    Carteira();

    double getSaldo() const;
    void adicionarSaldo(double valor);
    bool retirarSaldo(double valor);

    double getSaldoD() const;
    void adicionarSaldoD(double valor);

    double getSaldoB() const;
    void adicionarSaldoB(double valor);
};

#endif // CARTEIRA_HPP
