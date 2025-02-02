#ifndef RELATORIO_HPP
#define RELATORIO_HPP

#include "Historico.hpp"
#include <iostream>
using namespace std;
#pragma once

class Relatorio
{
public:
    static void gerarRelatorio(const Historico &historico);
};

#endif // RELATORIO_HPP
