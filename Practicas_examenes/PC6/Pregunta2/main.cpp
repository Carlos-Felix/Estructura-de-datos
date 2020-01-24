#include "grafo.h"

int main(){

    Grafo g;
    g.insertarVertice(1);
    g.insertarVertice(2);
    g.insertarVertice(3);
    g.insertarVertice(4);
    g.insertarVertice(5);
    g.insertarVertice(6);
    

    g.insertarArista(1,2,4);
    g.insertarArista(2,3,5);
    g.insertarArista(1,3,2);
    g.insertarArista(2,4,10);
    g.insertarArista(3,5,3);
    g.insertarArista(5,4,4);
    g.insertarArista(1,2,4);
    g.insertarArista(4,6,11);

    g.imprimirGrafo();
    //CAMINO MÁS LARGO DE 1 A 4
    cout << g.longestPath(1,4) << endl;

    return 0;
}