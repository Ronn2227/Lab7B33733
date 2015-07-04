#pragma once

using namespace std;

class Gato {

	friend ostream & operator<<(ostream &, const Gato &);

	template <class T>
	friend class Nodo;

private:

	int vidas;
	string nombre;
	Gato();

public:

	Gato(string, int);
	virtual ~Gato();

	int compareTo(Gato*); // Se compara por nombre.
	void imprimir(ostream &) const;

	bool operator<(Gato &);
	bool operator<=(Gato &);
	bool operator>(Gato &);
	bool operator>=(Gato &);
	bool operator==(Gato &);
};

ostream & operator<<(ostream &, const Gato &);