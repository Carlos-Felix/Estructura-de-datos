//#include <iostream>
#include "arbolBinario.h"

//using namespace std;

bool camino(nodo* p,nodoBin<int>* q){
    if(p == NULL) return true;
    else if(q == NULL) return false;
    if(p->numero != q->dato) return false;
    if(p->numero == q->dato){
        if(camino(p->siguiente,q->hi) || camino(p->siguiente,q->hd)) return true;
        else return false;
    }
}

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
    l.insertarInicio(7);
    l.insertarInicio(2);
    l.insertarInicio(4);
    cout << "lista: " << endl;
    l.Imprimir();

    cout << endl;
    if(ab.camino(l.getPrimer(),ab.getRaiz())) cout << "Existe el camino" << endl;
    else cout << "No existe el camino" << endl;

    return 0;
}
