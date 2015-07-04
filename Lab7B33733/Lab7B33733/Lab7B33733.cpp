// Lab7B33733.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DoublyLinkedList.h"
#include "Persona.h"
#include "Gato.h"


int _tmain(int argc, _TCHAR* argv[]) {

	srand((unsigned int)time(NULL));

	ofstream filePruebas;
	filePruebas.open("Pruebas.txt");// Como las salidas de pruebas son muchas y no caben en la pantalla, se guardarán en un archivo a revisar.


	// Nombres posibles a elegir para las personas.
	string nombresPersonas[20] = {"Maria", "Juan", "Ana", "Pedro", "Alejandra", "Ronald", "Ximena", "Alfredo", "Amanda", "Jose",
						  "Elsa", "Diego", "Amaia", "Esteban", "Elena", "Antonio", "Stephanie", "Ruben", "Tiana", "Elias"};

	// Nombres posibles a elegir para los gatos.
	string nombresGatos[20] = {"Karin", "Fiona", "Brownie", "Mittens", "Chispa", "Tom", "Cheethara", "Azrael", "Arlene", "Garfield",
							   "Happy", "Nermal", "Duquesa", "Bills", "Nina", "Felix", "Luna", "Silvestre", "Nala", "Bigotes"};

	int cantidadElementos = rand() % 41 + 15; // Setea cantidad de Elementos de la Lista en un valor aleatorio entre 15 y 50.
	DoublyLinkedList<int> enteros;
	for (int i = 0; i < cantidadElementos; i++){

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

	filePruebas << "Lista de enteros:" << endl;
	filePruebas << enteros << endl;

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

	filePruebas << "Lista de enteros con 10 remociones aleatorias:" << endl;
	filePruebas << enteros << endl;

	Nodo<int> * eleInt = enteros.buscarPorPosicion(2);
	filePruebas << "en la posicion " << 2 << " hay un: " << *eleInt << endl;
	eleInt = enteros.buscarPorPosicion(enteros.getSize() - 3);
	filePruebas << "en la posicion " << enteros.getSize() - 3 << " hay un: " << *eleInt << endl;
	
	filePruebas << "el tamaño de la lista es de: " << enteros.getSize() << endl;
	filePruebas << endl;
	//delete eleInt; // No se hacen los delete a estos punteros porque la lista se encarga de eliminarlos y si se eliminan se cae el iterador despues.

	cantidadElementos = rand() % 41 + 15; // Setea cantidad de Elementos de la Lista en un valor aleatorio entre 15 y 50.
	DoublyLinkedList<double> doubles;
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

	filePruebas << "Lista de doubles:" << endl;
	filePruebas << doubles << endl;

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

	filePruebas << "Lista de doubles con 10 remociones aleatorias:" << endl;
	filePruebas << doubles << endl;

	Nodo<double> * eledouble = doubles.buscarPorPosicion(2);
	filePruebas << "en la posicion " << 2 << " hay un: " << *eledouble << endl;
	eledouble = doubles.buscarPorPosicion(doubles.getSize() - 3);
	filePruebas << "en la posicion " << doubles.getSize() - 3 << " hay un: " << *eledouble << endl;

	filePruebas << "el tamaño de la lista es de: " << doubles.getSize() << endl;
	filePruebas << endl;

	cantidadElementos = rand() % 41 + 15; // Setea cantidad de Elementos de la Lista en un valor aleatorio entre 15 y 50.
	DoublyLinkedList<char> chars;
	for (int i = 0; i < cantidadElementos; i++){
		int a = 0;
		if (rand() % 2 == 0) {
			a = rand() % 26 + 65;
		}
		else {
			a = rand() % 26 + 97;
		}
		char c = char(a);

		int cualInsercion = rand() % 3;

		if (cualInsercion == 0){ // Elige de manera aleatoria si incertar en la cabeza, en una posicion o en la cola.
			chars.insertarCabeza(c);
		}
		else if (cualInsercion == 1){
			chars.insertarNodo(c, rand() % (chars.getSize() + 1)); // Incerta en una posicion aleatoria entre 0 y el tamaño de la lista.
		}
		else {
			chars.insertarCola(c);
		}
	}

	filePruebas << "Lista de chars:" << endl;
	filePruebas << chars << endl;

	for (int i = 0; i < 10; i++){
		int cualRemocion = rand() % 3;

		if (cualRemocion == 0){ // Elige de manera aleatoria si remover la cabeza, una posicion o la cola.
			chars.removerCabeza();
		}
		else if (cualRemocion == 1){
			chars.removerNodo(rand() % (chars.getSize() + 1)); // Remueve en una posicion aleatoria entre 0 y el tamaño de la lista.
		}
		else {
			chars.removerCola();
		}
	}

	filePruebas << "Lista de chars con 10 remociones aleatorias:" << endl;
	filePruebas << chars << endl;

	Nodo<char> * eleChar = chars.buscarPorPosicion(2);
	filePruebas << "en la posicion " << 2 << " hay un: " << *eleChar << endl;
	eleChar = chars.buscarPorPosicion(chars.getSize() - 3);
	filePruebas << "en la posicion " << chars.getSize() - 3 << " hay un: " << *eleChar << endl;

	filePruebas << "el tamaño de la lista es de: " << chars.getSize() << endl;
	filePruebas << endl;

	cantidadElementos = rand() % 41 + 15; // Setea cantidad de Elementos de la Lista en un valor aleatorio entre 15 y 50.
	DoublyLinkedList<Persona> personas;
	for (int i = 0; i < cantidadElementos; i++){
		string name = nombresPersonas[rand() % 20]; // Elige aleatoriamente entre los 20 nombres.
		int id = rand() % 100; // Genera un id aleatorio entre 0 y 100.
		Persona per (name, id); // Crea persona con valores aleatorios.

		int cualInsercion = rand() % 3;

		if (cualInsercion == 0){ // Elige de manera aleatoria si incertar en la cabeza, en una posicion o en la cola.
			personas.insertarCabeza(per);
		}
		else if (cualInsercion == 1){
			personas.insertarNodo(per, rand() % (personas.getSize() + 1)); // Incerta en una posicion aleatoria entre 0 y el tamaño de la lista.
		}
		else {
			personas.insertarCola(per);
		}
	}

	filePruebas << "Lista de personas:" << endl;
	filePruebas << personas << endl;

	for (int i = 0; i < 10; i++){
		int cualRemocion = rand() % 3;

		if (cualRemocion == 0){ // Elige de manera aleatoria si remover la cabeza, una posicion o la cola.
			personas.removerCabeza();
		}
		else if (cualRemocion == 1){
			personas.removerNodo(rand() % (personas.getSize() + 1)); // Remueve en una posicion aleatoria entre 0 y el tamaño de la lista.
		}
		else {
			personas.removerCola();
		}
	}

	filePruebas << "Lista de personas con 10 remociones aleatorias:" << endl;
	filePruebas << personas << endl;

	Nodo<Persona> * elePer = personas.buscarPorPosicion(2);
	filePruebas << "en la posicion " << 2 << " hay un: " << *elePer << endl;
	elePer = personas.buscarPorPosicion(personas.getSize() - 3);
	filePruebas << "en la posicion " << personas.getSize() - 3 << " hay un: " << *elePer << endl;

	filePruebas << "el tamaño de la lista es de: " << personas.getSize() << endl;
	filePruebas << endl;

	cantidadElementos = rand() % 41 + 15; // Setea cantidad de Elementos de la Lista en un valor aleatorio entre 15 y 50.
	DoublyLinkedList<Gato> gatos;
	for (int i = 0; i < cantidadElementos; i++){
		string name = nombresGatos[rand() % 20]; // Elige aleatoriamente entre los 20 nombres.
		int vidas = rand() % 9 + 1; // Genera una cantidad de vidas alatoria entre 1 y 9.
		Gato cat(name, vidas); // Crea gato con valores aleatorios.

		int cualInsercion = rand() % 3;

		if (cualInsercion == 0){ // Elige de manera aleatoria si incertar en la cabeza, en una posicion o en la cola.
			gatos.insertarCabeza(cat);
		}
		else if (cualInsercion == 1){
			gatos.insertarNodo(cat, rand() % (gatos.getSize() + 1)); // Incerta en una posicion aleatoria entre 0 y el tamaño de la lista.
		}
		else {
			gatos.insertarCola(cat);
		}
	}

	filePruebas << "Lista de gatos:" << endl;
	filePruebas << gatos << endl;

	for (int i = 0; i < 10; i++){
		int cualRemocion = rand() % 3;

		if (cualRemocion == 0){ // Elige de manera aleatoria si remover la cabeza, una posicion o la cola.
			gatos.removerCabeza();
		}
		else if (cualRemocion == 1){
			gatos.removerNodo(rand() % (gatos.getSize() + 1)); // Remueve en una posicion aleatoria entre 0 y el tamaño de la lista.
		}
		else {
			gatos.removerCola();
		}
	}

	filePruebas << "Lista de gatos con 10 remociones aleatorias:" << endl;
	filePruebas << gatos << endl;

	Nodo<Gato> * eleCat = gatos.buscarPorPosicion(2);
	filePruebas << "en la posicion " << 2 << " hay un: " << *eleCat << endl;
	eleCat = gatos.buscarPorPosicion(gatos.getSize() - 3);
	filePruebas << "en la posicion " << gatos.getSize() - 3 << " hay un: " << *eleCat << endl;

	filePruebas << "el tamaño de la lista es de: " << gatos.getSize() << endl;
	filePruebas << endl;

	
	filePruebas << "Prueba iterador hacia adelante: " << endl;
	for (Iterador<int> i = enteros.begin(); i != enteros.end(); ++i) {
		filePruebas << *i << endl;
	}
	filePruebas << endl;

	filePruebas << "Prueba iterador hacia atras: " << endl;
	for (Iterador<double> d = doubles.rBegin(); d != doubles.rEnd(); d--) {
		filePruebas << *d << endl;
	}

	filePruebas.close();
	system("pause");
	return 0;
}

