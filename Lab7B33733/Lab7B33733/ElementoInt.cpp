#include "stdafx.h"
#include "ElementoInt.h"

ElementoInt::ElementoInt(int i) : Elemento(),
i(i) { // equivalente a this->i = i;
}

ElementoInt::~ElementoInt() {
}

int ElementoInt::compareTo(Elemento * otro) {
	int cmp = 0;
	ElementoInt * eInt = dynamic_cast<ElementoInt *>(otro);
	if (eInt != 0) {
		cmp = this->i < eInt->i ? -1 : this->i == eInt->i ? 0 : 1;
	}
	return cmp;
}

void ElementoInt::imprimir(ostream & out) const {
	out << i;
}
