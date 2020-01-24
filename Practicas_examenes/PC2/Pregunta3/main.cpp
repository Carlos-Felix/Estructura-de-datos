#include "ListaCircular.h"

using namespace std;

ListaCircular<int> f;
ListaCircular<int> l;
int n,m;

void fibonacci(ListaCircular<int> &l,int a[]){
    a[0] = 1;
    a[1] = 1;
    for(int i = 0; i < n; i++){
        if(i >= 2) a[i] = a[i-1] + a[i-2]; 
        l.insertar(a[i]);
    }
}

void lista(ListaCircular<int> &l){
    int bf;
    cout << "Ingrese los elementos de I(2): \n";
    for(int i = 0; i < m; i++){
        cin >> bf;
        l.insertar(bf);
    }
}

void ans(ListaCircular<int> &f,ListaCircular<int> &l){
    nodo<int>* cl;
    while(!l.vacio()){
        cl = l.getCabeza();
        f.eliminarElemento(cl->dato);
        l.eliminarElemento(cl->dato);
    }
}

int main(){
    cout << "Ingrese n: ";
    cin >> n;
    int a[n];
    cout << "Ingrese m: ";
    cin >> m;
    fibonacci(f,a);
    lista(l);
    cout << "I(1): ";
    f.imprimir();

    cout << "I(2): ";
    l.imprimir();

    ans(f,l);

    cout << "ans: \n";
    cout << "I(1): "; 
    f.imprimir();
    return 0;
}