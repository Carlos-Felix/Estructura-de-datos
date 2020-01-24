#include "leftistHeap.h"

leftistHeap::leftistHeap()
{
    raiz = NULL;
}

leftistHeap::~leftistHeap(){
    deleteHeap(raiz);
    //while(getMin() != nulo){
    //    deleteMin();
    ///}
}

void leftistHeap::deleteHeap(nodo* r){
    if(r == NULL) return;
    deleteHeap(r->left);
    deleteHeap(r->right);
    nodo* temp = r;
    delete temp; 
}

nodo* leftistHeap::getRaiz(){
    return raiz;
}

void leftistHeap::setRaiz(nodo* x){
    raiz = x;
}

int leftistHeap::getMin(){
    if(raiz == NULL){
        return nulo;
    }else{
        return raiz->dato;
    }
}

void leftistHeap::deleteMin(){
    nodo* aux;
    if(raiz == NULL) return;
    aux = raiz;
    raiz = merge(raiz->left,raiz->right);
    delete aux;
}

void leftistHeap::print(nodo* r,int cnt){
    if(r == NULL) return;
    else{
        print(r->right,cnt+1);
        for(int i = 0; i < cnt; i++){
            std::cout << "   ";
        }
        std::cout << r->dato /*<< "," << r->rank */ << std::endl;
        print(r->left,cnt+1);
    }
}

void leftistHeap::insert(int x){
    nodo* p = new nodo;
    p->dato = x;
    p->rank = 0;
    p->left = NULL;
    p->right = NULL;
    if(raiz == NULL){
        raiz = p;
        return;
    }
    
    raiz = merge(raiz,p);
}

void balanceo(nodo* r){
    if(r->left == NULL || r->right == NULL){
        if(r->left != NULL){
            return;
        }else if(r->right != NULL){
            r->left = r->right;
            r->right = NULL;
        }
    }else{
        r->rank = std::min(r->right->rank,r->left->rank)+1;
        if(r->right->rank > r->left->rank){
            nodo* aux = r->left;
            r->left = r->right;
            r->right = aux;
        }
    }
}

nodo* leftistHeap::merge(nodo* r2){
    if(raiz == NULL) return NULL;
    if(r2 == NULL) return raiz;
    raiz = merge(raiz,r2);
    return raiz;
}

nodo* leftistHeap::merge(nodo* r1,nodo*r2){
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
