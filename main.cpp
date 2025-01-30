#include <iostream>      
#include <fstream>       
#include <string>       
#include <vector>        
#include <unordered_map> 
#include <iomanip>       
#include <sstream>       
#include <cctype> 
#include <ctime>
#include <algorithm>      

#include "Usuario.cpp"
#include "Carteira.cpp"
#include "Transacao.cpp"
#include "Criptomoeda.cpp"
#include "Historico.cpp"
#include "Logger.cpp"
#include "Cadastro.cpp"
#include "Login.cpp"
#include "Transferencia.cpp"
#include "Saldo.cpp"
#include "Deposito.cpp"
#include "Retirada.cpp"
#include "Notificacao.cpp"
#include "Validador.cpp"
#include "Relatorio.cpp"
#include "Sistema.cpp"
*#include "ComprarCripto.cpp*

using namespace std;

int main() {
    Sistema sistema;

    sistema.carregarUsuarios();

    sistema.exibirMenuInicial();

    sistema.salvarUsuarios();

    return 0;
}
