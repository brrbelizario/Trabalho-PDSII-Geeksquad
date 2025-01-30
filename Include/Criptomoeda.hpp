#ifndef CRIPTOMOEDA_HPP
#define CRIPTOMOEDA_HPP

#include <string>
using namespace std;

class Criptomoeda {
private:
    string nome;
    double cotacao;

public:
    Criptomoeda(string nome, double cotacao);

    string getNome() const;
    double getCotacao() const;
};

#endif // CRIPTOMOEDA_HPP
