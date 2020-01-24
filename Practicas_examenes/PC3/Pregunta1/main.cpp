#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

#define MAX 10

char Laberinto[MAX][MAX] ={{'X','X','X','X','*','X','X','X','X','X'},
                          {'X','X','X','X',' ','X','X','X','X','X'},
                          {'X','X','X','X',' ','X','X','X','X','X'},
                          {'X',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                          {'X','X','X',' ','X','X','X','X','X','X'},
                          {'X','X','X',' ',' ',' ',' ',' ',' ','X'},
                          {'X','X','X','X','X','X','X','X',' ','X'},
                          {'X','X','X','X','X','X','X','X',' ','X'},
                          {'X',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                          {'X','X','X','X','X','X','X','X','X','X'}};

void imprimir(){
    
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
            cout << Laberinto[i][j];
        cout << endl;
    }
    cout << endl;
}

bool camino(int i, int j){
    if(Laberinto[i][j] == '*') return true; // SALIDA
    if(Laberinto[i][j] == 'X') return false; //PARED
    if(Laberinto[i][j] == 'o') return false; // HILO
    Laberinto[i][j] = 'o';
    imprimir();
    if(camino(i+1,j)) return true; //ABAJO
    else if(camino(i-1,j)) return true; //ARRIBA
    else if(camino(i,j-1)) return true; //IZQUIERDA
    else if(camino(i,j+1)) return true; // DERECHA
    else return false; 
}
int main(){
    int X,Y;
    srand(time(NULL));
    do{
        Y = rand()%MAX;
        X = rand()%MAX;
    }while(Laberinto[Y][X] != ' ');

    cout << camino(Y,X) << endl;
    
    return 0;
}