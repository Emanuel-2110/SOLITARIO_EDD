
#ifndef Barajear_H
#define Barajear_H
#include <string>
#include "Carta.h"
#include "Pila.h"
#include "Pila.cpp"
#include "Cola.h"
#include "ListaDobleEnlazada.h"
using namespace std;

class Barajear {
    
    public:
        Barajear();
        void barajearCartas(ListaDobleEnlazada<Carta*>* cartas);
        void distribuirColas(ListaDobleEnlazada<Carta*>* cartas);
        void distribuirPilas(ListaDobleEnlazada<Carta*>* cartas);
        Cola<Carta*>* obtenerCola();
        ListaDobleEnlazada<Pila<Carta*>*>* obtenerPilasPrincipales();
        ListaDobleEnlazada<Pila<Carta*>*>* obtenerPilasSecundarias();

    private:
        Carta* carta;
        int aleatorio;
        ListaDobleEnlazada<Pila<Carta*>*>* pilaPrincipales = new ListaDobleEnlazada<Pila<Carta*>*>;
        ListaDobleEnlazada<Pila<Carta*>*>* pilaSecundarias = new ListaDobleEnlazada<Pila<Carta*>*>;
        Cola<Carta*>* cola = new Cola<Carta*>;
};
#endif /* Barajear_H */

