#include <iostream>

using namespace std;

const int N = 10;

void imprimir(int a[N]){
    for(int i = 0; i < N ; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void Quick_Sort(int a[N],int p1,int p2){

    int n = (p1 + p2 +1)/2,aux;

    int pivote = a[n];

    cout<<"pivote: "<<pivote<<endl;

    for(int i = p1; i <= n; i++){
        for(int j = p2; j >= n; j--){
            if(a[i] >= pivote && a[j] <= pivote){
                if(a[i] == pivote) n = j;
                if(a[j] == pivote) n = i;
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
        imprimir(a);
    }

    cout<<"n: "<<n<<endl;
    cout<<"p1: "<<p2<<",p2: "<<p2<<endl;
    cout<<"p2-p1: "<<(p2-p1)<<endl;

    if(p1 < p2){
        Quick_Sort(a,p1,n-1);
        Quick_Sort(a,n+1,p2);
    }


}
int main(){

    int a[N] = {3,3,3,3,4,5,6,7,8};

    Quick_Sort(a,0,N-1);

    return 0;
}
