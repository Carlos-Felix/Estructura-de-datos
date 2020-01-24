#include <iostream>
#include <conio.h>

using namespace std;

const int N = 11;

int seleccion_binario(int a[N],int x){
    int u,k,l, iteracciones = 1;

    u = 0;
    k = N-1;
    l = (u + k)/2;
    cout << "u: "<< u << " k: " << k <<" l: "<< l <<endl;

    while(u <  k){
        if(x != a[u] && x != a[k]){
            l = (u + k)/2;
            if (x == a[l]) return l;
            if (x > a[l]){
                u = l+1;
                k = k-1;
                l = (u + k)/2;
                cout << "u: "<< u << " k: " << k <<" l: "<< l <<endl;
            }
            if (x < a[l]){
                u = u +1;
                k = l-1;
                l = (u + k)/2;
                cout << "u: "<< u << " k: " << k <<" l: "<< l <<endl;
            }


        }else
            {
                if(x == a[u]) {
                        return u;
                }
                if(x == a[k]) return k;
            }
    }
    return -1;

}

int main(){

    int pos,a[N]={3,4,7,12,17,20,22,44,99,150,300};

    pos = seleccion_binario(a,150);
    if(pos == -1) cout << "No se encontro" <<endl;
        else cout << "se encuentra en la posicion: "<< pos <<endl;

    return 0;
}
