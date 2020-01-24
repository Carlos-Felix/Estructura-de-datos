#include "arbol_busqueda.h"

using namespace std;

int numHojas(nodoArbol* r){
    int n = 0;
    if(r == NULL) return 0;
    else{
        if(r->hijoizq != NULL || r->hijoder != NULL){
            n = numHojas(r->hijoder) +  numHojas(r->hijoizq);
        }else{
             n++;
        }
    }
    return n;
}


int main(){
    arbol a;

    a.insertarNodo(3);
    a.insertarNodo(5);
    a.insertarNodo(7);
    a.insertarNodo(1);
    a.insertarNodo(9);
    a.insertarNodo(0);
    a.insertarNodo(2);

    a.imprimirArbol(a.getRaiz(),0);

    cout << "Num de hojas: " << numHojas(a.getRaiz()) << endl;

    return 0;
}