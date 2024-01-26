#include "Barbearia.h"
//#include "cliente.h"
//#include <functional>
#include <future>
Barbearia::Barbearia(int qtdCadeiraDeEspera){
    this->qtdCadeiraDeEspera = qtdCadeiraDeEspera;
    cout << "O barbeiro chegou em sua barbearia." << endl;
    /*thread t([this]{
             this->run();
    });*/
    //thread t(bind(&Barbearia::run, this));
    //thread t(&Barbearia::run, this);

}

Barbearia::~Barbearia(){
    //dtor
}


bool Barbearia::entrarNaFila(Cliente *c){
    cout << "Chegou novo Cliente." << endl;
    mtxclientes.lock();
    bool adicionado = false;
    int size = clientes.size();
    if(size<qtdCadeiraDeEspera){
        cout << "Existem " << qtdCadeiraDeEspera-size <<  " de " << qtdCadeiraDeEspera << " cadeiras livres para espera, Cliente aguardando sua vez" << endl;
        //c->getMutex().lock();
        clientes.push_back(c);
        adicionado = true;
    }else{
        cout << "Não existem cadeiras de espera disponíveis, Cliente foi embora." << endl;
    }
    mtxclientes.unlock();
    return adicionado;
}

Cliente *Barbearia::getCliente(){
    Cliente *c = nullptr;
    mtxclientes.lock();
    if ((int)clientes.size()){
        c = clientes[0];
        clientes.erase(clientes.begin());
    }
    mtxclientes.unlock();
    return c;
}

void Barbearia::run(){
    //cortandoCabelo.lock();
    //cout << "Barbeiro Dormindo" << endl;
    Cliente *c;
    int cont = 0;
    bool first = true;

    while(true){

        c = getCliente();
        if (!first){
            cout << "Cliente acordou o barbeiro" << endl;
            barbeiroDormindo = false;
        }else{
            first = false;
        }
        while(c){
            cont++;
            c = getCliente();
            cout << "O Barbeiro está cortando o Cabelo do Cliente " << cont << endl;
            this_thread::sleep_for (std::chrono::seconds(2));
           // c->getMutex().unlock();
        }
        cortandoCabelo.unlock();
        cortandoCabelo.lock();
        barbeiroDormindo = true;
        cout << "Barbeiro Dormindo" << endl;
        cortandoCabelo.lock();

    }
}

bool Barbearia::getDormindo(){
    return barbeiroDormindo;
}

void Barbearia::acordar(){
    cortandoCabelo.unlock();
}
/*
void Barbearia::gerarClientes(){
    srand((unsigned)time(NULL));
    //for(int i = 0; i < 10; i++){
      //  cout << 1+rand()%10 << endl;
    //}
    totalClientes = 1 + (rand()%clientesChegando);
    cout << "ddd: " << totalClientes << endl;
    for (int i=0; i<totalClientes; i++){
        clientes.push_back(i);
    }
    for (auto x:clientes){
        cout << "Vetor: " << x << endl;
    }
}

void Barbearia::barbeiroDorme(){
    if (clientes.size() == 0){
        cout << "Não há clientes para atender, o barbeiro foi dormir." << endl;
        barbeiroDormindo = true;
    //    Thread.sleep(3000);
        gerarClientes();
    }

}

void Barbearia::barbeiroAtendendoClientes(){
    if (qtdCadeiraDeEspera == clientes.size()){
        cout << "Novo(s) cliente(s) foram embora, pois as cadeiras estavam ocupadas por clientes esperando" << endl;
    }else{
        if (totalClientes > 0){
            if (cadeiraOcupada == false){
                cout << "Entrou " << totalClientes << " clientes na barbearia" << endl;
            } else {
                cout << "Existem " << totalClientes << " clientes esperando na barbearia" << endl;
            }
            cout << "Um cliente está sendo atendido" << endl;
            cadeiraOcupada = true;
            totalClientes = totalClientes - 1;
            clientes.pop_back();
//            thread.sleep(3000);
        }
    }
    if (barbeiroDormindo == true && totalClientes > 0){
        cout << "Cliente acorda barbeiro" << endl;
        barbeiroDormindo = false;
        cadeiraOcupada = false;
        Barbearia::barbeiroAtendendoClientes();
    }
}*/
