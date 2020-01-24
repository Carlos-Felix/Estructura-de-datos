#include<iostream>
using namespace std;

struct nodoArbol{
	int dato;
	nodoArbol *arbolizq;
	nodoArbol *arbolder;
};
typedef nodoArbol *pnodoArbol;

class arbol{
	private: 
		pnodoArbol praiz;
	public:	
		arbol();
		//~arbol();
		void insertarNodo(int);
		void imprimir(pnodoArbol);
		pnodoArbol getraiz();
};

arbol::arbol(){
	praiz=NULL;
}
pnodoArbol arbol::getraiz(){
	return praiz;
}
void arbol::insertarNodo(int x){
        pnodoArbol p,q,padreq;
	char hijo;
	p=new nodoArbol;
	p->dato=x;
	p->arbolizq=NULL;
	p->arbolder=NULL;
	q=praiz;
	if(q==NULL)
		praiz=p;
	else{
		while(q!=NULL){
			padreq=q;
			if(x<q->dato)
				{q=q->arbolizq; hijo='i';}
			else if(x>q->dato)
				{q=q->arbolder; hijo='d';}
		}
		if(hijo=='i')
			padreq->arbolizq=p;
		else
			padreq->arbolder=p;
	}

}
void arbol::imprimir(pnodoArbol r){
		if(r!=NULL){	
		imprimir(r->arbolizq);
		cout<<r->dato<<" ";
		imprimir(r->arbolder);
		}
}

int main(){
	arbol abb;
	abb.insertarNodo(5);cout<<"insertó 5"<<endl;
        abb.insertarNodo(4);cout<<"insertó 4"<<endl;
	abb.insertarNodo(3);cout<<"insertó 5"<<endl;
        abb.insertarNodo(8);cout<<"insertó 4"<<endl;
	abb.imprimir(abb.getraiz());

}











 















