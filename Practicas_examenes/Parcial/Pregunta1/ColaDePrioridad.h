#pragma once

#include <iostream>
#include "nodo.h"

//int Mayor(nodo<int>*);

class ColaPrioridad{
    nodo<int>* frente;
    nodo<int>* cola;
    int n;
public:
    ColaPrioridad();
    void Insertar(int,int);
    void Imprimir();
    nodo<int>* tfrente();
    void Desencolar();
    nodo<int>* DesencolaPrioridad(int prioridad);
    int getNumElem();
    void EliminarPos(int);
    bool Vacio();

};

ColaPrioridad::ColaPrioridad(){
    frente = NULL;
    cola = NULL;
    n = 0;
}

bool ColaPrioridad::Vacio(){
    return (frente == NULL) ? true:false;
}

void ColaPrioridad::Insertar(int id,int Prioridad){
    nodo<int>* p = new nodo<int>;
    p->Id = id;
    p->Prioridad = Prioridad;
    p->sig = NULL;
    if(Vacio()){
        frente = p;
        cola = p;
        n++;
    }else{
        nodo<int>* q;
        nodo<int>* qAnt;
        q = frente;
        qAnt = NULL;
        while(q->Prioridad >= p->Prioridad){
            qAnt = q;
            q = q->sig;
            if(q == NULL) break;
        }
        if(qAnt == NULL){
            p->sig = frente;
            frente = p;
        }else{
            if(q == NULL){
            qAnt->sig = p;
            p->sig = NULL;
            cola = p;
            }else{
                qAnt->sig = p;
                p->sig = q;
            }
        }
        
        n++;
    }
}

int ColaPrioridad::getNumElem(){
    return n;
}

void ColaPrioridad::Imprimir(){
    nodo<int>* p = frente;
    while(p != NULL){
        std::cout<<p->Id<<"("<<p->Prioridad<<")"<<" ";
        p = p->sig;
    }
    std::cout << std::endl;
}

nodo<int>* ColaPrioridad::tfrente(){
    return frente;
}

void ColaPrioridad::Desencolar(){
    if(Vacio()) return;
    nodo<int>* e;
    e = frente;
    frente = frente->sig;
    delete e;
}

nodo<int>* ColaPrioridad::DesencolaPrioridad(int pr){
    if(Vacio()) return NULL;
    nodo<int>* p = frente;
    nodo<int>* pAnt;
    pAnt = NULL;
    while(p->Prioridad != pr){
        p = p->sig;
        if(p == NULL) break;
    }
    if(p == NULL) return p;
    if(pAnt == NULL){
        if(p->sig == NULL){
            frente = NULL;
            cola = NULL;
        }else{
            frente = p->sig;
        }
    }else{
        if(p->sig == NULL){
            pAnt->sig = NULL;
            cola = pAnt;
        }else{
            pAnt->sig = p->sig;
        }
    }
    return p;
}

void ColaPrioridad::EliminarPos(int pos){
    nodo<int>* pant = NULL,*p = frente;
    if(pos >= 1 && pos <= n && !Vacio()){
        for(int i = 2; i <= pos; i++){
            pant = p;
            p = p->sig;
        }

        if(pant == NULL){
            if(p->sig == NULL){
                frente = NULL;
                cola = NULL;
                delete p;
            }else{
                frente = p->sig;
                delete p;
            }
        }else{
            if(p->sig == NULL){
                pant->sig = NULL;
                cola = pant;
                delete p;
            }else{
                pant->sig = p->sig;
                delete p;
            }
        }
    }

}

int Mayor(nodo<int>* frente){
    nodo<int>* p = frente;
    int pos = 0,mayor,posPr;
    if(frente != NULL){
        pos = 1;
        mayor = p->Prioridad;
        while(p != NULL){
            if(p->Prioridad > mayor){
                mayor = p->Prioridad;
                posPr = pos;
            }
            pos++;
            p = p->sig;
        }
    }
    return posPr;
}

