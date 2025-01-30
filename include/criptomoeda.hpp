#pragma once

#include <string>

class Criptomoeda {
private:
    std::string nome;
    double cotacao;

public:
    Criptomoeda(const std::string& nome, double cotacao);

    std::string getNome() const;
    double getCotacao() const;
};
