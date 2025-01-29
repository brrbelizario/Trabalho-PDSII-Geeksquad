#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Transacao {
private:
    double valor;
    std::string tipo;

public:
    Transacao(double valor, const std::string& tipo);

    void exibirDetalhes() const;
    std::string formatarParaLog() const;
};
