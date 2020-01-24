#include <iostream>

using namespace std;

int N;

void imprimir(int a[]){
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int promedio(int a[],int i,int j){
    int suma = 0;
    for(int k = i; k <= j; k++){
        suma = suma + a[k];
    }
    return (suma/(j-i+1));
}

int particion(int a[],int i,int j){
    int pivote = promedio(a,i,j);
    int m = i-1;
    for(int k = i; k <= j; k++){
        if(a[k] <= pivote){
            m = m+1;
            int aux = a[m];
            a[m] = a[k];
            a[k] = aux;
        }
    }
    return m+1;
}

void QuickSortProm(int a[],int i, int j){
    int cont = 0;
    int q = 0;

    if(i < j){
        q = particion(a,i,j);
        if(q > j) return;
        QuickSortProm(a,i,q-1);
        QuickSortProm(a,q,j);
    }
}

int main(){
    cout << "Ingrese el tamaño del arreglo : ";
    cin >> N;
    int a[N];

    cout << "Ingrese los elementos: " << endl;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    QuickSortProm(a,0,N-1);
    imprimir(a);
    return 0;
}
