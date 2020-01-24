#include <iostream>
#include "Pila.h"

using namespace std;

class Lista{
    nodo<char>* pr;
    int n;
public:
    Lista();
    void Insertar(char );
    void Imprimir();
    ~Lista();

};

Lista::Lista(){
    pr = NULL;
    n = 0;
}
Lista::~Lista(){
    nodo<char>* p,*q;
    p = pr;

    while(p != NULL){
        q = p;
        p = p->sig;
        delete q;
    }

}

void Lista::Imprimir(){
    nodo<char>* p;
    p = pr;
    while(p != NULL){
        cout<<p->dato<<" ";
        //cout<<p->op;
        p = p->sig;
    }
    cout<<endl;

}

void Lista::Insertar(char s){
        nodo<char>* p,*q;
        q = pr;
        p = new nodo<char>;
        p->dato = s;
        p->sig = NULL;
        if(pr == NULL){
            pr = p;

        }else{
            while(q->sig != NULL){
                q = q->sig;

            }
            q->sig = p;
        }
}

bool IsNumber(char s){
    bool band = false;
    int a = 0;
    if( (int)s >= 48 && (int)s <= 57){
        band = true;

    }
    return band;
}

Lista* InfijoToPostfijo(string s){

    int x;
    Pila<char> Operadores;
    Lista* Postfija;
    Postfija = new Lista;

    for(int i = 0; i < s.length();i++){
        if(IsNumber(s[i])){

            Postfija->Insertar(s[i]);
        }else{
            switch((int)s[i]){
                case 40:
                    Operadores.apilar(s[i]);
                    break;
                //RESTA
                case 42:
                    x = Operadores.tcima();
                    if( x == 42 || x == 43 || x == 45 || x == 47 || x == 95 ){
                        Postfija->Insertar(Operadores.tcima());
                        Operadores.desapilar();

                    }
                    Operadores.apilar(s[i]);
                    break;
                //SUMA
                case 43:
                    x = Operadores.tcima();
                    while( x == 42 || x == 43 || x == 45 || x == 47 || x == 95 ){
                        Postfija->Insertar(Operadores.tcima());
                        Operadores.desapilar();
                        x = Operadores.tcima();
                    }
                    Operadores.apilar(s[i]);
                    break;
                //MULTIPLICACION
                case 45:
                    x = Operadores.tcima();
                    while(x == 45 || x == 47 || x == 95 ){
                        Postfija->Insertar(Operadores.tcima());
                        Operadores.desapilar();
                        x = Operadores.tcima();

                    }
                    Operadores.apilar(s[i]);
                    break;
                //DIVISION
                case 47:
                    x = Operadores.tcima();
                    while(x == 45 || x == 47 || x == 95 ){
                        Postfija->Insertar(Operadores.tcima());
                        Operadores.desapilar();
                        x = Operadores.tcima();

                    }
                    Operadores.apilar(s[i]);
                    break;
                //POTRNCIA
                case 95:
                    x = Operadores.tcima();
                    while(x == 95 ){
                        Postfija->Insertar(Operadores.tcima());
                        Operadores.desapilar();
                        x = Operadores.tcima();

                    }
                    Operadores.apilar(s[i]);
                    break;
                case 41:
                    x = Operadores.tcima();
                    while(x == 42 || x == 43 || x == 45 || x == 47 || x == 95){
                        Postfija->Insertar(Operadores.tcima());
                        Operadores.desapilar();
                        x = Operadores.tcima();
                    }
                    if(x == 40){
                        Operadores.desapilar();
                    }

                    break;
            }

        }

    }

    while(!Operadores.vacia()){
        Postfija->Insertar(Operadores.tcima());
        Operadores.desapilar();
        x = Operadores.tcima();

    }
    return Postfija;

}

Pila<string>* PrefijoToPostfijo(string s){

    string s1,s2,espacio,aux;
    Pila<string>* Postfija;
    Postfija = new Pila<string>;
    espacio = " ";
    for(int i = s.length()-1;i >=0; i--){
        //cout<<espacio + s[i]<<endl;

        if(IsNumber(s[i])){
            aux = s[i] +espacio ;
            Postfija->apilar(aux);

        }else{
            if( (int)s[i] == 42 || (int)s[i] == 43 || (int)s[i] == 45 || (int)s[i] == 47 || (int)s[i] == 95 ){
                        s2 = Postfija->tcima();
                        Postfija->desapilar();
                        s1 = s2 + Postfija->tcima() + s[i];
                        //cout<<"s1"<<s1<<endl;
                        Postfija->desapilar();
                        Postfija->apilar(s1);


                    }

        }


    }
    return Postfija;

}


int main(){

    Lista* p;
    Pila<string>* q;
    string s; // = "((3+4)/5)*7";
    string c; // = "+2*34";
    cout<<"Escribe una operacion en notacion infija: ";
    cin>>s;
    p = InfijoToPostfijo(s);
    cout<<"Notacion Postfija: ";
    p->Imprimir();
    cout<<"Escribe una operacion en notacion prefija: ";
    cin>>c;
    q = PrefijoToPostfijo(c);
    cout<<"Notacion Postfija: ";
    q->Imprimir();

    delete p;
    delete q;

    return 0;
}