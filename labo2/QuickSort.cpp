//QUICK SORT
#include <iostream>

using namespace std;

const int N = 7;

void imprimir(int a[N]){

	int i;
	for(i =0; i < N; i++)
		cout<< a[i]<<" ";
	cout<<endl;

}

void quickSort(int a[N], int pri, int ult){

	int i,j,c,piv,aux;
	i=pri;
	j = ult;
	
	c=(pri + ult)/2;
	piv = a[c];
	
	do{
	
		while(a[i] < piv)
			i++;
		while(a[j] > piv)
			j--;
		if(i<=j){
		
			aux = a[i];
			a[i] = a[j];
			a[j] = aux;
			i++;
			j--;
			imprimir(a);
		
		}
	}while(i <= j);
	if(pri < j)
		quickSort(a,pri,j);
	if(i < ult)
		quickSort(a,i,ult);

}

int main(){

	int a[N] = {8,5,6,7,4,1,0};
	imprimir(a);
	quickSort(a,0,N-1);
	imprimir(a);
	
	return 0;

}


