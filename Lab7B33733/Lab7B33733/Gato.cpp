#include "stdafx.h"
#include "Gato.h"

Gato::Gato() {
}

Gato::Gato(string name, int vidas){
	this->nombre = name;
	this->vidas = vidas;
}


Gato::~Gato(){
}

int Gato::compareTo(Gato* otro){
	return this->nombre.compare(otro->nombre); // Se compara con otro Gato por nombre.
}

ostream & operator<<(ostream & out, const Gato & cat) {
	cat.imprimir(out);
	return out;
}

void Gato::imprimir(ostream & out) const {
	out << nombre << ", vidas: " << vidas;
}

bool Gato::operator <(Gato& otro) {
	return this->compareTo(&otro) < 0;
}

bool Gato::operator <=(Gato& otro) {
	return this->compareTo(&otro) <= 0;
}

bool Gato::operator >(Gato& otro) {
	return this->compareTo(&otro) > 0;
}

bool Gato::operator >=(Gato& otro) {
	return this->compareTo(&otro) >= 0;
}

bool Gato::operator ==(Gato& otro) {
	return this->compareTo(&otro) == 0;
}