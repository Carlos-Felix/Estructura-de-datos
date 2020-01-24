#pragma once

#include <iostream>
#include "nodo.h"

template <typename T>
class ListaCircular{
private:
    nodo<T>* cabeza;
    nodo<T>* cola;

public:
    ListaCircular();
    void insertar(T);
    void imprimir();
    bool buscar(T);
    void eliminarElemento(T valorEliminar);
    nodo<T>* getCabeza();
    nodo<T>* getCola();
    bool vacio();
    ~ListaCircular();
};

template <typename T>
ListaCircular<T>::ListaCircular(){
    cabeza = NULL;
    cola = NULL;
}

template <typename T>
void ListaCircular<T>::insertar(T x){
    nodo<T>* p;
    p = new nodo<T>;
    p->dato = x;
    p->sig = NULL;
    if(vacio()){
        cabeza = p;
        cola = p;
        cola->sig = cabeza;
    }else{
        cola->sig = p;
        cola = cola->sig;
        cola->sig = cabeza;
    }
}

template <typename T>
void ListaCircular<T>::imprimir(){
    if(vacio()) return;
    nodo<T>* p;
    p = cabeza;
    do{
        std::cout << p->dato << "->";
        p = p->sig;
    }while(p != cabeza);
    std::cout << std::endl;
}

template <typename T>
bool ListaCircular<T>::buscar(T x){
    if(vacio()) return false;
    nodo<T>* p;
    p = cabeza;

    while(p->dato != x){
        p = p->sig;
        if(p == cabeza) return false;
    }
    return true;
}


template <typename T>
void ListaCircular<T>::eliminarElemento(T x){
    if(vacio()) return;
    nodo<T>* p,*antp;
    p = cabeza;
    antp = cola;

    while(p->dato != x){
        antp = p;
        p = p->sig;
        if(p == cabeza) return;
    }
    
    if(p == cabeza){
        if(p->sig == cabeza){
            cabeza =  NULL;
            cola = NULL;
        }else{
            cabeza = cabeza->sig;
            cola->sig = cabeza;
        }
    }else{
        if(p->sig == cabeza){
            cola = antp;
            cola->sig = cabeza;
        }else{
            antp->sig = p->sig;
        }
    }
    delete p;
}

template <typename T>
nodo<T>* ListaCircular<T>::getCabeza(){
    return cabeza;
}

template <typename T>
nodo<T>* ListaCircular<T>::getCola(){
    return cola;
}

template <typename T>
bool ListaCircular<T>::vacio(){
    return (cabeza == NULL)? true:false;
}

template <typename T>
ListaCircular<T>::~ListaCircular(){
    if(!vacio()){
        nodo<T>* p,*e;
        p = cabeza;
        do{
            e = p;
            p = p->sig;
            delete e;
        }while(p != cabeza);     
    }
}
