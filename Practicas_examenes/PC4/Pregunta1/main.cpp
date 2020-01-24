//#include <iostream>
#include "arbolBinario.h"

//using namespace std;

template <typename T>
bool isomorfo(nodoBin<T>* r1,nodoBin<T>* r2){
    if(r1 == NULL || r2 == NULL){
        if(r1 == NULL && r2 == NULL) return true;
        return false;
    }
    if(r1->dato != r2->dato) return false;
    else{
        if((isomorfo(r1->hd,r2->hd) && isomorfo(r1->hi,r2->hi)) || (isomorfo(r1->hd,r2->hi) && isomorfo(r1->hi,r2->hd))) return true;
        else return false;
    }
}

int main(){
    
    arbolBinario<int> ab;
    
    ab.insert(4,3,1);
    ab.insert(3,4,1);
    ab.insert(2,4,0);
    ab.insert(3,3,1);
    ab.insert(5,2,1);
    ab.insert(7,2,0);
    ab.imprimir(ab.getRaiz(),0);
    
    cout << "----------" << endl;
    arbolBinario<int> ab2;

    ab2.insert(4,3,1);
    ab2.insert(3,4,0);
    ab2.insert(2,4,1);
    ab2.insert(3,3,0);
    ab2.insert(5,2,0);
    ab2.insert(2,2,1);
    ab2.imprimir(ab2.getRaiz(),0);

    cout << endl;
    if(isomorfo<int>(ab.getRaiz(),ab2.getRaiz())) cout << "Son isomorfos\n";
    else cout << "No son isomorfos\n";
    return 0;
}