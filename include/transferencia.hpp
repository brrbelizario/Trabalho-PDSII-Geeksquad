#pragma once
#include "Carteira.hpp" // 

class Transferencia {
public:
    static bool realizarTransferencia(Carteira& deCarteira, Carteira& paraCarteira, double valor);
};
