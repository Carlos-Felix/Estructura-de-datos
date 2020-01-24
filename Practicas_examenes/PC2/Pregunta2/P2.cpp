#include <iostream>

using namespace std;

bool comparador(int x, int y){
    if(x%2 != 0){
        if(y%2 != 0){
            if(x > y) return true;
            else return false;
        }else return true;
    }else{
        if(y%2 == 0){
            if(x > y) return true;
            else return false;
        }return false;
    }
}

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
        while(comparador(x,q->dato) && q != NULL){
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

    int bf;
    while(1){
        cin >> bf;
        if(bf == 0) break;
       	l.Insertar(bf);
	};
    l.Imprimir();
    return 0;
}
