

#ifndef QUEUE_H
#define QUEUE_H
#include "Nodo.h"
template <class T>
class Cola{
    
    public:
        Cola();
        void encolar(T value);
        T desencolar();
        T obtenerCima();
        bool esVacia();
        void clear();
    
    private:
        Nodo<T>* primero;
        Nodo<T>* ultimo;
        bool esColaVacia();
};

#endif 

