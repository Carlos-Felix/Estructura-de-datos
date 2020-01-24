#include <iostream>

using namespace std;

struct nodo{
    int numero;
    nodo* siguiente;
};
class Lista{
    int NElem;
    nodo* pL;

public:
    Lista();
    void insertarInicio(int);
    void Imprimir();
    nodo* getPrimer();
    int getNumDeElementos();
    void BubbleSort();
    void InsertSort();
    void EliminarElemento();
    void EliminarPosicion();
    void EliminarPrimerNumeroIgualA();
    ~Lista();
};

Lista::Lista(){
    NElem = 0;
    pL = NULL;

}
Lista::~Lista(){
    nodo* p,*q;
    p = pL;
    while(p != NULL){
        q = p;
        p = p->siguiente;
        delete q;
    }

}
void Lista::insertarInicio(int n){
    nodo* p;
    p = new nodo();
    p->numero = n;
    p->siguiente = pL;
    pL = p;
    NElem++;
}

void Lista::Imprimir(){
    nodo* p;
    p = pL;
    if(p == NULL) cout<<"Lista vacia, ingrese un elemento"<<endl;
    while(p != NULL){
        cout<<p->numero<<"->";
        p = p->siguiente;
    }
    cout<<endl;

}
void Lista::EliminarElemento(){
    int n,flag = 0;
    nodo* p,*elim,*q;
    cout<<"Ingrese un elemento a eliminar"<<endl;
    cin>>n;
    if(pL == NULL) cout<<"Lista vacia, ingrese elementos a la lista."<<endl;
    else {
        while(pL->numero == n){
            elim = pL;
            pL = pL->siguiente;
            delete elim;
        }
        if(pL->siguiente == NULL) return;
        else{
            q = pL;
            p = pL->siguiente;
            while(p != NULL){
                if(p->numero == n){
                    elim = p;
                    q->siguiente = p->siguiente;
                    p = p->siguiente;
                    delete elim;
                }else{
                    q = q->siguiente;
                    p = p->siguiente;
                }
            }
        }
    }
}
int Lista::getNumDeElementos(){
    return NElem;
}

void Lista::BubbleSort(){
    nodo* p;
    int aux, flag = 0;

    while(flag == 0){
        flag = 1;
        p = pL;
        while(p->siguiente != NULL){
            if(p->numero > (p->siguiente)->numero){
                aux = p->numero;
                p->numero = (p->siguiente)->numero;
                (p->siguiente)->numero = aux;
                flag = 0;
            }
            p = p->siguiente;

        }
    }
}

nodo* Lista::getPrimer(){
    return pL;
}









