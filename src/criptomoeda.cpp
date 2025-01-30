#include "Criptomoeda.hpp"

Criptomoeda::Criptomoeda(string nome, double cotacao) : nome(nome), cotacao(cotacao) {}

string Criptomoeda::getNome() const {
    return nome;
}

double Criptomoeda::getCotacao() const {
    return cotacao;
}
