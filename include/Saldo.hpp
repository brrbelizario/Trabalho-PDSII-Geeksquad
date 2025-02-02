#ifndef SALDO_HPP
#define SALDO_HPP

#include "Carteira.hpp"
#include <iostream>
#include <iomanip>
using namespace std;
#pragma once

class Saldo
{
public:
    static void exibirSaldo(const Carteira &carteira);
};

#endif // SALDO_HPP
