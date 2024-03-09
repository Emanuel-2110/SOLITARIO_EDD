

#ifndef Pintar_HPP
#define Pintar_HPP
#include "Carta.h"
#include "Cola.h"
#include "Pila.h"
#include "ListaDobleEnlazada.h"
using namespace std;

class Pintar {
    public:
        Pintar();
        void pinta(Cola<Carta*>* cola, Pila<Carta*>* pila, ListaDobleEnlazada<Pila<Carta*>*>* principalpilas, ListaDobleEnlazada<Pila<Carta*>*>* pilasSecundarias);
       
    private:
        void pintaColasYpilasSecundarias(Cola<Carta*>* cola, Pila<Carta*>* pila, ListaDobleEnlazada<Pila<Carta*>*>* pilasSecundarias);
        void pintaPrincipalpilas( ListaDobleEnlazada<Pila<Carta*>*>* principalpilas);
        string createImage(int part, int type, string value);
        string type;
        string color;
        string endColor ="\x1B[0m";
        Carta* card;       
        Pila<Carta*>* pila = new Pila<Carta*>;;
        Pila<Carta*>* pila1 = new Pila<Carta*>;;
        Pila<Carta*>* pila2 = new Pila<Carta*>;;
        Pila<Carta*>* pila3 = new Pila<Carta*>;;
        Pila<Carta*>* pila4 = new Pila<Carta*>;;
        Pila<Carta*>* pila5 = new Pila<Carta*>;;
        Pila<Carta*>* pila6 = new Pila<Carta*>;;
        Pila<Carta*>* pila7 = new Pila<Carta*>;;
        Pila<Carta*>* auxiliarPila = new Pila<Carta*>;
        Pila<Carta*>* auxiliarPila1 = new Pila<Carta*>;;
        Pila<Carta*>* auxiliarPila2 = new Pila<Carta*>;;
        Pila<Carta*>* auxiliarPila3 = new Pila<Carta*>;;
        Pila<Carta*>* auxiliarPila4 = new Pila<Carta*>;;
        Pila<Carta*>* auxiliarPila5 = new Pila<Carta*>;;
        Pila<Carta*>* auxiliarPila6 = new Pila<Carta*>;;
        Pila<Carta*>* auxiliarPila7 = new Pila<Carta*>;;
        Cola<Carta*>* auxiliarCola = new Cola<Carta*>;;
};
#endif /* Pintar_H */

