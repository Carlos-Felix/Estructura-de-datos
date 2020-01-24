#pragma once

template <typename T>
struct nodo{
    T dato;
    nodo<T>* sig;
};