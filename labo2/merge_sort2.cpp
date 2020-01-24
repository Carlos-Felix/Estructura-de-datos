#include <iostream>

using namespace std;

void imp (int a[], int ini,int n){
	for(int i = ini; i < n; i++)
		cout<<a[i]<<" ";
		
	cout<<endl;
}

void merge(int *izq, int nIzq, int *der, int nDer, int *A){
	int i = 0, j = 0, k = 0;
	while( (i < nIzq) && (j < nDer)){
		if( izq[i] <= der[j]){
		
			A[k] = izq[i];
			i++;
		
		}
		else{
			A[k] = der[j];
			j++;
		}
		k++;
	}
	while( i < nIzq){
	
		A[k] = izq[i];
		i++;
		k++;
	
	}
	while(j < nDer){
		A[k] = der[j];
		j++;
		k++;
	}
}


void mSort(int *A,int n){

	if(n == 1){return;}
	int mitad = n/2;
	int *izq = new int[mitad];
	int *der = new int[n-mitad];
	for(int i = 0; i < mitad; i++)
		izq[i] = A[i];
	for(int i = mitad; i < n; i++)
		der[i-mitad] = A[i];
	mSort(izq, mitad);
	mSort(der, n-mitad);
	merge(izq,mitad,der,n-mitad, A);

}



int main(){

	int lista[] = {1,2,5,6,8,10,58,69,2,5,48,7};
	int n = sizeof(lista)/sizeof(int);
	
	cout<<" Antes del merge sort: ";
	imp(lista,0,n);
	mSort(lista,n);
	cout<<"DESPUES del merge sort: ";
	imp(lista,0,n);
	return 0;

}
