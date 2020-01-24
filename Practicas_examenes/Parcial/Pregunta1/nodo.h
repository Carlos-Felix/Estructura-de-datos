#pragma once

template <typename T>
struct nodo{
    T Id;
    int Prioridad;
    nodo<T>* sig;
};