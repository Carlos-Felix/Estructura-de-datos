#include <iostream>

using namespace std;

const int N = 24;

void imprimir(int a[N]){

    for(int i = 0 ; i < N; i++) cout<<a[i]<<", ";
    cout<<endl;
}

void ord_seleccion(int a[N]){

    int menor,j,aux;

    for(int i = 0; i < N; i++){

        for(int j = i; j < N; j++){
            if(a[i] > a[j]) {
                    aux = a[i];
                    a[i] = a[j];
                    a[j] = aux;
            }
        }

    }
    imprimir(a);

}

int main(){

    int a[N] = {0,3,4,3,7,10,400,20,3,23,40,20,12,36,48,29,10,49,20,900,40,29,16,50};

    imprimir(a);

    ord_seleccion(a);

}
