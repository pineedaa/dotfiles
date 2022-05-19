#include "tvectorporo.h"

#ifndef TAVLPORO_H
#define TAVLPORO_H

class TNodoAVL;

class TAVLPoro {
	private:
		TNodoAVL *raiz;
		void InordenAux(TVectorPoro &vector, int &pos) const;
		void PreordenAux(TVectorPoro &vector, int &pos) const;
		void PostordenAux(TVectorPoro &vector, int &pos) const;
		void Copiar(const TAVLPoro &arbol);
		void Reequilibrar();
		TPoro BuscarMayor() const ;//cambialo por el tuyo
		void rotacionDD();
		void rotacionID();
		void rotacionDI();
		void rotacionII();
		TNodoAVL * HijoDerecha() const;
	
	public:
		TAVLPoro();
		TAVLPoro(const TAVLPoro &arbol);
		~TAVLPoro();
		TAVLPoro & operator=(const TAVLPoro &arbol);
		//METODOS
		bool operator==(const TAVLPoro &arbol) const;
		bool operator!=(const TAVLPoro &arbol) const;
		bool EsVacio() const;
		bool Insertar(const TPoro &poro);
		bool Buscar(const TPoro &poro) const;
		bool Hoja() const;
		int Altura() const;
		int Nodos() const;
		int NodosHoja() const;
		TVectorPoro Inorden() const;
		TVectorPoro Preorden() const;
		TVectorPoro Postorden() const;
		bool Borrar(const TPoro &poro);
		TPoro Raiz() const;
	friend ostream & operator<<(ostream &os, const TAVLPoro &arbol);
	friend class TNodoAVL;
};	

class TNodoAVL {
	private:
		TPoro item;
		TAVLPoro iz, de;
		int fe;
	
	public:
		TNodoAVL();
		TNodoAVL(const TNodoAVL &nodo);
		~TNodoAVL();
		TNodoAVL & operator=(const TNodoAVL &nodo);
	friend class TAVLPoro;
};

#endif // TAVLPORO_H
	
