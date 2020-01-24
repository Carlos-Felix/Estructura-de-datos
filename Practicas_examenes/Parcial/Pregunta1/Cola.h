#pragma once

#include "nodo.h"
#include <iostream>

using namespace std;

template <typename T>
class Cola{
private:
    nodo<T>* frente;
    int n;
public:
    Cola();
    void Encolar(T dato);
    void Desencolar();
    T tfrente();
    bool Vacio();
    void Imprimir();
    ~Cola();
};

template <typename T>
Cola<T>::Cola(){
    frente = NULL;
    n = 0;
}

template <typename T>
void Cola<T>::Encolar(T x){
    nodo<T>* p,*q;
    p = new nodo<T>;
    p->dato = x;
    p->sig = NULL;
    if(Vacio()){
        frente = p;
        ++n;
    }else{
        q = frente;
        while(q->sig != NULL){
            q = q->sig;
        }
        q->sig = p;
        ++n;
    }
}

template <typename T>
void Cola<T>::Desencolar(){
    if(!Vacio()){
        nodo<T>* e;
        e = frente;
        frente = frente->sig;
        delete e;
        --n;
    }
}

template <typename T>
T Cola<T>::tfrente(){
    return frente->dato;
}

template <typename T>
bool Cola<T>::Vacio(){
    return (frente == NULL)? true:false;
}

template <typename T>
void Cola<T>::Imprimir(){
    if(!Vacio()){
        nodo<T>* p;
        p = frente;
        while(p != NULL){
            cout << p->dato << " ";
            p = p->sig;
        }
        cout << endl;
    }
}

template <typename T>
Cola<T>::~Cola(){
}
