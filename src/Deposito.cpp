#include "Deposito.hpp"

void Deposito::realizarDeposito(Carteira& carteira, double valor) {
    carteira.adicionarSaldo(valor);
}
