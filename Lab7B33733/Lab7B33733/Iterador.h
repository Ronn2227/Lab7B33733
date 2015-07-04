#pragma once

#include "Nodo.h"

using namespace std;

template<class T>
class Iterador {

private:
	Nodo<T> * actual;

public:
	Iterador(Nodo<T> * actual) {
		this->actual = actual;
	}

	~Iterador() {
	}

	Iterador<T>& operator++() { // Preincremento.
		if (actual->getNext() != NULL) {
			actual = actual->getNext();
		}
		else {
			actual = NULL;
		}
			return *this;
	}

	Iterador<T>& operator++(int) { // Posincremento.
		Iterador<T> tmp(this->actual);
		++(*this);
		return tmp;
	}

	Iterador<T>& operator--() { // Predecremento.
		if (actual->getPrev() != NULL) {
			actual = actual->getPrev();
		}
		else {
			actual = NULL;
		}
		return *this;
	}

	Iterador<T>& operator--(int) { // Posdecremento.
		Iterador<T> tmp(this->actual);
		--(*this);
		return tmp;
	}

	T operator*() {
		return actual->getActual();
	}

	bool operator!=(Iterador<T> & otro) {
		return this->actual != otro.actual;
	}

	bool operator==(Iterador<T> & otro) {
		return this->actual == otro.actual;
	}
};