
#ifndef STACK_HPP
#define STACK_HPP
#include "Nodo.h"

template <class T> 
class Pila {

    public:
        Pila();
        void apilar(T valor);
        T desapilar();
        T obtenerCima();
        bool estaVacia();
        void clear();
        
    private:
        Nodo<T>* cima;
        bool estaVaciaLaPila();
};
#endif /*  */

