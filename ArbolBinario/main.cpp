//#include <iostream>
#include "arbolBinario.h"

//using namespace std;

int main(){
    
    arbolBinario<int> ab;
    
    ab.insert(4,3,1);
    ab.insert(3,4,1);
    ab.insert(2,4,0);
    ab.insert(3,3,1);
    ab.insert(5,2,1);
    ab.insert(7,2,0);
    ab.imprimir(ab.getRaiz(),0);
    Lista l;
    l.Ingresar(4);
    //l.Ingresar(2);
    //l.Ingresar(4);
    cout << "lista: " << endl;
    l.Imprimir();
    cout << endl;
    cout << "camino:" << ab.camino(l.getPrimer(),ab.getRaiz());
    
    //return 0;
}