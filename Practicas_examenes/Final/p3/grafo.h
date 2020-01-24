//grafo.h
#pragma once

#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100

using namespace std;

struct arista
{
    int dato;
    int peso;
    arista* sig;

};

struct vertice{
    int dato = -1;
    arista* fr = NULL;
};

class Grafo{
private:
    vertice vt[MAX];
public:
    Grafo();
    ~Grafo();
    void insertarVertice(int x);
    void insertarArista(int x,int y,int peso);
    bool buscarVertice(int);
    arista* buscarArista(vertice*,int);
    void imprimirGrafo();
    void eliminarVertice(int);
    //void eliminarVertice(vertice*);
    void eliminarTodoVertice();
    void eliminarArista(vertice*,int);
    void eliminarArista(int, int);
    void eliminarTodaArista(vertice*);
    void eliminarTodaArista(int);
    int menorCamino(int,int);
    int longestPath(int, int);
    void ll(vector<int> &, int memo[MAX][3]);
    int maxTo(int ,int ,int memo[MAX]);
    int existeCaminoDist(int s,int t, int d);

};
#endif