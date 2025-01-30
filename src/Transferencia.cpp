#include "Transferencia.hpp"

bool Transferencia::realizarTransferencia(Carteira& deCarteira, Carteira& paraCarteira, double valor) {
    if (deCarteira.retirarSaldo(valor)) {
        paraCarteira.adicionarSaldo(valor);
        return true;
    }
    return false;
}
