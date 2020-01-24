#include <iostream>

#define MAX INT32_MAX
 
using namespace std;

int N,M;

void imprimir(int a[]);
int Particion(int a[],int i,int j);
void QuickSort(int a[],int i,int j);

void Merge(int a[],int b[],int i,int j){
    
    if(i >= N && j >= M) return;
    if(a[i] <= b[j]){ 
        while(a[i] <= b[j] && (i < N)){
            cout <<  a[i] << " ";
            ++i;
        }
    }else if(b[j] <= a[i]){
        while(a[i] >= b[j] && (j < M)){
            cout <<  b[j] << " ";
            ++j;
        }
    }
    Merge(a,b,i,j);
}

int main(){
    N = 11;
    M = 14;
    int a[N+1] = {3,4,3,5,6,4,6,7,1,3,4,MAX};
    int b[M+1] = {4,3,4,6,7,1,8,2,3,4,1,5,3,4,MAX};
    QuickSort(a,0,N-1);
    QuickSort(b,0,M-1);
    Merge(a,b,0,0);
    cout << endl;
    return 0;
}

void imprimir(int a[]){
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}    

int Particion(int a[],int i,int j){
    int key = a[j];
    int m = i-1;
    for(int k = i; k <= j;k++){
        if(a[k] <= key){
            ++m;
            int aux = a[k];
            a[k] = a[m];
            a[m] = aux;
        }
    }
    return m; 
}

void QuickSort(int a[],int i,int j){
    if(i < j){
        int q = Particion(a,i,j);
        QuickSort(a,i,q-1);
        QuickSort(a,q,j);
    }
}