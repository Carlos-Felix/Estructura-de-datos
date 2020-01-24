/*PROGRAMA BASADO EN EL METODO DE ORDENAMIENTO BURBUJA*/
#include <iostream>
#include <conio.h>

using namespace std;

//SE DEFINE LA CONSTANTE
const int N = 7;

//FUNCION PARA IMORIMIR UN ARRAY
void imprimir(int a[N]){
     for(int i = 0; i < N; i++)
             cout<<a[i]<< " ";
     cout<<endl;
     }
     

//FUNCION QUE ORDENA UNA ARRAY MEDIANTE EL METODO DE  ORDENAMIENTO BURBUJA
void ord_burbuja(int a[N]){
    int aux;
       for(int i = 0; i < N; i++){
               for(int j = 0; j < N -1; j++){
                       if (a[j] >  a[j+1]){
                                aux = a[j+1];
                                a[j+1] = a[j];
                                a[j] = aux;
                                }
                       }        
       }
       
       imprimir(a);
}

int main(){
    
    int a[N] = {3,2,1,10,100,43,99};
    imprimir(a);     
    ord_burbuja(a);
    
    //DETIENE LA EJECUCION DEL PROGRAMA HASTA QUE SE PRECIONE UNA TECLA
    getch();
    
    }
