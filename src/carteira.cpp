#include "..src/Carteira.hpp"

Carteira::Carteira() : saldo(0.0) {}

double Carteira::getSaldo() const {
    return saldo;
}

void Carteira::adicionarSaldo(double valor) {
    if (valor < 0) {
        std::cout << "Valor invalido" << std::endl;
    } else {
        saldo += valor;
    }
}

bool Carteira::retirarSaldo(double valor) {
    if (valor > saldo) {
        return false;
    }
    if (valor < 0) {
        std::cout << "Valor invalido" << std::endl;
        return false;
    } else {
        saldo -= valor;
        return true;
    }
}
