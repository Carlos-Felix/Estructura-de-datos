#pragma once

#ifndef __LEFTIST_H__
#define __LEFTIST_H__

#define nulo -2147483000

#include <cstddef>
#include <iostream>
#include <algorithm>

using namespace std;

struct nodo
{
    int dato;
    int rank;
    nodo* left;
    nodo* right;
};



class leftistHeap
{
private:
    nodo* raiz;
public:
    leftistHeap();
    ~leftistHeap();
    void deleteHeap(nodo*);
    nodo* getRaiz();
    void setRaiz(nodo*);
    int getMin();
    void deleteMin();
    void insert(int x);
    void print(nodo*,int);
    nodo* merge(nodo*);
    nodo* merge(nodo*,nodo*);
};
#endif