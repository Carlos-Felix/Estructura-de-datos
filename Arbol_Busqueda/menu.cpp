#include <iostream>
#include "menu.h"

Menu::Menu(){
    
    abb = new arbol;
    abb->insertarNodo(30);
    abb->insertarNodo(40);
    abb->insertarNodo(10);
    abb->insertarNodo(50);
    abb->insertarNodo(30);
    abb->insertarNodo(200);
    abb->insertarNodo(100);
    abb->insertarNodo(5);
    
}
void Menu::prensentarMenu(){
    while(op != 0){
        std::cout << std::endl;
        std::cout << "---------MENU---------" << std::endl;
        std::cout << std::endl;
        std::cout << "1) Ingresar Elemento" << std::endl;
        std::cout << "2) Encontrar elemento" << std::endl;
        std::cout << "3) Encontar Mayor" << std::endl;
        std::cout << "4) Encontrar Menor" << std::endl;
        std::cout << "5) Elminar elemento" << std::endl;
        std::cout << "6) Imprimir en orden" << std::endl;
        std::cout << "7) Imprimir Pre orden" << std::endl;
        std::cout << "8) Imprimir Post orden" << std::endl;
        std::cout << "9) Profundidad de nodo" << std::endl;
        std::cout << "10) Padre mas joven" << std::endl;
        std::cout << "0) Salir" << std::endl;
        std::cin >> op;
    
        switch (op)
        {
        case 1:
            std::cout << "Ingrese elemeto: ";
            std::cin >>  aux;
            abb->insertarNodo(aux);
            break;
        case 2:
            std::cout << "Ingrese a encontrar: ";
            std::cin >>  aux;
            aux2 = abb->encontrarElemento(aux);
            break;
        case 3:
            if(abb->encontrarMayor(abb->getRaiz()) == NULL ) std::cout << "arbol vacío" << std::endl;
            else std::cout << "Elmento mayor: " << abb->encontrarMayor(abb->getRaiz())->dato << std::endl;
            break;
        case 4:
            if(abb->encontrarMenor(abb->getRaiz()) == NULL ) std::cout << "arbol vacío" << std::endl;
            else std::cout << "Elmento menor: " << abb->encontrarMenor(abb->getRaiz())->dato << std::endl;
            break;
        case 5:
            std::cout << "Ingrese a eliminar: ";
            std::cin >>  aux;
            abb->eliminarElemento(aux);
            break;
        case 6:
            abb->imprimirOrden(abb->getRaiz());
            break;
        case 7:
            abb->imprimirPreorden(abb->getRaiz());
            break;
        case 8:
            abb->imprimirPostorden(abb->getRaiz());
            break;
        case 9:
            std::cout << "Ingrese un elemento: ";
            std::cin >>  aux;
            std::cout << "La profundidad es: " << abb->profunNodo(aux);
            break;
        case 10:
            std::cout << "Ingrese x e y: ";
            std::cin >>  aux >> aux3;
            
            std::cout << "El padre es " << abb->padreMasJoven(aux,aux3);
            break;
        
        default:
            break;
        }
    }
}
arbol* Menu::getArbol(){
    return abb;
}
