#include "./include/Login.hpp"

bool Login::validarCredenciais(const Usuario& usuario, const string& senha) {
    return usuario.verificarSenha(senha);
}
