#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
#include <algorithm>
using namespace std;
// Classe Criptomoeda
class Criptomoeda {
private:
    string nome;
    double cotacao;

public:
    Criptomoeda(string nome, double cotacao) : nome(nome), cotacao(cotacao) {}

    string getNome() const { return nome; }
    double getCotacao() const { return cotacao; }
};
