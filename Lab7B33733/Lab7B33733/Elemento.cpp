#include "stdafx.h"
#include "Elemento.h"


Elemento::Elemento() {
	next = NULL;
	prev = NULL;
}

Elemento::~Elemento() {
}

Elemento *& Elemento::getNext() {
	return next;
}

Elemento *& Elemento::getPrev() {
	return prev;
}

void Elemento::setNext(Elemento * e) {
	this->next = e;
}

void Elemento::setPrev(Elemento * e) {
	this->prev = e;
}

ostream & operator<<(ostream & out, const Elemento & e) {
	e.imprimir(out);
	return out;
}

bool Elemento::operator <(Elemento& otro) {
	return this->compareTo(&otro) < 0;
}

bool Elemento::operator <=(Elemento& otro) {
	return this->compareTo(&otro) <= 0;
}

bool Elemento::operator >(Elemento& otro) {
	return this->compareTo(&otro) > 0;
}

bool Elemento::operator >=(Elemento& otro) {
	return this->compareTo(&otro) >= 0;
}
