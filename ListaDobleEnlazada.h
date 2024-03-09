
#ifndef LISTADOBLEENLAZADA_H
#define LISTADOBLEENLAZADA_H
#include "Nodo.h"


template <class T>
class ListaDobleEnlazada {
    
    public:
        ListaDobleEnlazada();
        void agregarPrimero(T valor);
        void agregarUltimo(T valor);
        void agregar(int indice, T valor);
        T getPrimero();
        T getUltimo();
        T get(int indice);
        int indiceDe(T valor);
        void eliminarPrimero();
        void eliminarUltimo();
        void eliminiarConIndice(int indice);
        void eliminarValor(T valor);
        bool esVacia();
        void clear();
        int size();
        
        
    private:
        Nodo<T>* primero;
        Nodo<T>* ultimo;
        bool esVaciaLista();
        bool limiteDelArreglo(int indice);
        void eliminar(Nodo<T>* node); 

};
#endif 

