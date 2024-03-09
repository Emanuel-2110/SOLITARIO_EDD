
#include "Carta.h"
#include <string>
using namespace std;

Carta::Carta(){}

Carta::Carta(string setValor, int tipo, string color, bool esconder){
    this->valor = setValor;
    this->tipo = tipo;
    this->color = color;
    this->esconder = esconder;
}

void Carta::setValor(string setValor){
    this->valor = setValor;
}

void Carta::setTipo(int tipo){
    this->tipo = tipo;
}

void Carta::setColor(string color){
    this->color = color;
}

void Carta::setEsconder(bool esconder){
    this->esconder = esconder;
}

string Carta::getValor(){
    return this->valor;
}

int Carta::getTipo(){
    return this->tipo;
}

string Carta::getColor(){
    return this->color;
}

bool Carta::esOculto(){
    return this->esconder;
}

Carta::~Carta(){
    
}

