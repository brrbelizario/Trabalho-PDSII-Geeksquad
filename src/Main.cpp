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

#include "../include/Usuario.hpp"
#include "../include/Carteira.hpp"
#include "../include/Transacao.hpp"
#include "../include/Criptomoeda.hpp"
#include "../include/Historico.hpp"
#include "../include/Logger.hpp"
#include "../include/Cadastro.hpp"
#include "../include/Login.hpp"
#include "../include/Transferencia.hpp"
#include "../include/Saldo.hpp"
#include "../include/Deposito.hpp"
#include "../include/Retirada.hpp"
#include "../include/Notificacao.hpp"
#include "../include/Validador.hpp"
#include "../include/Relatorio.hpp"
#include "../include/Sistema.hpp"

using namespace std;

int main() {
    Sistema sistema;

    sistema.carregarUsuarios();

    sistema.exibirMenuInicial();

    sistema.salvarUsuarios();

    return 0;
}
