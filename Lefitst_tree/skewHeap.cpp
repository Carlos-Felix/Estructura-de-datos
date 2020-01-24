#include "skewHeap.h"

skewHeap::skewHeap()
{
    raiz = NULL;
}

skewHeap::~skewHeap(){
    //deleteHeap(raiz);
    while(getMin() != nulo){
        deleteMin();
    }
}

void skewHeap::deleteHeap(nodoSH* r){
    if(r == NULL) return;
    deleteHeap(r->left);
    deleteHeap(r->right);
    //r = NULL;
    //nodoSH* temp = r;
    delete r; 
}

nodoSH* skewHeap::getRaiz(){
    return raiz;
}

void skewHeap::setRaiz(nodoSH* x){
    raiz = x;
}

int skewHeap::getMin(){
    if(raiz == NULL){
        return nulo;
    }else{
        return raiz->dato;
    }
}

void skewHeap::deleteMin(){
    nodoSH* aux;
    if(raiz == NULL) return;
    aux = raiz;
    raiz = merge(raiz->left,raiz->right);
    delete aux;
}

void skewHeap::print(nodoSH* r,int cnt){
    if(r == NULL) return;
    else{
        print(r->right,cnt+1);
        for(int i = 0; i < cnt; i++){
            std::cout << "   ";
        }
        std::cout << r->dato << std::endl;
        print(r->left,cnt+1);
    }
}

void skewHeap::insert(int x){
    nodoSH* p = new nodoSH;
    p->dato = x;
    p->left = NULL;
    p->right = NULL;
    if(raiz == NULL){
        raiz = p;
        return;
    }
    
    raiz = merge(raiz,p);
}

void balanceo(nodoSH* r){
    
    if(r!= NULL){
        nodoSH* aux = r->left;
        r->left = r->right;
        r->right = aux;
    }
    
}

nodoSH* skewHeap::merge(nodoSH* r2){
    if(raiz == NULL) return NULL;
    if(r2 == NULL) return raiz;
    raiz = merge(raiz,r2);
    return raiz;
}


nodoSH* skewHeap::merge(nodoSH* r1,nodoSH* r2){
    if(r1 == NULL && r2 == NULL){
        return NULL;
    }
    if(r1 == NULL) return r2;
    if(r2 == NULL) return r1;
    if(r1->dato <= r2->dato){ 
        if(r1->right == NULL){
            r1->right = r2;
            
        }else{
            r1->right = merge(r1->right,r2);
        }
        balanceo(r1);
        
        return r1;
    }else{
        if(r2->right == NULL){
            r2->right = r1;
            
        }else{
            r2->right = merge(r2->right,r1);
        }
        balanceo(r2);
        return r2; 
    }

}
