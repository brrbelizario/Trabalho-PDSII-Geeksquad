#include "../include/Retirada.hpp"

bool Retirada::realizarRetirada(Carteira &carteira, double valor)
{
    return carteira.retirarSaldo(valor);
}
