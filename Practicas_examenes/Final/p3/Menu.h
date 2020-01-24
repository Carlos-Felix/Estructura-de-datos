#pragma once
#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>
#include "grafo.h"

using std::cout;
using std::cin;
using std::endl;

class Menu{
private:
    int op,bf,bf2,bf3;
    Grafo* g;
public:
    Menu();
    void presentarMenu();
    int mostrarMenu();

    ~Menu();
};

#endif

