#pragma once


#include <iostream>
#include <algorithm>

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
    void imprimirArbol(nodoArbol* raiz,int contador);
    void imprimirOrden(nodoArbol*);
    void imprimirPreorden(nodoArbol*);
    void imprimirPostorden(nodoArbol*);
    int altura(nodoArbol*);
    nodoArbol* encontrarElemento(int);
    nodoArbol* encontrarPadre(int);
    nodoArbol* encontrarMayor(nodoArbol*);
    nodoArbol* encontrarMenor(nodoArbol*);
    nodoArbol* sucesor(nodoArbol*);
    nodoArbol* sucesor(int);
    nodoArbol* antecesor(nodoArbol*);
    nodoArbol* antecesor(int);
    int padreMasJoven(int,int);
    int profunNodo(int x);
    int numHojas(nodoArbol*);
    void eliminarArbol(nodoArbol* r);
    void eliminarElemento(int);
    nodoArbol* getRaiz();
    void setRaiz(nodoArbol*);
    ~arbol();
};

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

void arbol::imprimirArbol(nodoArbol* r,int cnt){
    if(r == NULL) return;
    else{
        imprimirArbol(r->hijoder,cnt+1);
        for(int i = 0; i < cnt; i++){
            std::cout << "   ";
        }
        std::cout << r->dato << std::endl;
        imprimirArbol(r->hijoizq,cnt+1);
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

nodoArbol* arbol::encontrarMayor(nodoArbol* r){
    nodoArbol* p = r;
    nodoArbol* padrep = NULL;
    if(r != NULL){
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
    if(r != NULL){
        while(p != NULL){
            padrep = p;
            p = p->hijoizq;
        }
        return padrep;
    }else return NULL;
}

nodoArbol* arbol::sucesor(int x){
    nodoArbol* r = encontrarElemento(x);
    return sucesor(r);
}

nodoArbol* arbol::sucesor(nodoArbol* r){
    nodoArbol* p,*padrep;
    if(r == NULL) return NULL;
    if(r->hijoder != NULL)
        return encontrarMenor(r->hijoder);
    else{
        p = r;
        padrep = encontrarPadre(p->dato);
        while(padrep->dato <= p->dato){
            
            p = padrep;
            if(padrep != NULL)  
                padrep = encontrarPadre(padrep->dato);
            if(padrep == NULL) break;
        }
        if(padrep == NULL) {
            return padrep;
        }
        else return padrep;
    }
}

nodoArbol* arbol::antecesor(nodoArbol* r){
    nodoArbol* p,*padrep;
    if(r == NULL) return NULL;
    if(r->hijoizq != NULL)
        return encontrarMayor(r->hijoizq);
    else{
        p = r;
        padrep = encontrarPadre(p->dato);
        while(padrep->dato >= p->dato){
            p = padrep;
            if(padrep != NULL)  
                padrep = encontrarPadre(padrep->dato);
            if(padrep == NULL) break;
        }
        if(padrep == NULL) {
            return padrep;
        }
        else return padrep;
    }
}

nodoArbol* arbol::antecesor(int x){
    nodoArbol* r = encontrarElemento(x);
    return antecesor(r);
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

int arbol::numHojas(nodoArbol* r){
    int n = 0;
    if(r == NULL) return 0;
    else{
        if(r->hijoizq != NULL || r->hijoder != NULL){
            n = numHojas(r->hijoder) +  numHojas(r->hijoizq);
        }else{
             n++;
        }
    }
    return n;
}

void arbol::setRaiz(nodoArbol* r){
    raiz = r;
}