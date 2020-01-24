#include "arbolBinario.h"

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
        if(q == NULL) return buscar(x,p->hi);
        else return q;
    }
}

template <typename T>
void arbolBinario<T>::insert(T x,T padre){
    
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
            p->dato = x;
            p->hd = NULL;
            p->hi = NULL;
            if(q->hi == NULL) q->hi = p;
            else{
                if(q->hd == NULL) q->hd = p;
                else{
                    return;
                }
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

