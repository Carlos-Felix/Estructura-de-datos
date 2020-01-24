#include <iostream>

using namespace std;

int N;

void imprimir(int a[]){
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int menor(int a[],int i,int j){
    int PosMenor = i;
    for(int k = i; k <= j; k++)
        if(a[k] < a[PosMenor]) PosMenor = k;
    return PosMenor;

}

int mayor(int a[],int i,int j){
    int PosMayor = i;
    for(int k = i; k <= j; k++)
        if(a[k] > a[PosMayor]) PosMayor = k;
    return PosMayor;

}

void Ordena(int a[],int i, int j){
    if(i < j){
        int pos = menor(a,i,j);
        if(pos != i){
            int aux = a[i];
            a[i] = a[pos];
            a[pos] = aux;
        }
        i++;
    }

    imprimir(a);

    if(i < j){
        int pos = mayor(a,i,j);
        if(pos != j){
            int aux = a[j];
            a[j] = a[pos];
            a[pos] = aux;
        }
        j--;
    }

    imprimir(a);

    if(i < j) Ordena(a,i,j);

}

int main(){
    
    cout << "Ingrese el tamaño del arreglo : ";
    cin >> N;
    int a[N];

    cout << "Ingrese los elementos: " << endl;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    cout << "Ordena: "<< endl;
    Ordena(a,0,N-1);
    return 0;
}