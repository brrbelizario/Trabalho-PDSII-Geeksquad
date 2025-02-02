#ifndef DEPOSITO_HPP
#define DEPOSITO_HPP

#include "Carteira.hpp"
using namespace std;
#pragma once

class Deposito
{
public:
    static void realizarDeposito(Carteira &carteira, double valor);
};

#endif // DEPOSITO_HPP
