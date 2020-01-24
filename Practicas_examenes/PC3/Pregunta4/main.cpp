#include <iostream>
#include "Cola.h"

using namespace std;

Cola<int> estacionamiento;

void LLegaCarro(Cola<int> &);
void SaleCarro(Cola<int> &);


void Menu(){
    int op = -1;
    while (op != 0)
    {
        cout << endl;
        cout << "        MENU" << endl;
        cout << endl;
        estacionamiento.Imprimir();
        cout << endl;
        cout << "1) Llega carro" << endl;
        cout << "2) Sale carro" << endl;
        cout << "0) Salir" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            LLegaCarro(estacionamiento);
            break;
        case 2:
            SaleCarro(estacionamiento);
            break;
        
        default:
            break;
        }
    }
    
    
}

void LLegaCarro(Cola<int> &c){
    if(c.getNumElem() == 10){
        cout << "El estacionamiento está lleno" << endl;
        return;
    }else{
        int bf1;
        cout << "Ingrese el ID del carro: ";
        cin >> bf1;
        c.Encolar(bf1);
    }

}

void SaleCarro(Cola<int> &c){
    if(c.Vacio()) return;
    int bf1,cont = 0;
    cout << "Ingrese el ID del carro: ";
    cin >> bf1;

    Cola<int> aux;
    while(c.tfrente() != bf1){
        aux.Encolar(c.tfrente());
        c.Desencolar();
        cont++;
        if(c.Vacio()) break;
    }
    if(c.Vacio()){
        cout << "El carro no se encuentra en el estacionamiento" << endl;
    }else{
        c.Desencolar();
        cout << "Se ha movido el carro " << cont+1 << " veces" << endl;

    } 

    while(!c.Vacio()){
        aux.Encolar(c.tfrente());
        c.Desencolar();
    }

    while(!aux.Vacio()){
        c.Encolar(aux.tfrente());
        aux.Desencolar();
    }

    
}

int main(){
    Menu();
    return 0;
}