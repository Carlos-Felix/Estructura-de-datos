#include <iostream>
using namespace std;

nodopila{
	int dato;
	nodopila *sgt;	
}*sima;

void apilar(int x);
void desapilar();
void imprimir();

int main(){
	
}

void apilar(int x){
	nodopoila p;
	p= new nodopila;
	p->dato=x;
	p->sgt=sima;
	sima=p;	
}

void desapilar(){
	nodopila p;
	p= sima;
	sima=p->sgt;
	delete p;
}

void imprimir(){
	nodopila p;
	p=sima;
	while
}
