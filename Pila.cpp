
#include "Pila.h"
#include "Nodo.h"


template <typename T>
Pila<T>::Pila(){
    this->cima = NULL;
}


template <typename T>
void Pila<T>::apilar(T valor){
    Nodo<T>* nodo = new Nodo<T>(valor);
    nodo->setSiguiente(cima);
    cima = nodo;
}


template <typename T>
T Pila<T>::desapilar(){
    if(!this->estaVaciaLaPila()){
        Nodo<T>* nodo = this->cima;
        cima = nodo->getSiguiente();
        T valor = nodo->getValor();
        delete nodo;
        return valor;
    }
    return T(NULL);

}


template <typename T>
T Pila<T>::obtenerCima(){
    if(!this->estaVaciaLaPila()){
        return this->cima->getValor();
    }
    return T(NULL);
}


template <typename T>
bool Pila<T>::estaVacia(){
    return cima == NULL;
}


template <typename T>
void Pila<T>::clear(){
    Nodo<T>* nodo;
    while(!this->estaVacia()){
        nodo = this->cima;
        cima = cima->getSiguiente();
        delete nodo;    
    } 
}


template <typename T>
bool Pila<T>::estaVaciaLaPila(){
    if(this->estaVacia()){
        std::string msg = "Error: La pila se encuentra vacia"; 
        throw msg;
    }
    return false;
}
