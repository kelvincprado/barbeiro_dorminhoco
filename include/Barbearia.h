#ifndef BARBEARIA_H
#define BARBEARIA_H

#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
using namespace std;

class Cliente;
class Barbearia{
    public:
        Barbearia(int qtdCadeiraDeEspera);
        virtual ~Barbearia();
/*
        void gerarClientes();
        void barbeiroDorme();
        void barbeiroAtendendoClientes();
*/
        bool entrarNaFila(Cliente *c);
        bool getDormindo();
        void acordar();
        void run();
    private:
        int qtdCadeiraDeEspera;
        bool cadeiraOcupada = false;
        vector<Cliente*> clientes;
        bool barbeiroDormindo = false;
        mutex mtxclientes;
        Cliente* getCliente();
        mutex cortandoCabelo;

};

#endif // BARBEARIA_H
