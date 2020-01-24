#include "ColaDePrioridad.h"
#include "Cola.h"

using namespace std;

class Banco
{
private:
    ColaPrioridad Premium;
    ColaPrioridad Clientes;
    ColaPrioridad Visitantes;
    ColaPrioridad Espera;
public:
    Banco();
    void llegaCliente();
    void llegaCliente(int, int);
    void Atender();
    void clienteSeAburre();
    void SaleDeEspera();
    void Imprimir();
    ~Banco();
};

Banco::Banco(/* args */){
    llegaCliente(3,1);
    llegaCliente(2,1);
    llegaCliente(5,1);
    llegaCliente(1,3);
    llegaCliente(4,2);
    llegaCliente(6,3);
    llegaCliente(7,1);
    llegaCliente(8,2);
    llegaCliente(9,1);
    llegaCliente(10,3);
    llegaCliente(11,3);
    llegaCliente(12,2);
    llegaCliente(13,1);
    llegaCliente(14,3);
    llegaCliente(15,2);
    llegaCliente(16,3);
    llegaCliente(17,2);
}
void Banco::llegaCliente(){
    int bf1,bf2;
    cout << "Ingrese la ID cliente y su categoría";
    cin >> bf1 >> bf2;
    if(bf2 == 3){
        if(Premium.getNumElem() < 5) Premium.Insertar(bf1,bf2);
        else Espera.Insertar(bf1,bf2);
    }else if(bf2 == 2){
        if(Clientes.getNumElem() < 5) Clientes.Insertar(bf1,bf2);
        else Espera.Insertar(bf1,bf2);
    }else if(bf2 == 1){
        if(Visitantes.getNumElem() < 5) Visitantes.Insertar(bf1,bf2);
        else Espera.Insertar(bf1,bf2);
    }
}

void Banco::llegaCliente(int bf1,int bf2){
    
    if(bf2 == 3){
        if(Premium.getNumElem() < 5) Premium.Insertar(bf1,bf2);
        else Espera.Insertar(bf1,bf2);
    }else if(bf2 == 2){
        if(Clientes.getNumElem() < 5) Clientes.Insertar(bf1,bf2);
        else Espera.Insertar(bf1,bf2);
    }else if(bf2 == 1){
        if(Visitantes.getNumElem() < 5) Visitantes.Insertar(bf1,bf2);
        else Espera.Insertar(bf1,bf2);
    }
}

void Banco::Atender(){
    Premium.Desencolar();
    Premium.Desencolar();
    Premium.Desencolar();
    Clientes.Desencolar();
    Clientes.Desencolar();
    Visitantes.Desencolar();
    if(!Espera.Vacio()){
        
    }
    
}
void Banco::Imprimir(){
    cout << "Premium: ";
    Premium.Imprimir();
    cout << "Clientes: ";
    Clientes.Imprimir();
    cout << "Visitantes: ";
    Visitantes.Imprimir();
    cout << "Espera: ";
    Espera.Imprimir(); 
}
Banco::~Banco()
{
}


void Menu(){
    
    int op = -1;
    Banco b;
    while(op){
        cout << "      MENU\n\n";
        b.Imprimir();
        cout << "1)Llega un cliente\n";
        cout << "2)Atender\n";
        cout << "0)Salir\n";
        cin >> op;
    
    switch (op)
    {
        case 1:
            b.llegaCliente();
            break;
        case 2:
            b.Atender();
            break;
        
        default:
            break;
    }
    }
}

int main(){
    Menu();
    
    return 0;
}