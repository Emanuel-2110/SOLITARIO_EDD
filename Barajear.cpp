
#include "Barajear.h"
#include "ListaDobleEnlazada.cpp"
#include "Cola.cpp"
#include <iostream>

Barajear::Barajear(){}


void Barajear::barajearCartas(ListaDobleEnlazada<Carta*>* cartas){
    srand((unsigned)time(NULL)); 
    for(int i = 0; i < cartas->size() - 4; i++){
        this->aleatorio = rand()%51+0;
        carta = cartas->get(i);
        cartas->eliminiarConIndice(i);
        cartas->agregar(aleatorio, carta);
    }
    this->distribuirColas(cartas);
    this->distribuirPilas(cartas);
}


 
void Barajear::distribuirColas(ListaDobleEnlazada<Carta*>* cartas){
    for(int i = 0; i < 24; i++){
        cola->encolar(cartas->getPrimero());
            cartas->eliminarPrimero();
    }    
}


void Barajear::distribuirPilas(ListaDobleEnlazada<Carta*>* cartas){            
    //Creacion e insercion de las pilas principales.
    for(int i = 1; i < 8; i++){
        Pila<Carta*>* pila = new Pila<Carta*>;
        for(int j = 0; j < i; j++){
            pila->apilar(cartas->getPrimero());
            cartas->eliminarPrimero();
            if(j == 0){
                pila->obtenerCima()->setEsconder(false);
            }
        }
        pilaPrincipales->agregar(i-1, pila);
    }

    //Creacion e insercion de las pilas secundarias.
    for(int i = 0; i < 4; i++){
        Pila<Carta*>* pila = new Pila<Carta*>;
        pila->apilar(cartas->getUltimo());
        cartas->eliminarUltimo();
        pilaSecundarias->agregarPrimero(pila);
    }
}

ListaDobleEnlazada<Pila<Carta*>*>* Barajear::obtenerPilasPrincipales(){
    return this->pilaPrincipales;
}

ListaDobleEnlazada<Pila<Carta*>*>* Barajear::obtenerPilasSecundarias(){
    return this->pilaSecundarias;
}

Cola<Carta*>* Barajear::obtenerCola(){
    return this->cola;
}
 