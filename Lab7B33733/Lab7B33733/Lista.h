#pragma once

#include "Elemento.h"

using namespace std;

class Lista {

	friend ostream & operator<<(ostream &, Lista &);

private:

	Elemento * cabeza;
	Elemento * cola;
	int size;

public:

	Lista();
	virtual ~Lista();
	void insertarCabeza(Elemento *);
	void insertarCola(Elemento *);
	void insertarElemento(Elemento *, int);
	void removerCabeza();
	void removerCola();
	void removerElemento(int); // Remueve un elemento de la lista según una posición.
	int getSize(); // Devuelve el tamaño de la lista (cantidad de elementos).
	int buscarPorElemento(Elemento *); // Busca un elemento en la lista y deuelve la posición donde lo encontró (El primero que encuentra).
	Elemento * buscarPorPosicion(int); // Devuelve el Elemento según una posición.

private:
	void imprimir(Elemento *, ostream &); // Devuelve un out que sirve para imprimir la lista.
	void destruirLista(); // Destruye la lista.
};

ostream & operator<<(ostream &, Lista &);