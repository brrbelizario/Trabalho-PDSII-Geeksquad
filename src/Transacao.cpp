#include "../include/Transacao.hpp"

Transacao::Transacao(double valor, const string &tipo) : valor(valor), tipo(tipo) {}

void Transacao::exibirDetalhes() const
{
    cout << "Transacao: " << tipo << ", Valor: " << fixed << setprecision(2) << valor << endl;
}

string Transacao::formatarParaLog() const
{
    stringstream ss;
    ss << "Transacao: " << tipo << ", Valor: " << fixed << setprecision(2) << valor;
    return ss.str();
}
