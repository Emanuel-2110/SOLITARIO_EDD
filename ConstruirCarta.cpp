
#include "ConstruirCarta.h"
#include <string>

ConstruirCarta::ConstruirCarta() {
}


ListaDobleEnlazada<Carta*>* ConstruirCarta:: crearCartas(){
    actualColor = colores[0];
    for(int i = 1; i < 5; i++){
        if(i == 3){
            actualColor = colores[1];
        }
        for(int j = 0; j < 13; j++){
            Carta* carta = new Carta(valorCartas[j], i, actualColor, true);
            todasLasCartas->agregarPrimero(carta); 
        }   
    }
    
    actualColor = colores[0];
    for(int i = 1; i < 5; i++){
        if(i == 3){
            actualColor = colores[1];
        }
        Carta* carta = new Carta(valorCartas[i-1], i, actualColor, false);
        todasLasCartas->agregarUltimo(carta); 
    }
    return this->todasLasCartas;
}

