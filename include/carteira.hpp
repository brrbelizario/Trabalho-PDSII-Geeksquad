#ifndef CARTEIRA_H
#define CARTEIRA_H

#include <iostream>

class Carteira {
private:
    double saldo;

public:
    Carteira(); // Construtor
    double getSaldo() const;
    void adicionarSaldo(double valor);
    bool retirarSaldo(double valor);
};

#endif // CARTEIRA_H
