
#ifndef NODE_H
#define NODE_H
#include <iostream>
template <class T>
class Nodo{
    
    private:
        T valor;
        Nodo<T>* siguiente;
        Nodo<T>* anterior;
    
        public:
            Nodo();
            Nodo(T valor);
            void setValor(T valor);
            void setAnterior(Nodo<T>* anterior);
            void setSiguiente(Nodo<T>* siguiente);
            T getValor();
            Nodo<T>* getAnterior();
            Nodo<T>* getSiguiente();   
};
#endif 

