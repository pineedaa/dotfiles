#ifndef T_LISTAPORO_H
#define T_LISTAPORO_H

#include <iostream>
#include "tporo.h"

using namespace std;

class TListaNodo {
	private:
		TPoro e;
		TListaNodo *anterior;
		TListaNodo *siguiente;
	public:
		TListaNodo();
		TListaNodo(const TListaNodo &nodo);
		~TListaNodo();
		TListaNodo & operator=(const TListaNodo &nodo);
	friend class TListaPosicion;
	friend class TListaPoro;
};

class TListaPosicion {
	private:
		TListaNodo *pos;
	public:
		TListaPosicion();
		TListaPosicion(const TListaPosicion &origen);
		~TListaPosicion();
		TListaPosicion & operator=(const TListaPosicion &origen);
		bool operator==(const TListaPosicion &origen) const;
		TListaPosicion Anterior() const;
		TListaPosicion Siguiente() const;
		bool EsVacia() const;
	friend class TListaPoro;
};

class TListaPoro {
	private:
		TListaNodo *primero;
		TListaNodo *ultimo;
		void Copiar(const TListaPoro &lista);
		void InsertarCabeza(TListaNodo *n);
		void InsertarCola(TListaNodo *n);
		void InsertarEntre(TListaNodo *n, const TListaPosicion &p);
	public:
		TListaPoro();
		TListaPoro(const TListaPoro &lista);
		~TListaPoro();
		TListaPoro & operator=(const TListaPoro &lista);
		bool operator==(const TListaPoro &lista) const;
		TListaPoro operator+(const TListaPoro &lista);
		TListaPoro operator-(const TListaPoro &lista);
		bool EsVacia() const;
		bool Insertar(const TPoro &poro);
		bool Borrar(const TPoro &poro);
		bool Borrar(const TListaPosicion &origen);
		TPoro Obtener(const TListaPosicion &origen) const;
		bool Buscar(const TPoro &poro) const;
		int Longitud() const;
		TListaPosicion Primera() const;
		TListaPosicion Ultima() const;
		TListaPoro ExtraerRango(int n1, int n2);
	friend ostream & operator<<(ostream &os, const TListaPoro &lista);
};

#endif