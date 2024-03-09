
#include "Cola.h"
#include "Nodo.h"
#include <string>
using namespace std;

template <typename T>
Cola<T>::Cola(){
    this->primero = NULL;
    this->ultimo = NULL;
}


template <typename T>
void Cola<T>::encolar(T valor){
    Nodo<T>* nodo = new Nodo<T>(valor);
    if(this->esVacia()){
        this->primero = nodo;
    }
    else{
        ultimo->setAnterior(nodo);
    }
    this->ultimo = nodo;
}

template <typename T>
T Cola<T>::desencolar(){
    if(!this->esColaVacia()){
        Nodo<T>* nodo = this->primero;
        primero = nodo->getSiguiente();
        T valor = nodo->getValor();
        delete nodo;
        return valor;
    }
    return T(NULL);
}


template <typename T>
T Cola<T>::obtenerCima() {
    if(!this->esColaVacia()){
        return primero->getValor();
    }
    return T(NULL);
}


template <typename T>
bool Cola<T>::esVacia(){
    return this->primero == NULL;
}


template <typename T>
void Cola<T>::clear(){
    Nodo<T>* nodo;
    while(!this->esVacia()){
        nodo = this->primero;
        primero = primero->getSiguiente();
        delete nodo; 
    }
    return T(NULL);
}


template <typename T>
bool Cola<T>::esColaVacia(){
    if(this->esVacia()){
        string msg = "Error: La cola se encuentra vacia"; 
        throw msg;
    }
    return false;
}
