// Lab7B33733.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lista.h"
#include "ElementoInt.h"


int _tmain(int argc, _TCHAR* argv[]) {
	srand((unsigned int)time(NULL));

	int cantidadElementos = rand() % 41 + 15; // Setea cantidad de Elementos de la Lista en un valor aleatorio entre 15 y 50.
	Lista enteros;
	for (int i = 0; i < cantidadElementos; i++){
		Elemento * nodo = new ElementoInt(rand() % 100);

		int cualInsercion = rand() % 3;

		if (cualInsercion == 0){ // Elige de manera aleatoria si incertar en la cabeza, en una posicion o en la cola.
			enteros.insertarCabeza(nodo);
		}
		else if (cualInsercion == 1){
			enteros.insertarElemento(nodo, rand() % (enteros.getSize() + 1)); // Incerta en una posicion aleatoria entre 0 y el tamaño de la lista.
		}
		else {
			enteros.insertarCola(nodo);
		}
	}

	cout << "Lista de enteros:" << endl;
	cout << enteros << endl;

	for (int i = 0; i < 10; i++){
		int cualRemocion = rand() % 3;

		if (cualRemocion == 0){ // Elige de manera aleatoria si remover la cabeza, una posicion o la cola.
			enteros.removerCabeza();
		}
		else if (cualRemocion == 1){
			enteros.removerElemento(rand() % (enteros.getSize() + 1)); // Renueve en una posicion aleatoria entre 0 y el tamaño de la lista.
		}
		else {
			enteros.removerCola();
		}
	}

	cout << "Lista de enteros con 10 remociones aleatorias:" << endl;
	cout << enteros << endl;

	int donde = enteros.buscarPorElemento(new ElementoInt(22));
	cout << "hay un 22 en la posicion:" << donde << endl;
	Elemento * elemento = enteros.buscarPorPosicion(donde);
	cout << "en la posicion " << donde << " hay un: " << *elemento << endl;
	cout << "el tamaño de la lista es de: " << enteros.getSize() << endl;

	return 0;
}

