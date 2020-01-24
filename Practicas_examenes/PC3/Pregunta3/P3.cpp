#include <iostream>
#include <string>
#include <sstream>
#include "Pila.h"
#include "Cola.h"

using namespace std;

string Convert (float numero){
    ostringstream buff;
    buff<<numero;
    return buff.str();
}

/////////////////////////////////////////////

/////////////////////////////////////

class Calculadora{
    Pila<float> p;
    Pila<char> op;
    Cola<string> pantalla;
public:
    void Inicio();
};

void Calculadora::Inicio(){

    int opc;
    float r1;
    string s = "hola";

    do{

        cout<<"   CALCULADORA POLACA   "<<endl;
        cout<<"Introduce una operacion en notacion polaca:"<<endl;
        cout<<"------------------------------------------"<<endl;
        pantalla.Imprimir();
        cout<<"------------------------------------------"<<endl;
        cout<<endl;
        cout<<"1)Introducir un  numero."<<endl;
        cout<<"2)+"<<endl;
        cout<<"3)-"<<endl;
        cout<<"4)*"<<endl;
        cout<<"5)/"<<endl;
        cout<<"6)="<<endl;
        cout<<"0)Salir"<<endl;

        cin>>opc;
        
        switch(opc){
            case 1:
                cin>>r1;
                p.apilar(r1);
                pantalla.Encolar(Convert(r1));
                if(p.numElem() == 2){
                    switch (op.tcima()){ 
                        //SUMA                   
                        case 43:
                            r1 = p.tcima();
                            p.desapilar();
                            r1 = r1 + p.tcima();
                            p.desapilar();
                            p.apilar(r1);
                            op.desapilar();
                            break;
                        //RESTA
                        case 45:
                            r1 = p.tcima();
                            p.desapilar();
                            r1 = p.tcima() - r1;
                            p.desapilar();
                            p.apilar(r1);
                            op.desapilar();
                            break;
                        //MULTIPLICACION
                        case 42:
                            r1 = p.tcima();
                            p.desapilar();
                            r1 = p.tcima()*r1;
                            p.desapilar();
                            p.apilar(r1);
                            op.desapilar();
                            break;
                        //DIVISION
                        case 47:
                            r1 = p.tcima();
                            p.desapilar();
                            r1 = p.tcima()/r1;
                            p.desapilar();
                            p.apilar(r1);
                            op.desapilar();
                            break;
                        
                        default:
                            break;
                    }
                }
                break;
            case 2:
                op.apilar(43);
                pantalla.Encolar("+");
                break;
            case 3:
                op.apilar(45);
                pantalla.Encolar("-");
                break;
            case 4:
                op.apilar(42);
                pantalla.Encolar("*");
                break;
            case 5:
                op.apilar(47);
                pantalla.Encolar("/");
                break;
            case 6:
                cout<<"Resultado:";
                p.Imprimir();
                pantalla.Encolar(" = ");
                pantalla.Encolar(Convert(p.tcima()));
                cout<<endl;
                break;
        }
    }while(opc !=0);
}

int main(){
    Calculadora c;
    c.Inicio();
    return 0;
}