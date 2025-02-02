#ifndef COMPRAR_CRIPTO_HPP
#define COMPRAR_CRIPTO_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Historico.hpp"
#include "Logger.hpp"
#include "Carteira.hpp"
#pragma once

class ComprarCripto
{
private:
    const double valorBitcoin = 620897.68; // 1 Bitcoin em reais
    const double valorDogeCoin = 200.00;   // 1 Dogecoin em reais
    double saldoTotal;                     // Saldo total disponível
    double saldoBitcoin;                   // Saldo em Bitcoin
    double saldoDogcoin;                   // Saldo em Dogcoin
    Historico historico;                   // Histórico de transações
    Carteira &carteira;                    // Non-const reference

public:
    ComprarCripto(double atualB, double atualD, Carteira &carteira) : carteira(carteira) {}

    void menu();
    void calcularPorcentagem(int opcao, double valorCompra);
};

#endif // COMPRARCRIPTO_HPP