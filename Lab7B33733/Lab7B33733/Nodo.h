#pragma once

using namespace std;

template<class T>
class Nodo {

	template<class T>
	friend ostream & operator<<(ostream &, Nodo<T> &);

private:

	T actual;
	Nodo<T> *prev, *next; // Anterior y siguiente respectivamente.

public:

	Nodo(T elemento) { // Estado inicial del Nodo.
		this->actual = elemento;
		prev = NULL;
		next = NULL;
	}

	~Nodo() {
	}

	T & getActual() {
		return actual;
	}

	Nodo<T> *& getPrev() {
		return prev;
	}

	Nodo<T> *& getNext() {
		return next;
	}

	void setPrev(Nodo<T> * e) {
		this->prev = e;
	}

	void setNext(Nodo<T> * e) {
		this->next = e;
	}

private:

	void imprimir(ostream & out) {
		out << actual;
	}

};

template<class T>
ostream & operator<<(ostream & out, Nodo<T> & n) {
	n.imprimir(out);
	return out;
}

