#include <iostream>

using namespace std;

const int N = 20;

void imprimir(int a[N]){

    for(int i = 0 ; i < N; i++) cout<<a[i]<<", ";
    cout<<endl;
}

void ord_insercion(int a[N]){

    int pos,aux;

    for(int i = 1; i < N; i++){

        pos = -1;

        for(int j = i; j >=0; j--){

            if(a[i] < a[j]){
                pos = j;
            }

        }
        if(pos != -1){

            aux = a[i];
            for(int j = i; j > pos; j--){
                a[j] = a[j-1];
                cout<<"Desplazar: ";
                imprimir(a);
            }
            a[pos] = aux;
            imprimir(a);
        }

    }

    imprimir(a);

}

int main(){

    int a[N] = {4,3,5,2,1,20,17,30,1,20,40,29,38,39,48,50,100,40,28,30};

    imprimir(a);

    ord_insercion(a);

    return 0;
}
