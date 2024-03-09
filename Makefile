all: practica1

practica1: main.o Carta.o ConstruirCarta.o ListaDobleEnlazada.o Nodo.o Pintar.o Cola.o Barajear.o Pila.o
	g++ -o practica1 main.o ConstruirCarta.o ListaDobleEnlazada.o Nodo.o Pintar.o Cola.o Barajear.o Pila.o
	
main.o: main.cpp Carta.h ConstruirCarta.h Barajear.h Cola.h Cola.cpp Pintar.h ConstruirCarta.cpp Barajear.cpp Pintar.cpp 
	g++ -c main.cpp

Nodo.o: Nodo.cpp Nodo.h
	g++ -c Nodo.cpp
	
Carta.o: Carta.cpp Carta.h
	g++ -c Carta.cpp
	
Pila.o: Pila.cpp Pila.h Nodo.h
	g++ -c Pila.cpp	
	
ListaDobleEnlazada.o: ListaDobleEnlazada.cpp ListaDobleEnlazada.h Nodo.h Nodo.cpp
	g++ -c ListaDobleEnlazada.cpp
	
Cola.o:  Cola.cpp Cola.h Nodo.h
	g++ -c Cola.cpp
	
ConstruirCarta.o: ConstruirCarta.cpp ConstruirCarta.h Carta.h ListaDobleEnlazada.cpp ListaDobleEnlazada.h
	g++ -c ConstruirCarta.cpp
	
	
Barajear.o: Barajear.cpp Barajear.h Carta.h Pila.cpp Pila.h Cola.h Cola.cpp ListaDobleEnlazada.h ListaDobleEnlazada.cpp
	g++ -c Barajear.cpp
	
Pintar.o: Pintar.cpp  Pintar.h Carta.h Pila.cpp Pila.h Cola.h Cola.cpp ListaDobleEnlazada.h ListaDobleEnlazada.cpp
	g++ -c Pintar.cpp
	


	
	
	
	
	
	
	
	
