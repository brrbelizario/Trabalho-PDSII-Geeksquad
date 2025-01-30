#include "Saldo.hpp"

void Saldo::exibirSaldo(const Carteira& carteira) {
    cout << "Saldo atual: " << fixed << setprecision(2) << carteira.getSaldo() << endl;
}
