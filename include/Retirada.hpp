#ifndef RETIRADA_HPP
#define RETIRADA_HPP

#include "Carteira.hpp"
using namespace std;

class Retirada
{
public:
    static bool realizarRetirada(Carteira &carteira, double valor);
};

#endif // RETIRADA_HPP
