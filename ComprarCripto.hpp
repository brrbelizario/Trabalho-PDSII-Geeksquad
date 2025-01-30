/*#ifndef COMPRARCRIPTO_HPP
#define COMPRARCRIPTO_HPP

#include <iostream>
#include <iomanip>
#include "Carteira.cpp"

class ComprarCriptoMoeda {
private:
    const double valorBitcoin = 620897.68; // 1 Bitcoin em reais
    const double valorDogCoin = 200.00;    // 1 Dogecoin em reais
    double saldo;  // Saldo do usuário
    Carteira* carteira;

public:
    ComprarCriptoMoeda(double saldoInicial) : saldo(saldoInicial) {}

    void menu();
    void calcularPorcentagem(int opcao, double valorCompra);
};

#endif // COMPRARCRIPTO_HPP */
