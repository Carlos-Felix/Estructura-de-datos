#pragma once

struct nodoArbol{
    int dato;
    nodoArbol* hijoizq;
    nodoArbol* hijoder;
};

class arbol{
    nodoArbol* raiz;
public:
    arbol();
    bool vacio();
    void insertarNodo(int);
    void imprimir(nodoArbol*);
    void imprimirOrden(nodoArbol*);
    void imprimirPreorden(nodoArbol*);
    void imprimirPostorden(nodoArbol*);
    void anchuraPrimero(nodoArbol*);
    int altura(nodoArbol*);
    nodoArbol* encontrarElemento(int);
    nodoArbol* encontrarPadre(int);
    nodoArbol* encontrarMayor(nodoArbol*);
    nodoArbol* encontrarMenor(nodoArbol*);
    int padreMasJoven(int,int);
    int profunNodo(int x);
    void eliminarArbol(nodoArbol* r);
    void eliminarElemento(int);
    nodoArbol* getRaiz();
    ~arbol();
};