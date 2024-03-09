
#include "Pintar.h"
#include "ListaDobleEnlazada.cpp"
#include "Cola.cpp"
#include "Pila.cpp"

Pintar::Pintar(){}

void Pintar::pinta(Cola<Carta*>* cola, Pila<Carta*>* pila, ListaDobleEnlazada<Pila<Carta*>*>* pilasPrincipales, ListaDobleEnlazada<Pila<Carta*>*>* pilasSecundarias){
    this->pintaColasYpilasSecundarias(cola, pila, pilasSecundarias);
    this->pintaPrincipalpilas(pilasPrincipales);
    for(int i = 0; i < 7; i++){
        switch(i){
            case 0:
                pila = pila1;
                auxiliarPila = auxiliarPila1;
            break;
            case 1:
                pila = pila2;
                auxiliarPila = auxiliarPila2;
            break;
            case 2:
                pila = pila3;
                auxiliarPila = auxiliarPila3;
            break;
            case 3:
                pila = pila4;
                auxiliarPila = auxiliarPila4;
            break;
            case 4:
                pila = pila5;
                auxiliarPila = auxiliarPila5;
            break;
            case 5:
                pila = pila6;
                auxiliarPila = auxiliarPila6;
            break;
            case 6:
                pila = pila7;
                auxiliarPila = auxiliarPila7;
            break;
        }
        while(!auxiliarPila->estaVacia()){
            pila->apilar(auxiliarPila->desapilar());
        }  
    }
}

void Pintar::pintaPrincipalpilas(ListaDobleEnlazada<Pila<Carta*>*>* pilasPrincipales){
    string image;
    int row = 1;
    pila1 = pilasPrincipales->get(0);
    pila2 = pilasPrincipales->get(1);
    pila3 = pilasPrincipales->get(2);
    pila4 = pilasPrincipales->get(3);
    pila5 = pilasPrincipales->get(4);
    pila6 = pilasPrincipales->get(5);
    pila7 = pilasPrincipales->get(6);
    while(!pila1->estaVacia() || !pila2->estaVacia() || !pila3->estaVacia() || !pila4->estaVacia() || !pila5->estaVacia() || !pila5->estaVacia() || !pila7->estaVacia()){ 
       for(int i = 1; i < 6; i++){ 
            for(int j = 0; j < 7; j++){
                switch(j){
                    case 0:
                        pila = pila1;
                        auxiliarPila = auxiliarPila1;
                    break;
                    case 1:
                        pila = pila2;
                        auxiliarPila = auxiliarPila2;
                    break;
                    case 2:
                        pila = pila3;
                        auxiliarPila = auxiliarPila3;
                    break;
                    case 3:
                        pila = pila4;
                        auxiliarPila = auxiliarPila4;
                    break;
                    case 4:
                        pila = pila5;
                        auxiliarPila = auxiliarPila5;
                    break;
                    case 5:
                        pila = pila6;
                        auxiliarPila = auxiliarPila6;
                    break;
                    case 6:
                        pila = pila7;
                        auxiliarPila = auxiliarPila7;
                    break;
                }
                         
                if(!pila->estaVacia()){
                    if(pila->obtenerCima()->esOculto()){
                        image = image + " " + this->createImage(i, 0, "+");
                    }
                    else{
                        card = pila->obtenerCima();
                        image = image + " " + this->createImage(i, card->getTipo(), card->getValor());
                    }
                    if(i == 5){
                        card = pila->desapilar();
                        auxiliarPila->apilar(card);
                    }
                }
                else{
                    image = image + "        ";
                }
            }
           
            if(i == 4){
                image = image + "  " + std::to_string(row) +  "\n";
                row++;
            }
            else{
               image = image + "\n";
            }     
        }         
    }
    std::cout<<image <<"\n\n";
}


 
void Pintar::pintaColasYpilasSecundarias(Cola<Carta*>* cola, Pila<Carta*>* pila, ListaDobleEnlazada<Pila<Carta*>*>* pilasSecundarias){
    string img = "    1       2      3       4       5       6       7   \n";
    for(int i = 1; i < 6; i++){
        //Colas.
        for(int j = 0; j < 2; j++){
            
            if(j == 0){
                if(cola->esVacia()){
                    Carta* card = new Carta(" ", 0, " ", true);
                    this->card = card;
                }
                else{
                    if(cola->obtenerCima()->esOculto()){
                        Carta* card = new Carta("+", 0, " ", true);
                        this->card = card;
                    }
                    else{
                        card = cola->obtenerCima();
                    }  
                }
            }
            else{
                if(pila->estaVacia()){
                    Carta* card = new Carta(" ", 0, " ", true);
                    this->card = card;
                }
                else{
                    if(pila->obtenerCima()->esOculto()){
                        Carta* card = new Carta("+", 0, " ", true);
                        this->card = card;
                    }
                    else{
                        card = pila->obtenerCima();
                    }
                }
            }
            img = img + " " + this->createImage(i, card->getTipo(), card->getValor());
        }
        img = img + "       ";
        
        
        //Pilas secundarias.
        for(int j = 0; j < pilasSecundarias->size(); j++){
            card = pilasSecundarias->get(j)->obtenerCima();
            img = img + " " + this->createImage(i, card->getTipo(), card->getValor());
        }
        if(i == 4){
            img = img + "  0\n";
        }
        else{
            img = img + "\n";
        }
    }
    std::cout<<img <<"\n \n";
}

string Pintar::createImage(int part, int type, string valor){
    string img;
    switch (type){
        case 0:
            this->type = "  ";
            this->color = "\x1B[30m";
        break;
        case 1:
            this->type = "<3";
            this->color = "\x1B[31m";
        break;
        case 2:
            this->type = "<>";
            this->color = "\x1B[31m";
        break;
        case 3:
            this->type = "E3";
            this->color = "\x1B[30m";
        break;
        case 4:
            this->type = "!!";
            this->color = "\x1B[30m";
        break;
    }
    switch(part){
        case 1:
            img = color + " _____ " + endColor;
        break;
        case 2:
            img = color + "|"+this->type+"   |" + endColor;
        break;
        case 3:
            img = color + "|     |" + endColor;
        break;
        case 4:
            if(valor.compare("10") == 0 || valor.compare("<3") == 0 || valor.compare("<>") == 0 || valor.compare("E3") == 0 ||valor.compare("!!") == 0){
                img = color + "| "+valor+"  |" + endColor;
            }
            else{
                img = color + "|  "+valor+"  |" + endColor;
            }
        break;
        case 5:
            img = color + "|_____|" + endColor;
        break;
            
    }
    return img;
}   