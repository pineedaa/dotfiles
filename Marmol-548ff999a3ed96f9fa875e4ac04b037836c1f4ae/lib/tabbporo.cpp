#include "../include/tabbporo.h"
#include <queue>

TNodoABB::TNodoABB() : item(), iz(), de() {

}

TNodoABB::TNodoABB(const TNodoABB &nodo) : item(nodo.item), iz(nodo.iz), de(nodo.de) {

}

TNodoABB::~TNodoABB() {

}

TNodoABB & TNodoABB::operator=(const TNodoABB &nodo) {
	if(this != &nodo) {
		TPoro poro;
		poro = nodo.item;

		TABBPoro izquierda, derecha;

		//Esto esta bien?
		if(nodo.iz.nodo != NULL && nodo.de.nodo != NULL) {
			izquierda = nodo.iz;
			derecha = nodo.de;
		}
		else {
			izquierda.nodo = NULL;
			derecha.nodo = NULL;
		}
	}

	return (*this);
}

//////////////////////////////// TABBPoro ////////////////////////////////
void TABBPoro::InordenAux(TVectorPoro &vector, int &pos) const {
	if(!EsVacio()) {
		nodo->iz.InordenAux(vector, pos);
		vector[pos] = nodo->item;
		pos++;
		nodo->de.InordenAux(vector, pos);
	}
}

void TABBPoro::PreordenAux(TVectorPoro &vector, int &pos) const {
	if(nodo != NULL) {
		vector[pos] = nodo->item;
		pos++;
		nodo->iz.PreordenAux(vector, pos);
		nodo->de.PreordenAux(vector, pos);
	}
}

void TABBPoro::PostordenAux(TVectorPoro &vector, int &pos) const {
	if(nodo != NULL) {
		nodo->iz.PostordenAux(vector, pos);
		nodo->de.PostordenAux(vector, pos);
		vector[pos] = nodo->item;
		pos++;
	}
}

void TABBPoro::Copiar(const TABBPoro &arbol) {
	if(arbol.nodo != NULL) {
		TNodoABB *n = new TNodoABB();
		n->item = arbol.nodo->item;
		nodo = n;
		(nodo->iz).Copiar(arbol.nodo->iz);
		(nodo->de).Copiar(arbol.nodo->de);
	}
	else {
		nodo = NULL;
	}
}

TNodoABB * TABBPoro::HijoDerecha() const {
	return nodo->de.nodo;
}

TABBPoro::TABBPoro() {
	nodo = NULL;
}

TABBPoro::TABBPoro(const TABBPoro &arbol) {
	Copiar(arbol);
}

TABBPoro::~TABBPoro() {
	if(nodo != NULL) {
		delete nodo;
		nodo = NULL;
	}
}

TABBPoro & TABBPoro::operator=(const TABBPoro &arbol) {
	(*this).~TABBPoro();
	Copiar(arbol);

	return (*this);
}

bool TABBPoro::operator==(const TABBPoro &arbol) const {
	if(arbol.Inorden() == Inorden()) {
		return true;
	}
	else {
		return false;
	}
}

bool TABBPoro::operator!=(const TABBPoro &arbol) const {
	return !((*this)==arbol);
}

bool TABBPoro::EsVacio() const {
	return nodo == NULL;
}

/*
 * Buscar recorre el arbol recursivamente al igual que
 * insertar, por lo tanto no creo que sea factible llamar a
 * buscar antes de intentar insertarlo.
 */
bool TABBPoro::Insertar(const TPoro &poro) {
	//Arbol NO vacio
	if(nodo != NULL) {
		double v = poro.Volumen();
		double vr = Raiz().Volumen();

		//No se pueden insertar duplicados.
		if(poro == nodo->item) {
			return false;
		}
		else if(Hoja()) {
			if(v > vr) {
				nodo->de.nodo = new TNodoABB();
				nodo->de.nodo->item = poro;
				return true;
			}
			else {
				nodo->iz.nodo = new TNodoABB();
				nodo->iz.nodo->item = poro;
				return true;
			}
		}
		else {
			if(v > vr) {
				(nodo->de).Insertar(poro);
			}
			else {
				(nodo->iz).Insertar(poro);
			}
		}

	}
	else {
		nodo = new TNodoABB();
		nodo->item = poro;
		return true;
	}
}

bool TABBPoro::Borrar(const TPoro &poro) {
	if(!EsVacio()) {
		if(nodo->item == poro) {
			//Si es hoja se borra directamente
			if(Hoja()) {
				(*this).~TABBPoro();
			}
			//Tiene un solo hijo a la izquierda
			else if(nodo->iz.nodo != NULL && nodo->de.nodo == NULL) {
				TNodoABB *n = nodo;
				nodo = nodo->iz.nodo;
				n->iz.nodo = NULL;
				delete n;
			}
			//Tiene un solo hijo a la derecha
			else if(nodo->iz.nodo == NULL && nodo->de.nodo != NULL) {
				TNodoABB *n = nodo;
				nodo = nodo->de.nodo;
				n->de.nodo = NULL;
				delete n;
			}
			//Tiene dos hijos
			else {
				TNodoABB *n = nodo;
				nodo = HijoDerecha();
				//Comprobamos que el nodo al que apuntaba no es HijoDerecha para evitar bucles.
				if(n->iz.nodo != nodo) {
					nodo->iz.nodo = n->iz.nodo;
				}
				if(n->de.nodo != nodo) {
					nodo->de.nodo = n->de.nodo;
				}
				n->de.nodo = NULL;
				n->iz.nodo = NULL;
				delete n;
			}

			return true;
		}
		else if(poro.Volumen() > nodo->item.Volumen()){
			(nodo->de).Borrar(poro);
		}
		else {
			(nodo->iz).Borrar(poro);
		}
	}
	else {
		return false;
	}
}

bool TABBPoro::Buscar(const TPoro &poro) const {
	if(!EsVacio()) {
		if(nodo->item == poro) {
			return true;
		}
		else {
			if(poro.Volumen() > nodo->item.Volumen()) {
				(nodo->de).Buscar(poro);
			}
			else {
				(nodo->iz).Buscar(poro);
			}
		}

	}
	else {
		return false;
	}
}

bool TABBPoro::Hoja() const {
	if(nodo != NULL && nodo->iz.nodo == NULL && nodo->de.nodo == NULL) {
		return true;
	}

	return false;
}

TPoro TABBPoro::Raiz() const {
	if(nodo != NULL) {
		return nodo->item;
	}
	else {
		TPoro error;
		return error;
	}
}
int TABBPoro::Altura() const {
	if(!EsVacio()) {
		if(Hoja()) {
			return 1;
		}
		else if(nodo->iz.Altura() > nodo->de.Altura()) {
			return (1 + nodo->iz.Altura());
		}
		else {
			return (1 + nodo->de.Altura());
		}
	}
	else {
		return 0;
	}
}

int TABBPoro::Nodos() const {
	if(!EsVacio()) {
		return (1 + (nodo->de).Nodos() + (nodo->iz).Nodos());
	}
	else {
		return 0;
	}
}

int TABBPoro::NodosHoja() const {
	if(!EsVacio()) {
		if(Hoja()) {
			return 1;
		}
		else {
			return ((nodo->de).NodosHoja() + (nodo->iz).NodosHoja());
		}
	}
	else {
		return 0;
	}
}

TVectorPoro TABBPoro::Inorden() const {
	int posicion = 1;
	TVectorPoro v(Nodos());

	InordenAux(v, posicion);

	return v;
}

TVectorPoro TABBPoro::Preorden() const {
	int posicion = 1;
	TVectorPoro v(Nodos());
	PreordenAux(v, posicion);

	return v;
}

TVectorPoro TABBPoro::Postorden() const {
	int posicion = 1;
	TVectorPoro v(Nodos());
	PostordenAux(v, posicion);

	return v;
}

TVectorPoro TABBPoro::Niveles() const {
	int i = 1;
	TVectorPoro vector(Nodos());
	queue<TABBPoro*> cola;

	TABBPoro aAux(*this);
	TABBPoro *aux = &aAux;
	
	if(!EsVacio()) {
		cola.push(&aAux);

		while(!cola.empty()) {
			aux = cola.front();
			vector[i++] = aux->nodo->item;
			cola.pop();

			if(!aux->nodo->iz.EsVacio()) {
				cola.push(&(aux->nodo->iz));
			}
			if(!aux->nodo->de.EsVacio()) {
				cola.push(&(aux->nodo->de));
			}
		}
	}

	return vector;
}

TABBPoro TABBPoro::operator+(const TABBPoro &arbol) {
	TABBPoro copia(*this);
	int tam = arbol.Nodos();
	TVectorPoro vector(arbol.Inorden());

	for(int i=1; i<=tam; i++) {
		copia.Insertar(vector[i]);
	}

	return copia;
}

TABBPoro TABBPoro::operator-(const TABBPoro &arbol) {
	TABBPoro a;
	int tam = Nodos();
	TVectorPoro vector(Inorden());

	for(int i=1; i<=tam; i++) {
		if(!arbol.Buscar(vector[i])) {
			a.Insertar(vector[i]);
		}
	}

	return a;
}

ostream & operator<<(ostream &os, const TABBPoro &arbol) {
	os << arbol.Niveles();

	return os;
}
