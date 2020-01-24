#pragma once

#ifndef __SKEW_H__
#define __SKEW_H__

#define nulo -2147483000

#include <cstddef>
#include <iostream>
#include <algorithm>

struct nodoSH
{
    int dato;
    nodoSH* left;
    nodoSH* right;
};



class skewHeap
{
private:
    nodoSH* raiz;
public:
    skewHeap();
    nodoSH* getRaiz();
    void setRaiz(nodoSH*);
    int getMin();
    void deleteMin();
    void insert(int x);
    void print(nodoSH*,int);
    nodoSH* merge(nodoSH*);
    nodoSH* merge(nodoSH*,nodoSH*);
    ~skewHeap();
    void deleteHeap(nodoSH*);
};


#endif