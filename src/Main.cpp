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

#include <iostream>
#include "Usuario.hpp"
#include "Carteira.hpp"
#include "Transacao.hpp"
#include "Criptomoeda.hpp"
#include "Historico.hpp"
#include "Logger.hpp"
#include "Cadastro.hpp"
#include "Login.hpp"
#include "Transferencia.hpp"
#include "Saldo.hpp"
#include "Deposito.hpp"
#include "Retirada.hpp"
#include "Notificacao.hpp"
#include "Validador.hpp"
#include "Relatorio.hpp"
#include "Sistema.hpp"
#include "ComprarCripto.hpp"

using namespace std;

int main()
{
    Sistema sistema;

    sistema.carregarUsuarios();

    sistema.exibirMenuInicial();

    sistema.salvarUsuarios();

    return 0;
}
