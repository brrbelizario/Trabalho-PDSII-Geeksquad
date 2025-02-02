#ifndef TRANSACAO_HPP
#define TRANSACAO_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
#pragma once

class Transacao
{
private:
    double valor;
    string tipo;

public:
    Transacao(double valor, const string &tipo);

    void exibirDetalhes() const;
    string formatarParaLog() const;
};

#endif // TRANSACAO_HPP
