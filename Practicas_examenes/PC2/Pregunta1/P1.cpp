#include <iostream>

using namespace std;

struct nodo
{
    int dato;
    nodo* sig;
};

class Lista{
private:
    nodo* first;
public:
    Lista();
    void Insertar(int dato);
    void Imprimir();
    bool vacia();
    ~Lista();
};

Lista::Lista(){
    first = NULL;
}
void Lista::Insertar(int x){
    nodo* p = new nodo;
    p->dato = x;
    if(vacia()){
        p->sig = NULL;
        first = p;
    }else{
        nodo* q,*qAnt;
        qAnt = NULL;
        q = first;
        while(q->dato < x && q != NULL){
            qAnt = q;
            q = q->sig;
            if(q == NULL) break;
        }

        if(qAnt == NULL){
            p->sig = first;
            first = p;
        }else{
            qAnt->sig = p;
            p->sig = q;
        }
    }
}
void Lista::Imprimir(){
    nodo* p = first;
    while(p != NULL){
        cout << p->dato << " ";
        p = p->sig;
    }
    cout << endl;
}
bool Lista::vacia(){
    return (first == NULL) ? true :false;
}
Lista::~Lista(){
}


int main(){
    Lista l;
    l.Insertar(4);
    l.Insertar(1);
    l.Insertar(5);
    l.Insertar(8);
    l.Insertar(9);
    l.Insertar(0);
    l.Insertar(8);
    l.Insertar(1);
    l.Insertar(12);
    l.Imprimir();
    return 0;
}