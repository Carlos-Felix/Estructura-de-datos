/*PROGRAMA QUE ENCUENTRA UN NUMERO EN UN ARRAY MEDIANTE EL METODO DE BUSQUEDA SECUENCIAL*/

#include <iostream>
#include <conio.h>

using namespace std;

const int N = 13;

//FUNCION PARA IMORIMIR UN ARRAY
void imprimir(int a[N]){
     for(int i = 0; i < N; i++)
             cout<<a[i]<< " ";
     cout<<endl;
     }

//FUNCION QUE IMPLEMENTA EL METODO DE BUSQUEDA SECUENCIAL, DEVUELVE LA POSICION DEL
//NUMERO O -1 SI NO LO ENCUENTRA
int busqueda_secuencial(int a[N], int x){
    
    for(int i = 0; i < N; i++)
            if(a[i] == x) return i;
    return -1; 
}

int main(){
    
    int pos;
    int a[N] = {3,4,3,2,5,6,54,5,4,3,4,5,7};
    
    imprimir(a);
    
    pos = busqueda_secuencial(a, 1000);
    
    if(pos == -1) 
           cout<<"No se encontro"<<endl;
           else
               cout<<"la posicion es "<<pos<<endl;
               
    getch();
    
}

