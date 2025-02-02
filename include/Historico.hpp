#ifndef HISTORICO_HPP
#define HISTORICO_HPP

#include "Transacao.hpp"
#include <vector>
#include <fstream>
using namespace std;
#pragma once

class Historico
{
private:
    vector<Transacao> transacoes;

public:
    void adicionarTransacao(const Transacao &transacao);
    void exibirHistorico() const;
    void salvarLog(const string &nomeUsuario) const;
    vector<Transacao> getTransacoes() const;
    static void salvarLogAdministrador(const string &logGeral);
};

#endif // HISTORICO_HPP
