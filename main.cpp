
#include <memory>
#include "Pintar.h"
#include "Carta.h"
#include "ConstruirCarta.h"
#include "Barajear.h"
#include "Cola.h"
#include "Cola.cpp"


using namespace std;

ConstruirCarta creador;
Barajear baraja;
Pintar pintar;

ListaDobleEnlazada<Carta*>* cartas = new ListaDobleEnlazada<Carta*>;
Cola<Carta*>* cola;
Pila<Carta*>* pila = new Pila<Carta*>;
ListaDobleEnlazada<Pila<Carta*>*>* pilasPrincipales;
ListaDobleEnlazada<Pila<Carta*>*>* pilasSecundarias;
bool finJuego = false;
int opcion;
int fila;
int columna;
int filaObjetivo;
int columnaObjetivo;


int main(){
    //Creamos todas las cartas y las mandamos a barajear.
    cartas = creador.crearCartas();
    baraja.barajearCartas(cartas);
    delete cartas;
    
    //Obtenemos las cartas organizadas dentro de sus respectivas estructuras.
    cola = baraja.obtenerCola();
    pilasPrincipales = baraja.obtenerPilasPrincipales();
    pilasSecundarias = baraja.obtenerPilasSecundarias();
       
    //Enviamos a imprimir la configuracion inicial.
    pintar.pinta(cola, pila, pilasPrincipales, pilasSecundarias);

    try{
        // menu del juego.
        while(opcion != 5){
            cout<< "\nJUEGO" <<endl;
            cout<< "1. Sacar carta de Baraja." <<endl;
            cout<< "2. Mover carta de la baraja al tablero" <<endl;
            cout<< "3. Mover Carta en el tablero." <<endl;  
            cout<< "4. Mover carta del tablero a la pila." <<endl;
            cout<< "5.Salir." <<endl;
            cout<< "Elige una Opcion" <<endl;
            cin >> opcion;
            switch(opcion){
                case 1:
                    pintar.pinta(cola, pila, pilasPrincipales, pilasSecundarias);
                break;
                case 2:
                    cout<<"Ingrese la columna destino: ";
                    cin >> columnaObjetivo; 
                        pintar.pinta(cola, pila, pilasPrincipales, pilasSecundarias);
                    
                break;
                case 3:
                    cout<<"Ingrese la columna origen: ";
                    cin >> columna;  
                    cout<<"Ingrese la columna destino: ";
                    cin >> columnaObjetivo; 
                    cout<<endl;
                    
                    pintar.pinta(cola, pila, pilasPrincipales, pilasSecundarias);
                    
                break;
                case 4:
                    cout<<"Ingrese la columna origen: ";
                    cin >> columna;  
                   
                     pintar.pinta(cola, pila, pilasPrincipales, pilasSecundarias);
                       
                break;
                case 5:
                    cout<<"SALIENDO DEL JUEGO" <<endl;
                break;
                default:
                    pintar.pinta(cola, pila, pilasPrincipales, pilasSecundarias);
                    cout<<"Opcion no valida" <<endl;
                break;     
            }
        }
    }
    catch(string e){
        cout<<e<<endl;
    }
    return 0;
}

