#include "stdafx.h"
#include "Lista.h"


Lista::Lista(){ // Estado inicial de la lista.
	size = 0;
	cabeza = NULL;
	cola = NULL;
}


Lista::~Lista(){
	if (cabeza != NULL) {
		destruirLista();
	}
}

void Lista::insertarCabeza(Elemento * nodo){
	if (cabeza == NULL) { // Si la cabeza est� vac�a solo asigna (si solo hay un elemento la cabeza y la cola aputan al mimo lugar).
		cabeza = nodo;
		cabeza->setPrev(NULL);
		cabeza->setNext(NULL);
		cola = nodo;
		cola->setPrev(NULL);
		cola->setNext(NULL);
	}
	else { // Si no est� vac�a mueve a todos los Elementos.
		Elemento * temp = nodo;
		cabeza->setPrev(temp);
		temp->setNext(cabeza);
		cabeza = temp;
		cabeza->setPrev(NULL);
	}
	size++;
}

void Lista::insertarCola(Elemento* nodo){
	if (cola == NULL){ // Si la cola est� vac�a solo asigna.
		cola = nodo;
		cola->setPrev(NULL);
		cola->setNext(NULL);
		cabeza = nodo;
		cabeza->setPrev(NULL);
		cabeza->setNext(NULL);
	}
	else { // Si no lo inserta al final.
		Elemento * temp = nodo;
		cola->setNext(temp);
		temp->setPrev(cola);
		cola = temp;
		cola->setNext(NULL);
	}
	size++;
}

void Lista::insertarElemento(Elemento * nodo, int donde){
	if (donde <= 0 || size == 0){ // Si la direcci�n es 0 (o menos para evitar excepciones) o si no hay ning�n elemento en la lista (tambi�n para evitar excepciones) se inserta el Elemento en la cabeza.
		insertarCabeza(nodo);
	}
	else if (donde >= size){ // Si la direcci�n es igual al tama�o (posicion siguiente a la ultima) o mayor (tambi�n para evitar excepciones) se inserta el Elemento en la cola.
		insertarCola(nodo);
	}
	else if (donde == size-1) { // si la direcci�n es igual al tama�o-1 (posici�n actual de la cola) se inserta ahi y se mueve la cola.
		Elemento * nuevo = nodo;
		cola->getPrev()->setNext(nuevo);
		nuevo->setPrev(cola->getPrev());
		nuevo->setNext(cola);
		cola->setPrev(nuevo);
		size++;
	}
	else { // Si no avanza hasta la posicion deseada y lo inserta en ese lugar.
		if (donde <= size/2) {
			Elemento * actual = cabeza;
			for (int i = 0; i < donde - 1; i++){ // Avanza en la lista hasta el elemento anterior a donde se quiere insertar.
				actual = actual->getNext();
			}
			Elemento * temp = actual->getNext();
			Elemento * nuevo = nodo;
			actual->setNext(nuevo);
			nuevo->setPrev(actual);
			nuevo->setNext(temp);
			temp->setPrev(nuevo);
		}
		else {
			Elemento * actual = cola;
			for (int i = size-1; i > donde + 1; i--){ // Avanza en la lista hasta el elemento siguiente a donde se quiere insertar.
				actual = actual->getPrev();
			}
			Elemento * temp = actual->getPrev();
			Elemento * nuevo = nodo;
			actual->setPrev(nuevo);
			nuevo->setNext(actual);
			nuevo->setPrev(temp);
			temp->setNext(nuevo);
		}
		size++;
	}
}

void Lista::removerCabeza(){
	if (cabeza != NULL){
		if (cabeza->getNext() != NULL){ // Si hay m�s de un elemento elimina la cabeza y asigna la cabeza a la siguiente posici�n.
			Elemento * temp = cabeza;
			cabeza = cabeza->getNext();
			cabeza->setPrev(NULL);
			delete temp;
		}
		else{ // Si solo hay uno, lo borra y vuelve al estado inicial.
			Elemento * temp = cabeza;
			cabeza = NULL;
			cola = NULL;
			delete temp;
		}
		size--;
	}
}

void Lista::removerCola(){
	if (cola != NULL){
		if (size == 1){ // Si solo hay un Elemento lo borra y vuelve al estado inicial.
			Elemento * temp = cola;
			cola = NULL;
			cabeza = NULL;
			delete temp;
		}
		else{ // Si hay m�s de uno elimina la cola y asigna la cola al pen�ltimo.
			Elemento * temp = cola;
			cola = cola->getPrev();
			cola->setNext(NULL);
			delete temp;
		}
		size--;
	}
}

void Lista::removerElemento(int donde){
	if (cabeza != NULL){
		if (donde <= 0 || size == 1){ // Si la direcci�n es 0 (o menor) o solo hay un elemento se elimina la cabeza.
			removerCabeza();
		}
		else if (donde >= size - 1){ // Si la direcci�n es igual al tama�o-1 o mayor se elimina la cola.
			removerCola();
		}
		else { // Si no avanza hasta la posici�n del elemento a elmininar y se elimina.
			if (donde <= size / 2) {
				Elemento * actual = cabeza;
				for (int i = 0; i < donde - 1; i++){ // Avanza en la lista hasta el elemento anterior al que se quiere eliminar.
					actual = actual->getNext();
				}
				Elemento * borrar = actual->getNext();
				actual->setNext(actual->getNext()->getNext());
				actual->getNext()->setPrev(actual);
				delete borrar;
			}
			else {
				Elemento * actual = cola;
				for (int i = size - 1; i > donde + 1; i--){ // Avanza en la lista hasta el elemento siguiente al que se quiere eliminar.
					actual = actual->getPrev();
				}
				Elemento * borrar = actual->getPrev();
				actual->setPrev(actual->getPrev()->getPrev());
				actual->getPrev()->setNext(actual);
				delete borrar;
			}
		}
		size--;
	}
}

int Lista::buscarPorElemento(Elemento * nodo){
	bool encontrado = false;
	int posicion = -1; // Posici�n a devolver, si no lo encuentra devuelve un -1.
	int contador = 0;
	Elemento * actual = cabeza;
	while (encontrado == false && actual->getNext() != NULL){ // Avanza buscando hasta que lo encuentre o ya no haya m�s elementos.
		if (actual->compareTo(nodo) == 0){
			posicion = contador;
			encontrado = true;
		}
		else {
			actual = actual->getNext();
			contador++;
		}
	}
	if (actual->compareTo(nodo) == 0){ // Se sale del ciclo antes de comprobar el �ltimo as� que se comprueba afuera.
		posicion = contador;
	}
	return posicion;
}

Elemento* Lista::buscarPorPosicion(int posicion){
	Elemento * actual = cabeza; // Elemento a devolver.
	if (posicion <= 0){ // Si la direcci�n es 0 (o menor) se devuelve la cabeza.
		actual = cabeza;
	}
	else if (posicion >= size - 1){ // Si la direcci�n es igual al tama�o-1 o mayor se devuelve la cola.
		actual = cola;
	}
	else {
		if (posicion <= size/2) {
			for (int i = 0; i < posicion; i++){ // Si es menor que la mitad avanza hasta la posici�n solicitada y la devuelve.
				actual = actual->getNext();
			}
		}
		else {
			actual = cola;
			for (int i = size-1; i > posicion; i--){ // Si no retrocede hasta la posici�n solicitada y la devuelve.
				actual = actual->getPrev();
			}
		}
	}
	return actual;
}

ostream & operator<<(ostream & out, Lista & l) {
	l.imprimir(l.cabeza, out);
	return out;
}

void Lista::imprimir(Elemento* nodo, ostream& out){
	Elemento* actual = nodo;
	while (actual->getNext() != NULL){
		out << *actual << endl;
		actual = actual->getNext();
	}
	out << *actual << endl;
}

void Lista::destruirLista(){
	int tam = size;
	for (int i = 0; i < tam; i++){
		removerCabeza();
	}
}

int Lista::getSize(){
	return size;
}