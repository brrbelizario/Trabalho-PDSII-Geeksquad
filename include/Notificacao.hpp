#ifndef NOTIFICACAO_HPP
#define NOTIFICACAO_HPP

#include <string>
#include <iostream>
using namespace std;
#pragma once

class Notificacao
{
public:
    static void enviarNotificacao(const string &mensagem);
};

#endif // NOTIFICACAO_HPP
