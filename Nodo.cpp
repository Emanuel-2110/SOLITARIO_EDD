

#include "Nodo.h"
#include <iostream>


template <typename T>
Nodo<T>::Nodo(){
    this->valor = NULL;
    this->anterior = NULL;
    this->siguiente = NULL;
}

template <typename T>
Nodo<T>::Nodo(T valor){
    this->valor = valor;
    this->anterior = NULL;
    this->siguiente = NULL;
}

template <typename T>
void Nodo<T>::setValor(T valor){
    this->valor = valor;
}

template <typename T>
void Nodo<T>::setAnterior(Nodo<T>* anterior){
    this->anterior = anterior;
}

template <typename T>
void Nodo<T>::setSiguiente(Nodo<T>* siguiente){
    this->siguiente = siguiente;
}


template <typename T>
T Nodo<T>::getValor(){
    return this->valor;
}

template <typename T>
Nodo<T>* Nodo<T>::getAnterior(){
    return this->anterior;
}

template <typename T>
Nodo<T>* Nodo<T>::getSiguiente(){
    return this->siguiente;
}
