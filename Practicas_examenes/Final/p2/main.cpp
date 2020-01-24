#include <iostream>
#include "GRAFOS.h"
#include "arbol_busqueda.h"

using namespace std;

int main(){
    Grafo g;
    g.insertarVertice(8);
    g.insertarVertice(5);
    g.insertarVertice(3);
    g.insertarVertice(6);
    g.insertarVertice(1);
    g.insertarArista(5,3);
    g.imprimirGrafo();

    g.Ordenar();

    return 0;
}