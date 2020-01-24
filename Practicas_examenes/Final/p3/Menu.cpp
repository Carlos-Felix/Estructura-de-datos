#include "Menu.h"

Menu::Menu(){
    op = -1;
    g = new Grafo;
    /*
    g->insertarVertice(5);
    g->insertarVertice(9);
    g->insertarVertice(4);
    g->insertarVertice(15);
    g->insertarVertice(25);
    g->insertarVertice(45);
    g->insertarVertice(10);
    
    g->insertarArista(5,15,2);
    g->insertarArista(5,25,4);
    g->insertarArista(5,5,5);
    g->insertarArista(5,4,3);
    g->insertarArista(5,5,2);

    g->insertarArista(9,25,4);
    g->insertarArista(9,45,5);
    g->insertarArista(9,45,7);
    g->insertarArista(25,9,4);
    
    //g->insertarArista(5,9,2);
    //g->insertarArista(9,4,3);
    
    g->insertarVertice(1);
    g->insertarVertice(2);
    g->insertarVertice(3);
    g->insertarVertice(4);
    g->insertarVertice(5);

    

    g->insertarArista(1,4,5);
    g->insertarArista(4,1,5);
    g->insertarArista(1,2,2);
    g->insertarArista(2,1,2);
    g->insertarArista(2,3,1);
    g->insertarArista(3,2,1);
    g->insertarArista(2,4,3);
    g->insertarArista(4,2,3);
    g->insertarArista(3,4,1);
    g->insertarArista(4,3,1);

    g->insertarArista(3,5,9);
    g->insertarArista(5,3,9);
    g->insertarArista(4,5,2);
    g->insertarArista(5,4,2);
    */
    g->insertarVertice(1);
    g->insertarVertice(2);
    g->insertarVertice(3);
    

    g->insertarArista(1,3,5);
    g->insertarArista(1,2,7);
    g->insertarArista(2,3,1);

    cout << "funcion: " << endl;
    //g->longestPath(3,5);
    //g->menorCamino(1,6);
    //cout << "Inserte: ";
    //int au1,au2,au3;
    //cin >>  au1 >> au2 >> au3; 
    cout << "ans:" <<g->existeCaminoDist(1,3,2);
    
}

int Menu::mostrarMenu(){
    int x;
    //std::system("clear");
    cout << endl;
    cout << "-----MENU-----"<< endl;
    cout << "1) Insertar vertice" << endl;
    cout << "2) Insertar arista" << endl;
    cout << "3) Imprimir grafo" << endl;
    cout << "4) Eliminar arista" << endl;
    cout << "5) Eliminar toda arista" << endl;
    cout << "6) Eliminar vertice" << endl;
    cout << "7) Eliminar todo vertice" << endl;
    cout << "8) Camino más corto" << endl;
    cout << "0) Salir" << endl;
    cin >> x;

    return x;

}

void Menu::presentarMenu(){
    while (op != 0){

        op = mostrarMenu();
        switch (op){
            case 1:
                cout << "Ingrese el vertice: ";
                cin >> bf;
                g->insertarVertice(bf);
                break;
            case 2:
                cout << "Ingrese el vertice,arista y peso:";
                cin >> bf >> bf2 >> bf3;
                g->insertarArista(bf,bf2,bf3);
                break;
            case 3:
                g->imprimirGrafo();
                break;
            case 4:
                cout << "Ingrese el vertice y arista: ";
                cin >> bf >> bf2;
                g->eliminarArista(bf,bf2);
                break;
            case 5:
                cout << "Ingrese el vertice: ";
                cin >> bf;
                g->eliminarTodaArista(bf);
                break;
            case 6:
                cout << "Ingrese el vertice: ";
                cin >> bf;
                g->eliminarVertice(bf);
                break;
            case 7:
                g->eliminarTodoVertice();
                break;
            case 8:
                cout << "Ingrese el inicio y final: ";
                cin >> bf >> bf2;
                g->menorCamino(bf,bf2);
                break;
            
            default:
                break;
        }
    }
}

Menu::~Menu(){
}