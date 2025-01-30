#include "Relatorio.hpp"
#include "Historico.hpp" // 

void Relatorio::gerarRelatorio(const Historico& historico) {
    std::cout << "Gerando relatorio..." << std::endl;
    historico.exibirHistorico();
