#include "Transacao.hpp"

Transacao::Transacao(double valor, const std::string& tipo) : valor(valor), tipo(tipo) {}

void Transacao::exibirDetalhes() const {
    std::cout << "Transacao: " << tipo << ", Valor: " << std::fixed << std::setprecision(2) << valor << std::endl;
}

std::string Transacao::formatarParaLog() const {
    std::stringstream ss;
    ss << "Transacao: " << tipo << ", Valor: " << std::fixed << std::setprecision(2) << valor;
    return ss.str();
}
