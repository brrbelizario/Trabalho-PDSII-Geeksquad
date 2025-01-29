#ifndef COMPRAR_CRIPTO_MOEDA_HPP
#define COMPRAR_CRIPTO_MOEDA_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Historico.hpp" 
#include "Logger.hpp"    

class ComprarCriptoMoeda {
private:
    const double valorBitcoin = 620897.68; // 1 Bitcoin em reais
    const double valorDogCoin = 200.00;   // 1 Dogecoin em reais
    double saldoTotal;                     // Saldo total disponível
    double saldoBitcoin;                   // Saldo em Bitcoin
    double saldoDogcoin;                   // Saldo em Dogcoin
    Historico historico;                   // Histórico de transações

public:
    ComprarCriptoMoeda(double saldoTotal, double saldoBitcoin = 0, double saldoDogcoin = 0);

    void menu();
    
private:
    void calcularPorcentagem(int opcao, double valorCompra);
};

#endif // COMPRAR_CRIPTO_MOEDA_HPP
