#include "Historico.hpp"

void Historico::adicionarTransacao(const Transacao& transacao) {
    transacoes.push_back(transacao);
}

void Historico::exibirHistorico() const {
    cout << "Historico de Transacoes:" << endl;
    for (const auto& transacao : transacoes) {
        transacao.exibirDetalhes();
    }
}

void Historico::salvarLog(const string& nomeUsuario) const {
    ofstream arquivoLog(nomeUsuario + "_log.txt", ios::app);
    if (arquivoLog.is_open()) {
        for (const auto& transacao : transacoes) {
            arquivoLog << transacao.formatarParaLog() << endl;
        }
        arquivoLog.close();
    }
}

vector<Transacao> Historico::getTransacoes() const {
    return transacoes;
}

void Historico::salvarLogAdministrador(const string& logGeral) {
    ofstream arquivoLog("log.txt", ios::app);
    if (arquivoLog.is_open()) {
        arquivoLog << logGeral << endl;
        arquivoLog.close();
    }
}
