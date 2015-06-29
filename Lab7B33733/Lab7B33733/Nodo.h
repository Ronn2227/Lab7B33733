#pragma once

using namespace std;

template<class T>
class Nodo {

	template<class T>
	friend ostream & operator<<(ostream &, Nodo<T> &);

private:

	T actual;
	Nodo<T> *prev, *next;

public:

	Nodo(T elemento) {
		this->actual = elemento;
		prev = NULL;
		next = NULL;
	}

	~Nodo() {
	}

	T getActual() {
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

	int compareTo(Nodo<T> * otro) {
		int cmp = this->actual < otro->actual ? -1 : this->actual == otro->actual ? 0 : 1;
		return cmp;
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

