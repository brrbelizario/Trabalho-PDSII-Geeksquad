#ifndef DEPOSITO_HPP
#define DEPOSITO_HPP

#include "Carteira.hpp"  
class Deposito {
public:
    static void realizarDeposito(Carteira& carteira, double valor);
};

#endif // DEPOSITO_HPP
