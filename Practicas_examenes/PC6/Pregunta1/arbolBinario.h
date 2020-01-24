#pragma once

#include <iostream>
#include "Lista.h"
#include "nodo.h"

using namespace std;

template<typename T>
class arbolBinario{

private:
    nodoBin<T>* raiz;
public:
    arbolBinario();
    nodoBin<T>* getRaiz();
    void insert(T,T,bool);
    nodoBin<T>* buscar(T,nodoBin<T>*);
    void imprimir(nodoBin<T>*,int);
    bool camino(nodo*,nodoBin<T>*);
    //~arbolBinario();
};

template <typename T>
arbolBinario<T>::arbolBinario(){
    raiz = NULL;
}

template <typename T>
nodoBin<T>* arbolBinario<T>::getRaiz(){
    return raiz;
}

template <typename T>
nodoBin<T>* arbolBinario<T>::buscar(T x,nodoBin<T>* p){
    nodoBin<T>* q;
    if(p == NULL) return NULL;
    if(p->dato == x) return p;
    else{
        q = buscar(x,p->hi);
        if(q != NULL) return q;
        else{
            q = buscar(x,p->hd);
            if(q != NULL) return q;
            else return NULL;
        }
    }
}

template <typename T>
void arbolBinario<T>::insert(T x,T padre,bool izq){
    
    if(raiz == NULL){
        nodoBin<T>* p = new nodoBin<T>;
        p->dato = x;
        p->hd = NULL;
        p->hi = NULL; 
        raiz = p;
    }else{
        nodoBin<T>* q = buscar(padre,raiz);
        if(q == NULL) return;
        else{
            nodoBin<T>* p = new nodoBin<T>;
            if(izq == 1 && q->hi == NULL){
                p->dato = x;
                p->hd = NULL;
                p->hi = NULL;

                q->hi = p;
            }
            if(izq == 0 && q->hd == NULL){
                p->dato = x;
                p->hd = NULL;
                p->hi = NULL;

                q->hd = p;
            }  
        }
        
    }
}

template <typename T>
void arbolBinario<T>::imprimir(nodoBin<T>* r,int cnt){
    if(r == NULL) return;
    else{
        imprimir(r->hd,cnt+1);
        for(int i = 0; i < cnt; i++){
            std::cout << "   ";
        }
        std::cout << r->dato << std::endl;
        imprimir(r->hi,cnt+1);
    }
}

template <typename T>
bool arbolBinario<T>::camino(nodo* p,nodoBin<T>* q){
    if(p == NULL) return true;
    else if(q == NULL) return false;
    if(p->numero != q->dato) return false;
    if(p->numero == q->dato){
        if(camino(p->siguiente,q->hi) || camino(p->siguiente,q->hd)) return true;
        else return false;
    }
}


