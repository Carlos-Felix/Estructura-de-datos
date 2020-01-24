#include <iostream>
#include "nodo.h"

using namespace std;

class Lista{
    int NElem;
    nodo<int>* pL;

public:
    Lista();
    void Ingresar(int,int);
    void Imprimir();
    nodo<int>* getPrimer();
    nodo<int>* getElemPrioridad(int n);
    int getNumDeElementos();
    void EliminarElementoId(int Id);
    void eliminarElemento(nodo<int>*);
    void EliminarPosicion();
    ~Lista();
};

Lista::Lista(){
    NElem = 0;
    pL = NULL;

}

Lista::~Lista(){
    nodo<int>* p,*q;
    p = pL;
    while(p != NULL){
        q = p;
        p = p->sig;
        delete q;
    }

}
void Lista::Ingresar(int n,int prioridad){
    nodo<int>* p;
    p = new nodo<int>;
    p->Id = n;
    p->Prioridad = prioridad;
    p->sig = pL;
    pL = p;
    NElem++;
}

void Lista::Imprimir(){
    nodo<int>* p;
    p = pL;
    if(p == NULL) return;
    while(p != NULL){
        cout<<p->Id<<"->";
        p = p->sig;
    }
    cout<<endl;

}

void Lista::EliminarElementoId(int n){
    int flag = 0;
    nodo<int>* p,*elim,*pAnt;
    if(pL == NULL) return;
    pAnt = NULL;
    p = pL;
    while(p->Id != n){
        p = p->sig;
        if(p == NULL) break;
    }
}

nodo<int>* Lista::getElemPrioridad(int Pr){
    nodo<int>* p;
    p = pL;
    while(p != NULL){
        if(p->Prioridad == Pr) break;
        p = p->sig;
    }
    return p;
}
int Lista::getNumDeElementos(){
    return NElem;
}

nodo<int>* Lista::getPrimer(){
    return pL;
}