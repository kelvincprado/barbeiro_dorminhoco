#ifndef CLIENTE_H
#define CLIENTE_H

#include <random>
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;
class Barbearia;
class Cliente{
    public:
        Cliente(Barbearia *b);
        virtual ~Cliente();
        mutex &getMutex();
        void run();
    private:
        Barbearia *b;
        int gerarTempo();
        mutex m;
};

#endif // CLIENTE_H
