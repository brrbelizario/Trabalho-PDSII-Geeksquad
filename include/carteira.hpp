#ifndef CARTEIRA_HPP
#define CARTEIRA_HPP

#include <iostream>
using namespace std;

class Carteira {
private:
    double saldo;

public:
    Carteira();

    double getSaldo() const;
    void adicionarSaldo(double valor);
    bool retirarSaldo(double valor);
};

#endif // CARTEIRA_HPP

