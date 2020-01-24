#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo* sig;
    nodo* ant;


};

class lista{
    private:
    nodo* pL;
    public:
    lista();
    ~lista();
    void insertar_comienzo(int x);
    void insertar_final(int x);
    void imprimir();
    void buscar(int x);
    void Eliminar(int x);

};

lista::~lista(){
    nodo* p,*q;
    if(pL != NULL){
        p = pL;
        while(p!= NULL){
        
            q =(*p).sig;
            delete p;
            p = q;
        }
    
    }
}

lista::lista(){

    pL = NULL;
    
}

void lista::insertar_comienzo(int x){

    if(pL == NULL){
        nodo* p;
        p = new nodo;
        (*p).dato = x;
        (*p).sig = NULL;
        (*p).ant = NULL;
        pL = p;
    
    }else{
        nodo* p;
        p = new nodo;
        (*p).dato = x;
        (*p).sig = pL;
        (*p).ant = NULL;
        (*pL).ant = p;
        pL = p;
    }
    
}

void lista::insertar_final(int x){

    if(pL == NULL){
        nodo* p;
        p = new nodo;
        (*p).dato = x;
        (*p).sig = NULL;
        (*p).ant = NULL;
        pL = p;
    
    }else{
        nodo* p,*q;
        q = pL;
        p = new nodo;
        (*p).dato = x;
        (*p).sig = NULL;
        while((*q).sig != NULL){
            q = (*q).sig;
        
        }
        (*p).ant = q;
        (*q).sig = p;
    }
    
}

void lista::buscar(int x){

    nodo* p;
    int i =0,a=0;
    p = pL;
    if(pL == NULL)
        cout<<"lista vacía"<<endl;
    else{
        
        while(p != NULL){
            if((*p).dato == x){
                
                a = 1;
            }
            p = (*p).sig;        
        }       
    
    }
    
    if(a == 1) cout<<"el numero se encuentra en la lista"<<endl;
    if(a == 0) cout<<"el numero no se encuentra en la lista"<<endl;


}

void lista::imprimir(){
    nodo* p;
    if( pL == NULL)
        cout<<"lista vacía"<<endl;
    else {
        p = pL;
        while(p!= NULL){
            cout<<(*p).dato<<" <-> ";
            p = (*p).sig;
        
        }
        cout<<"NULO"<<endl;
    
    }

}

void lista::Eliminar(int x){
    nodo* p,*q,*r;
    p = pL;
    
    
    
    
    if( pL == NULL)
        cout<<"lista vacía"<<endl;
    else {
    
        while((*pL).dato == x){
            r = pL;
            pL = ((*pL).sig);
            delete r; 
        
        }
        
        p = ((*pL).sig);
        q = (*p).ant;
        while(p != NULL){
            if((*p).dato == x){
                r = p;
                (*q).sig = (*p).sig;
                p = (*p).sig;
                if(p != NULL ) (*p).ant = q;
                delete r;
            
            }else{
                
                p = (*p).sig;
                q = (*q).sig;
            }
            
        }
    
    }
    

}

int main(){
    //nodo* p;
    //cout<<p;
    int x;
    lista L;
    
    cout<<"Ingrese un elemento al inicio"<<endl;
    cin>>x;
    L.insertar_comienzo(x);
    cout<<"Ingrese un elemento  al inicio"<<endl;
    cin>>x;
    L.insertar_comienzo(x);
    cout<<"Ingrese un elemento  al inicio"<<endl;
    cin>>x;
    L.insertar_comienzo(x);
    cout<<"Ingrese un elemento  al inicio"<<endl;
    cin>>x;
    L.insertar_comienzo(x);
    cout<<"Ingrese un elemento  al inicio"<<endl;
    cin>>x;
    L.insertar_comienzo(x);
     cout<<"Ingrese un elemento al final"<<endl;
    cin>>x;
    L.insertar_final(x);
     cout<<"Ingrese un elemento al final"<<endl;
    cin>>x;
    L.insertar_final(x);
     cout<<"Ingrese un elementoal final"<<endl;
    cin>>x;
    L.insertar_final(x);
    
    L.imprimir();
    cout<<"Ingrese un elementoa buscar"<<endl;
    
    cin>>x;
    L.buscar(x);
    
    cout<<"Ingrese un elemento a eliminar"<<endl;
    cin>>x;
    L.Eliminar(x);
    L.imprimir();
    
    cout<<"Ingrese un elemento a eliminar"<<endl;
    cin>>x;
    L.Eliminar(x);
    L.imprimir();
    
    cout<<"Ingrese un elemento a eliminar"<<endl;
    cin>>x;
    L.Eliminar(x);
    L.imprimir();
    
    

}
