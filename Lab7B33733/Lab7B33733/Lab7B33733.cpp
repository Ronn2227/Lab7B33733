// Lab7B33733.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lista.h"


int _tmain(int argc, _TCHAR* argv[]) {
	srand((unsigned int)time(NULL));

	int cantidadElementos = rand() % 41 + 15; // Setea cantidad de Elementos de la Lista en un valor aleatorio entre 15 y 50.
	Lista<int> enteros;
	for (int i = 0; i < cantidadElementos; i++){
		//Elemento * nodo = new ElementoInt(rand() % 100);

		int cualInsercion = rand() % 3;

		if (cualInsercion == 0){ // Elige de manera aleatoria si incertar en la cabeza, en una posicion o en la cola.
			enteros.insertarCabeza(rand() % 100);
		}
		else if (cualInsercion == 1){
			enteros.insertarNodo(rand() % 100, rand() % (enteros.getSize() + 1)); // Incerta en una posicion aleatoria entre 0 y el tamaño de la lista.
		}
		else {
			enteros.insertarCola(rand() % 100);
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
			enteros.removerNodo(rand() % (enteros.getSize() + 1)); // Renueve en una posicion aleatoria entre 0 y el tamaño de la lista.
		}
		else {
			enteros.removerCola();
		}
	}

	cout << "Lista de enteros con 10 remociones aleatorias:" << endl;
	cout << enteros << endl;

	int donde = enteros.buscarPorNodo(22);
	cout << "hay un 22 en la posicion:" << donde << endl;
	Nodo<int> * elemento = enteros.buscarPorPosicion(donde);
	cout << "en la posicion " << donde << " hay un: " << *elemento << endl;
	elemento = enteros.buscarPorPosicion(2);
	cout << "en la posicion " << 2 << " hay un: " << *elemento << endl;
	elemento = enteros.buscarPorPosicion(enteros.getSize()-3);
	cout << "en la posicion " << enteros.getSize() - 3 << " hay un: " << *elemento << endl;
	
	cout << "el tamaño de la lista es de: " << enteros.getSize() << endl;

	cantidadElementos = rand() % 41 + 15; // Setea cantidad de Elementos de la Lista en un valor aleatorio entre 15 y 50.
	Lista<double> doubles;
	for (int i = 0; i < cantidadElementos; i++){
		double d = (double)rand() * 100 / (double)RAND_MAX; // Genera double aleatorio entre 0 y 100.
		int cualInsercion = rand() % 3;

		if (cualInsercion == 0){ // Elige de manera aleatoria si incertar en la cabeza, en una posicion o en la cola.
			doubles.insertarCabeza(d);
		}
		else if (cualInsercion == 1){
			doubles.insertarNodo(d, rand() % (doubles.getSize() + 1)); // Incerta en una posicion aleatoria entre 0 y el tamaño de la lista.
		}
		else {
			doubles.insertarCola(d);
		}
	}

	cout << "Lista de doubles:" << endl;
	cout << doubles << endl;

	for (int i = 0; i < 10; i++){
		int cualRemocion = rand() % 3;

		if (cualRemocion == 0){ // Elige de manera aleatoria si remover la cabeza, una posicion o la cola.
			doubles.removerCabeza();
		}
		else if (cualRemocion == 1){
			doubles.removerNodo(rand() % (doubles.getSize() + 1)); // Remueve en una posicion aleatoria entre 0 y el tamaño de la lista.
		}
		else {
			doubles.removerCola();
		}
	}

	cout << "Lista de doubles con 10 remociones aleatorias:" << endl;
	cout << doubles << endl;

	donde = doubles.buscarPorNodo(3.5);
	cout << "hay un 3.5 en la posicion:" << donde << endl;
	Nodo<double> * eledouble = doubles.buscarPorPosicion(donde);
	cout << "en la posicion " << donde << " hay un: " << *eledouble << endl;
	eledouble = doubles.buscarPorPosicion(2);
	cout << "en la posicion " << 2 << " hay un: " << *eledouble << endl;
	eledouble = doubles.buscarPorPosicion(doubles.getSize() - 3);
	cout << "en la posicion " << doubles.getSize() - 3 << " hay un: " << *eledouble << endl;

	cout << "el tamaño de la lista es de: " << doubles.getSize() << endl;

	return 0;
}

