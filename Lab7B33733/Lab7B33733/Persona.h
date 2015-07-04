#pragma once

using namespace std;

class Persona {

	friend ostream & operator<<(ostream &, const Persona &);

	template <class T>
	friend class Nodo;

private:

	int id;
	string nombre;
	Persona();

public:

	Persona(string, int);
	virtual ~Persona();

	int compareTo(Persona*); // Se compara por id.
	void imprimir(ostream &) const;
	
	bool operator<(Persona &);
	bool operator<=(Persona &);
	bool operator>(Persona &);
	bool operator>=(Persona &);
	bool operator==(Persona &);
};

ostream & operator<<(ostream &, const Persona &);