#include "Historico.hpp"

void Historico::adicionarTransacao(const Transacao& transacao) {
    transacoes.push_back(transacao);
}

void Historico::exibirHistorico() const {
    std::cout << "Historico de Transacoes:" << std::endl;
    for (const auto& transacao : transacoes) {
        transacao.exibirDetalhes();
    }
}

void Historico::salvarLog(const std::string& nomeUsuario) const {
    std::ofstream arquivoLog(nomeUsuario + "_log.txt", std::ios::app);
    if (arquivoLog.is_open()) {
        for (const auto& transacao : transacoes) {
            arquivoLog << transacao.formatarParaLog() << std::endl;
        }
        arquivoLog.close();
    }
}

std::vector<Transacao> Historico::getTransacoes() const {
    return transacoes;
}

void Historico::salvarLogAdministrador(const std::string& logGeral) {
    std::ofstream arquivoLog("log.txt", std::ios::app);
    if (arquivoLog.is_open()) {
        arquivoLog << logGeral << std::endl;
        arquivoLog.close();
    }
}
