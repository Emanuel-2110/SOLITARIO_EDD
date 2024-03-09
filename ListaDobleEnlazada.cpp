
#include "ListaDobleEnlazada.h"
#include <string>
#include <iostream>
#include "Nodo.h"
#include "Nodo.cpp"
using namespace std;


template <typename T>
ListaDobleEnlazada<T>::ListaDobleEnlazada(){
    this->primero = NULL;
    this->ultimo = NULL;
}

template <typename T>
void ListaDobleEnlazada<T>::agregarPrimero(T valor){
    Nodo<T>* nodo = new Nodo<T>(valor);   
    if(this->esVacia()){
        this->primero = nodo;
        this->ultimo = nodo;
    }
    else{
        nodo->setSiguiente(this->primero);
        this->primero->setAnterior(nodo);
        this->primero = nodo;
    }
} 


template <typename T>
void ListaDobleEnlazada<T>::agregarUltimo(T valor){
    Nodo<T>* nodo = new Nodo<T>(valor);   
    if(this->esVacia()){
        primero = nodo;
        ultimo = nodo;
    }
    else{
        nodo->setAnterior(this->ultimo);
        this->ultimo->setSiguiente(nodo);
        ultimo = nodo;
    }
} 

template <typename T>
void ListaDobleEnlazada<T>::agregar(int indice, T valor){
    if(indice == this->size()){
        this->agregarUltimo(valor);
    }
    else{
        if(!this->esVaciaLista()){
            if(!this->limiteDelArreglo(indice)){
                int actualindice = 0;
                for(Nodo<T>* actualNodo = this->primero; actualNodo != NULL; actualNodo = actualNodo->getSiguiente()){
                    if(actualindice == indice){  
                        if(actualNodo == this->primero){
                            this->agregarPrimero(valor);
                            break;
                        }
                        else{ 
                            Nodo<T>* nuevoNodo = new Nodo<T>(valor);
                            actualNodo->getAnterior()->setSiguiente(nuevoNodo);
                            nuevoNodo->setAnterior(actualNodo->getAnterior());
                            nuevoNodo->setSiguiente(actualNodo);
                            actualNodo->setAnterior(nuevoNodo);
                            break;
                        }
                    }
                    actualindice++;
                }
            }
        }
    }
}


template <typename T>
T ListaDobleEnlazada<T>::getPrimero(){
    if(!this->esVaciaLista()){
        return this->primero->getValor();
    }
    return T(NULL);
}


template <typename T>
T ListaDobleEnlazada<T>::getUltimo(){
    if(!this->esVaciaLista()){
        return this->ultimo->getValor();
    }
    return T(NULL);
}


template <typename T>
T ListaDobleEnlazada<T>::get(int indice){
    if(!this->esVaciaLista()){
        if(!this->limiteDelArreglo(indice)){
            int actualindice = 0;
            for(Nodo<T>* nodo = this->primero; nodo != NULL; nodo = nodo->getSiguiente()){
                if(indice == actualindice){
                    return nodo->getValor();
                }
                actualindice++;
            }
        }      
    }
    return T(NULL);
}


template <typename T>
int ListaDobleEnlazada<T>::indiceDe(T valor){
    if(!this->esVaciaLista()){
        int indice = 0;
        for(Nodo<T>* nodo = this->primero; nodo != NULL; nodo = nodo->getSiguiente()){
            if(nodo->getValor() == valor){
                return indice;
            }
            indice++;
        }
    }
    return -1;
}    

template <typename T>
void ListaDobleEnlazada<T>::eliminarPrimero(){
    if(!this->esVaciaLista()){
        Nodo<T>* nodo = this->primero;
        if(this->primero == this->ultimo){
            this->primero = NULL;
            this->ultimo = NULL;
        }
        else{
            this->primero = nodo->getSiguiente();
            nodo->getSiguiente()->setAnterior(NULL);
        }
        delete nodo;
    }
} 


template <typename T>
void ListaDobleEnlazada<T>::eliminarUltimo(){
    if(!this->esVaciaLista()){
        Nodo<T>* nodo = this->ultimo;
        if(this->primero == this->ultimo){
            this->primero = NULL;
            this->ultimo = NULL;
        }
        else{
            this->ultimo = nodo->getAnterior();
            nodo->getAnterior()->setSiguiente(NULL);
        }
        delete nodo;
    }
} 


template <typename T>
void ListaDobleEnlazada<T>::eliminiarConIndice(int indice){
    if(!this->esVaciaLista()){
        if(!this->limiteDelArreglo(indice)){
            int actualindice = 0;
            for(Nodo<T>* nodo = this->primero; nodo != NULL; nodo = nodo->getSiguiente()){
                if(actualindice == indice){
                    this->eliminar(nodo);
                    break;
                }   
            actualindice++;
            }
        }
    }
}


template <typename T>
void ListaDobleEnlazada<T>::eliminarValor(T valor){
    if(!this->esVaciaLista()){
        for(Nodo<T>* nodo = this->primero; nodo != NULL; nodo = nodo->getSiguiente()){
            if(nodo->getValor() == valor){
                this->eliminar(nodo);
                break;
            }   
        }
    }   
}


template <typename T>
bool ListaDobleEnlazada<T>::esVacia(){
    return this->primero == NULL && ultimo == NULL;
}

template <typename T>
void ListaDobleEnlazada<T>::clear(){
    if(!this->esVacia()){
        int length = this->size();
        for(int i =0; i < length; i++){
            this->eliminarPrimero();
        }
    }
}


template<typename T>
int ListaDobleEnlazada<T>::size(){
    if(this->esVacia()){
        return 0;
    }
    else{
        int size = 1;
        for(Nodo<T>* nodo = this->primero; nodo != ultimo; nodo = nodo->getSiguiente()){
            size++;
        }
        return size;
    }
}


template <typename T>
bool ListaDobleEnlazada<T>::esVaciaLista(){
    if(this->esVacia()){
        string msg = "La lista se encuentra vacia";
        throw msg;
    }
    return false;    
}


template <typename T>
bool ListaDobleEnlazada<T>::limiteDelArreglo(int indice){
    if(indice >= this->size() || indice < 0){
        string msg = "El indice se encuentra fuera de los limites";
        throw  msg;
    }
    return false;    
}


template <typename T>
void ListaDobleEnlazada<T>::eliminar(Nodo<T>* nodo){
    if(nodo == this->primero){
        this->eliminarPrimero();
    }
    else if(nodo == this->ultimo){
        this->eliminarUltimo();
    }
    else{
        nodo->getAnterior()->setSiguiente(nodo->getSiguiente());
        nodo->getSiguiente()->setAnterior(nodo->getAnterior()); 
        delete nodo;
    }
}
