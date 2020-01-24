#include <iostream>

using namespace std;
///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////PILAS/////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
struct nodoc{
    char op;
    nodoc* sig;
};

class Pila{
    nodoc* cima;
    int n;

public:
    Pila();
    void apilar(char);
    void desapilar();
    char tcima();
    void Imprimir();
    bool vacia();
    ~Pila();

};

Pila::Pila(){

        cima = NULL;
        n = 0;
}

bool Pila::vacia(){
    if(cima == NULL) return true;
    else return false;

}
void Pila::apilar(char x){
    nodoc* p;
    p = new nodoc;
    p->op = x;

    if(vacia()){
        p->sig = NULL;
        cima = p;
        n++;
    }else{
        p->sig = cima;
        cima = p;
        n++;
    }

}

void Pila::desapilar(){
    nodoc* elim;
    if(!vacia()){
        elim = cima;
        cima = cima->sig;
        delete elim;
    }

}

char Pila::tcima(){

    char c;

    if(!vacia()){
        c = cima->op;
        return c;
    }
}


Pila::~Pila(){
    nodoc* p,*q;
    p = new nodoc;
    p = cima;
    while(p != NULL){
        q = p->sig;
        delete p;
        p = q;
    }

}

void Pila::Imprimir(){
    nodoc* p;
    p = new nodoc;
    p = cima;
    while(p != NULL){
        cout<<p->op<<" ";
        p = p->sig;

    }
    cout<<endl;
}

struct nodoi{
    int num;
    nodoi* sig;
};

class PilaInt{
    nodoi* cima;
    int n;

public:
    PilaInt();
    void apilar(int);
    void desapilar();
    int tcima();
    void Imprimir();
    bool vacia();
    ~PilaInt();

};



PilaInt::PilaInt(){

        cima = NULL;
        n = 0;
}

bool PilaInt::vacia(){
    if(cima == NULL) return true;
    else return false;

}
void PilaInt::apilar(int x){
    nodoi* p;
    p = new nodoi;
    p->num = x;

    if(vacia()){
        p->sig = NULL;
        cima = p;
        n++;
    }else{
        p->sig = cima;
        cima = p;
        n++;
    }

}

void PilaInt::desapilar(){
    nodoi* elim;
    if(!vacia()){
        elim = cima;
        cima = cima->sig;
        delete elim;
    }

}

int PilaInt::tcima(){

    int c;

    if(!vacia()){
        c = cima->num;
        return c;
    }
}


PilaInt::~PilaInt(){
    nodoi* p,*q;
    p = new nodoi;
    p = cima;
    while(p != NULL){
        q = p->sig;
        delete p;
        p = q;
    }

}

void PilaInt::Imprimir(){
    nodoi* p;
    p = new nodoi;
    p = cima;
    while(p != NULL){
        cout<<p->num<<" ";
        p = p->sig;

    }
    cout<<endl;
}

///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////COLAS/////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

class Cola{
    nodoi* frente;
    nodoi* fin;
    int n;
public:
    Cola();
    void Encolar(int);
    void Desencolar();
    int tFrente();
    bool Vacia();
    void Imprimir();
    ~Cola();

};

Cola::Cola(){
    frente = NULL;
    fin = NULL;
    n = 0;
}

void Cola::Encolar(int x){
    nodoi* p;
    p = new nodoi;
    p->num = x;
    p->sig = NULL;
    if(Vacia()){
        frente = p;
        fin = p;
        n++;
    }else {
        fin->sig = p;
        fin = p;
        n++;
    }
}

void Cola::Desencolar(){
    nodoi* p;
    if(!Vacia()){
        if(frente == fin){
            p = frente;
            frente = NULL;
            fin = NULL;
            delete p;
        }else{
            p = frente;
            frente = frente->sig;
            delete p;
        }

    }

}
int Cola::tFrente(){
    if(!Vacia()) return frente->num;
}

bool Cola::Vacia(){
    return (frente == NULL) ? true:false;
}

void Cola::Imprimir(){
    nodoi* p;
    p = frente;
    while(p != NULL){
        cout<<p->num<<" ";
        p = p->sig;
    }
    cout<<endl;

}

Cola::~Cola(){
    nodoi* p,*q;
    p = frente;
    while(p!=NULL){
        q = p;
        p = p->sig;
        delete q;
    }
}

class ListaSE{
    nodoi* first;
    nodoi* last;
    int n;
public:
    ListaSE();
    void Insert(int);
    void InsertFinal(int);
    int tElementInPos(int);
    void Imprimir();
    bool Vacio();
    void ElimElemento(int);
    void ElimElementoPos(int);
    int getNumElements();
    nodoi* PunteroInPos(int);
    ~ListaSE();

};
ListaSE::ListaSE(){
    first = NULL;
    last = NULL;
    n =0;
}

void ListaSE::Insert(int x){
    nodoi* p = new nodoi;
    p->num = x;
    if(Vacio()){
        p->sig = NULL;
        first = p;
        last = p;
        n++;
    }else{
        p->sig = first;
        first = p;
        n++;
    }
}

void ListaSE::InsertFinal(int x){
    nodoi* p = new nodoi;
    p->num = x;
    if(Vacio()){
        p->sig = NULL;
        first = p;
        last = p;
        n++;
    }else{
        p->sig = NULL;
        last->sig = p;
        last = p;
        n++;
    }
}

void ListaSE::Imprimir(){
    nodoi* p = first;
    while(p != NULL){
        cout<<p->num<<" ";
        p = p->sig;
    }
    cout<<endl;
}

int ListaSE::tElementInPos(int x){
    nodoi* p;
    int pos;
    if(!Vacio()){
        p = first;
        pos = 1;
        while(pos < x && pos < n){
            p = p->sig;
            pos++;
        }
        return p->num;
    }
}

bool ListaSE::Vacio(){
    return (first == NULL)? true:false;
}

void ListaSE::ElimElemento(int x){
    nodoi* p,*q;
    if(!Vacio()){
        q = NULL;
        p = first;
        while((p != NULL) && (p->num != x)){
            q = p;
            p = p->sig;
        }
        if(q == NULL){
            q = first;
            p = p->sig;
            delete q;
            first = p;
            n--;
        }

        if(p != NULL && p->num == x){
            q ->sig = NULL;
            delete p;
            last = q;
            n--;
        }
    }



}

void ListaSE::ElimElementoPos(int y){
    nodoi* p,*q,*r;
    p = PunteroInPos(y);
    q = PunteroInPos(y-1);
    if(p != NULL){
        if(q != NULL){
            r = p;
            q->sig = p->sig;
            delete r;
            n--;
        }else {
            r = p;
            p = p->sig;
            first = p;
            delete r;
            n--;
        }
    }

}
int ListaSE::getNumElements(){
    return n;
}

nodoi* ListaSE::PunteroInPos(int x){
    if((!Vacio()) && x > 0 && x <= n){
        nodoi* p;
        int pos;
        p = first;
        for(int i = 1; i < x; i++){
            p = p->sig;
        }
        return p;
    }else return NULL;
}

ListaSE::~ListaSE(){
    nodoi* p = first,*q;
    while(p != NULL){
        q = p;
        p = p->sig;
        delete q;
    }
}







