#include "../include/Saldo.hpp"

void Saldo::exibirSaldo(const Carteira &carteira)
{
    cout << "Saldo atual: " << fixed << setprecision(2) << carteira.getSaldo() << endl;
    cout << "Doge atual: " << fixed << setprecision(8) << carteira.getSaldoD() << endl;
    cout << "Bitcoin atual: " << fixed << setprecision(8) << carteira.getSaldoB() << endl;
}
