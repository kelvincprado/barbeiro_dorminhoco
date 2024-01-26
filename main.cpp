#include "Barbearia.h"
#include "cliente.h"
#include <map>


int main(){
    Barbearia *b1 = new Barbearia(5);
    map<Cliente*, thread> clientes;

    thread t1(&Barbearia::run, b1);

    for (int i=0; i<10; i++){
        Cliente *c = new Cliente(b1);

        clientes[c] = thread(&Cliente::run, c);
    }
    t1.join();



/*    b1->gerarClientes();
    b1->barbeiroDorme();
    b1->barbeiroAtendendoClientes();
    cout << "Qtd cadeira de espera " << b1->qtdCadeiraDeEspera;
    cout << "Tamanho do vetor " << b1->clientes.size();
*/
    return 0;
}
