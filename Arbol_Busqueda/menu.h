#pragma once

#include "arbol_busqueda.h"

class Menu{
    arbol* abb;
    int op = -1,aux,aux3;
    nodoArbol* aux2;
public:
    Menu();
    void prensentarMenu();
    arbol* getArbol();
};

