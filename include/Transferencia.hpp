#ifndef TRANSFERENCIA_HPP
#define TRANSFERENCIA_HPP

#include "Carteira.hpp"
using namespace std;

class Transferencia
{
public:
    static bool realizarTransferencia(Carteira &deCarteira, Carteira &paraCarteira, double valor);
};

#endif // TRANSFERENCIA_HPP
