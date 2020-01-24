#pragma once

#include "nodo.h"

using namespace std;

template <typename T>
class Pila{
    nodo<T>* cima;
    int n;

public:
    Pila();
    void apilar(T);
    void desapilar();
    T tcima();
    void Imprimir();
    bool vacia();
    int numElem();
    T Calculadora();
    ~Pila();

};

template <typename T>
Pila<T>::Pila(){
        cima = NULL;
        n = 0;
}

template <typename T>
bool Pila<T>::vacia(){
    if(cima == NULL) return true;
    else return false;

}

template <typename T>
void Pila<T>::apilar(T x){
    nodo<T>* p;
    p = new nodo<T>;
    p->dato = x;

    if(vacia()){
        p->sig = NULL;
        cima = p;
        n++;
    }else{
        p->sig = cima;
        cima = p;
        n++;
    }

}

template <typename T>
void Pila<T>::desapilar(){
    nodo<T>* elim;
    if(!vacia()){
        elim = cima;
        cima = cima->sig;
        delete elim;
        --n;
    }

}

template <typename T>
T Pila<T>::tcima(){

    T c;
    if(!vacia()){
        c = cima->dato;
        return c;
    }
}

template <typename T>
Pila<T>::~Pila(){
    nodo<T>* p,*q;
    p = new nodo<T>;
    p = cima;
    while(p != NULL){
        q = p->sig;
        delete p;
        p = q;
    }
}

template <typename T>
void Pila<T>::Imprimir(){
    nodo<T>* p;
    p = new nodo<T>;
    p = cima;
    while(p != NULL){
        cout<<p->dato<<" ";
        p = p->sig;

    }
    cout<<endl;
}

template <typename T>
int Pila<T>::numElem(){
    return n;
}
