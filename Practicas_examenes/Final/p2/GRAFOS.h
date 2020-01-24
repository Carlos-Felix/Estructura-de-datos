#include <iostream>
#include "arbol_busqueda.h"

using namespace std;

struct arista
{
    int dato;
    arista* sig;

};

struct vertice{
    int dato;
    arista* fr;
    vertice* sig;
};

class Grafo{
private:
    vertice* first;
public:
    Grafo();
    void insertarVertice(int x);
    void insertarArista(int x,int y);
    vertice* buscarVertice(int x);
    void Eliminar(int);
    void imprimirGrafo();
    void Ordenar();
    vertice* Menor();
    vertice* Mayor();
    
};


Grafo::Grafo(){
    first = NULL;
}

void Grafo::Eliminar(int x){
    vertice* vant = NULL;
    vertice* v;

    if(first != NULL){
        v = first;
        while(v->dato != x){
            vant = v;
            v = v->sig;
            if(v == NULL) break;
        } 
    }else return;
    if(vant == NULL){
        first = v->sig;
    }else if( v == NULL){
        
    }else{
        vant->sig = v->sig;
    }
}

void Grafo::insertarVertice(int x){
    vertice* q = new vertice;
    q->dato = x;
    q->fr = NULL;
    q->sig = NULL;
    if(first == NULL){
        first = q;
        return;
    }
    bool fnd = false;
    vertice* p = first;
    while(p->sig != NULL){
        if(p->dato == x){
            fnd = true;
            break;
        }
        p = p->sig;
    }
    if(!fnd)
        if(p->dato == x)
            fnd = true;
            
    if(!fnd) p->sig = q;
}

vertice* Grafo::buscarVertice(int x){
    vertice* v;
    if(first != NULL){
        v = first;
        while(v->dato != x){
            v = v->sig;
            if(v == NULL) break;
        }
        return v;
        
    }else return NULL;
}


void Grafo::insertarArista(int x, int y){
    vertice* n = buscarVertice(x);
    if(n == NULL) return;
    arista* q = new arista;
    q->dato = y;
    q->sig = NULL;
    if(n->fr == NULL){
        n->fr = q;
        return;
    }
    bool fnd = false;
    arista* p = n->fr;
    
    while(p->sig != NULL){
        if(p->dato == y){
            fnd = true;
            break;
        }
        p = p->sig;
    }

    if(!fnd)
        if(p->dato == y)
            fnd = true;
    
    if(!fnd) p->sig = q; 
}

void Grafo::imprimirGrafo(){
    if(first == NULL) return;
    vertice *p = first;
    arista *a;
    while(p != NULL){
        cout << p->dato << " ";
        a = p->fr;
        while(a != NULL){
            cout << a->dato << " ";
            a = a->sig;
        }
        p = p->sig;
        cout << endl;
    }
    cout << endl;
}

vertice* Grafo::Menor(){
    vertice* v;
    v = first;
    
    vertice* men;
    men = v;
    while(v != NULL){
        if(men->dato > v->dato) men = v;
        v = v->sig;
    }
    return men;
}

vertice* Grafo::Mayor(){
    vertice* v;
    v = first;
    
    vertice* may;
    may = v;
    while(v != NULL){
        if(may->dato < v->dato) may = v;
        v = v->sig;
    }
    return may;
}

void Grafo::Ordenar(){
    vertice* v;
    int cont = 0;
    cout << "Orden: " << endl;
    while(first != NULL){
        v = Mayor();
        cout << v->dato << " ";
        Eliminar(v->dato);
        cont++;
        if(cont == 100){
            cout << "llega aca";
            break;
        }
    }
    cout << endl;
}
