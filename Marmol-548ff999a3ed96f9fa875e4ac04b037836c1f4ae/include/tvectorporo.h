#ifndef T_VECTOR_PORO_H
#define T_VECTOR_PORO_H

#include <iostream>
#include "tporo.h"

using namespace std;

class TVectorPoro
{
	private:
		int dimension;
		TPoro *datos;
		TPoro error;
		void Copiar(const TVectorPoro &vector);

	public:
		TVectorPoro();
		TVectorPoro(int dimension);
		TVectorPoro(const TVectorPoro &vector);
		~TVectorPoro();
		TVectorPoro & operator=(const TVectorPoro &vector);

		//Metodos
		bool operator==(const TVectorPoro &vector) const;
		bool operator!=(const TVectorPoro &vector) const;
		TPoro & operator[](const int &indice);		//Parte izquierda.
		TPoro operator[](const int &indice) const;	//Parte derecha.
		int Longitud() const {return this->dimension;};
		int Cantidad() const;
		bool Redimensionar(const int &tam);

	friend ostream & operator<<(ostream &os, const TVectorPoro &vector);
};

#endif
