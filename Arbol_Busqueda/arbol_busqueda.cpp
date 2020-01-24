#include <iostream>

#include <algorithm>
#include "arbol_busqueda.h"

nodoArbol* arbol::getRaiz(){
    return raiz;
}

int arbol::padreMasJoven(int x,int y){
    nodoArbol* aux,*padre1,*padre2;
    int profX = profunNodo(x),profY = profunNodo(y);
    if(profX > profY){
        while(profX > profY){
            aux = encontrarPadre(x);
            x = aux->dato;
            profX--;
        }
    }
    if(profX < profY){
        while(profX < profY){
            aux = encontrarPadre(y);
            y = aux->dato;
            profY--;
        }
    }
    if(profX == profY){
        if(x == y) return x;//SOLO SE BORRA ESTO
        padre1 =  encontrarPadre(x);
        padre2 =  encontrarPadre(y);
        if(padre1 == NULL) return raiz->dato;
        else{
            while(padre1 != padre2){
                padre1 = encontrarPadre(padre1->dato);
                padre2 = encontrarPadre(padre2->dato);
            }
        }
    }
    return padre1->dato;
    
}

int arbol::profunNodo(int x){
    nodoArbol* p = raiz;
    int prof = 0;
    while(p != NULL){
        if(x < p->dato){
            p = p->hijoizq;
            prof++;
        }
        else if(x > p->dato){ 
            p = p->hijoder;
            prof++;
        }
        else if(x == p->dato) break;
    }
    if(p == NULL) return -1;
    if(raiz != NULL) return prof;
    else return -1;
}

bool arbol::vacio(){
    return (raiz == NULL) ? true : false;
}

void arbol::imprimir(nodoArbol* r){

    if(r != NULL){
        std::cout << r->dato << " ";
        imprimir(r->hijoizq);
        imprimir(r->hijoder);
    }
    
}

void arbol::imprimirOrden(nodoArbol* r){
    if(r != NULL){
        imprimirOrden(r->hijoizq);
        std::cout << r->dato << " ";
        imprimirOrden(r->hijoder);
    }
}

void arbol::imprimirPreorden(nodoArbol* r){
    if(r != NULL){
        std::cout << r->dato << " ";
        imprimirPreorden(r->hijoizq);
        imprimirPreorden(r->hijoder);
    }
}

void arbol::imprimirPostorden(nodoArbol* r){
    if(r != NULL){
        imprimirPreorden(r->hijoizq);
        imprimirPreorden(r->hijoder);
        std::cout << r->dato << " ";
    }
}

void arbol::anchuraPrimero(nodoArbol* r){
    if(r != NULL){
        std::cout << "     "<< r->dato << std::endl;
        anchuraPrimero(r->hijoizq);
        std::cout << "     ";
        anchuraPrimero(r->hijoder);
        std::cout << std::endl;
    }
}

int arbol::altura(nodoArbol* r){
    if(r == NULL) return 0;
    if( r->hijoizq == NULL && r->hijoder  == NULL) return 1;
    else{
        return std::max(altura(r->hijoizq),altura(r->hijoder)) +1;
    }

}

arbol::arbol(){
    raiz = NULL;
}
arbol::~arbol(){
    eliminarArbol(raiz);
}

void arbol::insertarNodo(int x){
    nodoArbol* p = new nodoArbol,*q,*padreq;
    int band = -1;
    p->dato = x;
    if(vacio()){
        raiz = p;
    }else{
        q = raiz;
        while(q != NULL){
            padreq = q;
            if( x < q->dato){
                q = q->hijoizq;
                band = 0;
            }else if(x > q->dato){
                q = q->hijoder;
                band = 1;
            }else{
                band = -1;
                break;
            }
        }
        if(band == 0){
            padreq->hijoizq = p;
        }else if(band == 1)
            padreq->hijoder = p;
    }
}
nodoArbol* arbol::encontrarElemento(int x){
    nodoArbol* p = raiz;
    while(p != NULL){
        if(x < p->dato) p = p->hijoizq;
        else if(x > p->dato) p = p->hijoder;
        else if(x == p->dato) break;
    }
    if(p == NULL) std::cout << "No se encontó el dato" << std::endl;
    else std::cout << "Se ha encontrado el dato" << std::endl;
    return p;
}

nodoArbol* arbol::encontrarPadre(int x){
    nodoArbol* p = raiz;
    nodoArbol* padrep = NULL;
    while(p != NULL){
        if(x < p->dato) {
            padrep = p;
            p = p->hijoizq;
            }
        else if(x > p->dato) {
            padrep = p;
            p = p->hijoder;
            }
        else if(x == p->dato) break;
    }

    if(padrep == NULL){
        return NULL;
    } 
    else return padrep;
}
void arbol::eliminarElemento(int x){
    
    nodoArbol* p = encontrarElemento(x),*e,*m;
    if(p == NULL) return;
    nodoArbol* pp = encontrarPadre(p->dato);
    nodoArbol* hdp = p->hijoder;
    nodoArbol* hip = p->hijoizq;
    
    if(hdp == NULL && hip == NULL){
        e = p;
        if(pp != NULL){
            if(pp->dato < p->dato) pp->hijoder = NULL;
            else pp->hijoizq = NULL;
        }else{
            raiz = NULL;
        }
        delete e;
    }else if(hdp == NULL){
        e = p;
        if(pp != NULL){
            if(p->dato < pp->dato) pp->hijoizq = hip;
            else pp->hijoder = hip;
        }else{
            raiz = hip;
        }
        delete e;
    }else {
        e = p;
        m = encontrarMenor(hdp);
        m->hijoizq = hip;
        if(pp != NULL){
            if(pp->dato < p->dato) pp->hijoder = hdp;
            else pp->hijoizq = hdp;
            delete p;
        }else{
            raiz = hdp;
            delete p;
        }
    }
    
}

nodoArbol* arbol::encontrarMayor(nodoArbol* r){
    nodoArbol* p = r;
    nodoArbol* padrep = NULL;
    if(!vacio()){
        while(p != NULL){
            padrep = p;
            p = p->hijoder;
        }
        return padrep;
    }else return NULL;
}

nodoArbol* arbol::encontrarMenor(nodoArbol* r){
    nodoArbol* p = r;
    nodoArbol* padrep = NULL;
    if(!vacio()){
        while(p != NULL){
            padrep = p;
            p = p->hijoizq;
        }
        return padrep;
    }else return NULL;
}

void arbol::eliminarArbol(nodoArbol* r){
    nodoArbol* e;
    if(r->hijoizq == NULL && r->hijoder == NULL){
        e = r;
        delete e;
    }else{
        if(r->hijoder != NULL){
            eliminarArbol(r->hijoder);
        }
        if(r->hijoizq != NULL)
            eliminarArbol(r->hijoizq);
    }
}

