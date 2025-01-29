#ifndef LOGIN_HPP
#define LOGIN_HPP

#include "Usuario.hpp"
using namespace std;

class Login {
public:
    static bool validarCredenciais(const Usuario& usuario, const string& senha);
};

#endif // LOGIN_HPP
