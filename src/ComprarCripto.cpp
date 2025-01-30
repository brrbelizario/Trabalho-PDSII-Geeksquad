/*#include "ComprarCripto.hpp"
#include <iostream>
#include <iomanip>

void ComprarCriptoMoeda::menu() {
    int opcao;
    double valorCompra;

    std::cout << "Bem-vindo ao sistema de compra de Criptomoedas!\n";
    std::cout << "Escolha uma moeda para comprar:\n";
    std::cout << "1 - Bitcoin\n";
    std::cout << "2 - Dogecoin\n";
    std::cout << "Digite sua opcao: ";
    std::cin >> opcao;

    if (opcao != 1 && opcao != 2) {
        std::cout << "Opcao invalida! Encerrando o sistema.\n";
        return;
    }

    std::cout << "Digite o valor em reais que deseja investir: R$ ";
    std::cin >> valorCompra;

    if (valorCompra <= 0) {
        std::cout << "O valor deve ser maior que zero.\n";
        return;
    } else if (valorCompra > carteira->getSaldo()) {  // Verifica saldo antes da compra
        std::cout << "Erro: Saldo insuficiente. Tente novamente.\n";
        return;
    } 

    calcularPorcentagem(opcao, valorCompra);
    carteira->retirarSaldo(valorCompra); // Subtrai o valor da compra
}

void ComprarCriptoMoeda::calcularPorcentagem(int opcao, double valorCompra) {
    double quantidadeMoeda;
    double porcentagem;

    if (opcao == 1) { // Bitcoin
        quantidadeMoeda = valorCompra / valorBitcoin;
        porcentagem = (quantidadeMoeda * 100);
        std::cout << std::fixed << std::setprecision(8);
        std::cout << "\nCom R$ " << valorCompra << ", voce comprou " << quantidadeMoeda << " Bitcoins.";
        std::cout << "\nPorcentagem em Bitcoin: " << porcentagem << " % de 1 Bitcoin.\n";
    } else if (opcao == 2) { // Dogecoin
        quantidadeMoeda = valorCompra / valorDogCoin;
        porcentagem = (quantidadeMoeda / 1) * 100;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "\nCom R$ " << valorCompra << ", voce comprou " << quantidadeMoeda << " Dogecoins.";
        std::cout << "\nPorcentagem em Dogecoin: " << porcentagem << " % de 1 Dogecoin.\n";
    }
} */