#define LEFTIST

#include <iostream>
#include "leftistHeap.h"
#include "skewHeap.h"
#include "menu.h"


int main(){
#ifdef LEFTIST
    Menu m;
    m.PresentarMenu();
    /*
    leftistHeap* l = new leftistHeap;
    l->insert(7);
    //l->print(l->getRaiz(),0);
    l->insert(5);
    //l->print(l->getRaiz(),0);
    l->insert(8);
    //l->print(l->getRaiz(),0);
    l->insert(9);
    //l->print(l->getRaiz(),0);
    l->insert(15);
    //l->print(l->getRaiz(),0);
    l->insert(20);
    l->print(l->getRaiz(),0);
    //nodo* x = l->getRaiz();
    //std::cout << x << std::endl;

    leftistHeap* r = new leftistHeap;

    r->insert(2);
    r->insert(4);
    r->insert(5);
    r->insert(1);
    r->insert(7);
    r->insert(3);
    r->insert(10);
    r->print(r->getRaiz(),0);

    nodo* y = l->merge(l->getRaiz(),r->getRaiz());
    l->print(y,0);
    */
#else
    Menu m;
    m.PresentarMenu();
    /*
    skewHeap* s = new skewHeap;
    s->insert(1);
    s->insert(23);
    s->insert(4);
    s->insert(28);
    s->insert(24);
    s->insert(44);
    s->insert(63);
    s->print(s->getRaiz(),0);

    skewHeap* k = new skewHeap;
    k->insert(13);
    k->insert(99);
    k->insert(49);
    k->insert(201);
    k->insert(17);
    k->insert(105);
    k->insert(57);
    k->print(k->getRaiz(),0);

    nodoSH* x = k->merge(s->getRaiz(),k->getRaiz());
    k->print(x,0);
    */
#endif
    return 0;
}