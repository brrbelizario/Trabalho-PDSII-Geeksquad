#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <iostream>
using namespace std;
#pragma once

class Logger
{
public:
    static void log(const string &mensagem);
};

#endif // LOGGER_HPP
