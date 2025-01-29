#ifndef HISTORICO_HPP
#define HISTORICO_HPP

#include "Transacao.hpp"  
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Historico {
private:
    std::vector<Transacao> transacoes;

public:
    void adicionarTransacao(const Transacao& transacao);
    void exibirHistorico() const;
    void salvarLog(const std::string& nomeUsuario) const;
    std::vector<Transacao> getTransacoes() const;
    static void salvarLogAdministrador(const std::string& logGeral);
};

#endif // HISTORICO_HPP
