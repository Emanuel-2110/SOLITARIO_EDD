
#ifndef CONSTRUIRCARTA_H
#define CONSTRUIRCARTA_H
#include <string>
#include "Carta.h"
#include "ListaDobleEnlazada.h"
#include "ListaDobleEnlazada.cpp"
using namespace std;

class ConstruirCarta {
    public:
        ConstruirCarta();
        ListaDobleEnlazada<Carta*>* crearCartas();
        
    private:
        string createImage(int type, string value);
        string colores[2] = {"Rojo", "Negro"};
        string actualColor;
        string valorCartas[13] = {"K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2", "A"};
        string tipoCartas[4] = {"<3", "<>", "E3", "!!"};
        ListaDobleEnlazada<Carta*>* todasLasCartas = new ListaDobleEnlazada<Carta*>;  
        string  tipo;
        string color;
        string cardImage;
        string endColor ="\x1B[00m";
};
#endif 