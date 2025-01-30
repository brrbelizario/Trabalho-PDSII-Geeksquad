#pragma once
#include "Carteira.hpp" 

class Retirada {
public:
    static bool realizarRetirada(Carteira& carteira, double valor);
};
