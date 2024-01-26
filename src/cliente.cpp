#include "cliente.h"
#include "Barbearia.h"
Cliente::Cliente(Barbearia *b){
    this->b = b;
}

Cliente::~Cliente(){

}

int Cliente::gerarTempo(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(2, 5);
    return dist(gen);
}

void Cliente::run(){
    while(true){
        if (b->entrarNaFila(this)){
            if(b->getDormindo()){
                b->acordar();
            }
            //m.lock();
            //m.unlock();
            break;
        }else{
            this_thread::sleep_for (std::chrono::seconds(gerarTempo()));
        }
    }
}

mutex &Cliente::getMutex(){
    return m;
}
