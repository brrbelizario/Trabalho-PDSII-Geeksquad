#include "../include/Relatorio.hpp"

void Relatorio::gerarRelatorio(const Historico &historico)
{
    cout << "Gerando relatorio..." << endl;
    historico.exibirHistorico();
}
