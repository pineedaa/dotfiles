#include "../include/tlistaporo.h"

TListaNodo::TListaNodo() : e() {
	anterior = NULL;
	siguiente = NULL;
}

TListaNodo::TListaNodo(const TListaNodo &nodo) : e(nodo.e) {
	anterior = NULL;
	siguiente = NULL;
}

//No se tendria que hacer layering del destructor?
TListaNodo::~TListaNodo() {
	anterior = NULL;
	siguiente = NULL;
}

TListaNodo & TListaNodo::operator=(const TListaNodo &nodo) {
	anterior = NULL;
	siguiente = NULL;
	e = nodo.e;
	return (*this);
}

////////////////////////////////////// TListaPosicion //////////////////////////////////////

TListaPosicion::TListaPosicion() {
	pos = NULL;
}

TListaPosicion::TListaPosicion(const TListaPosicion &origen) {
	pos = origen.pos;
}

TListaPosicion::~TListaPosicion() {
	pos = NULL;
}

TListaPosicion & TListaPosicion::operator=(const TListaPosicion &origen) {
	if(! ((*this) == origen)) {
		pos = origen.pos;
	}
	return (*this);
}

bool TListaPosicion::operator==(const TListaPosicion &origen) const{
	return (pos==origen.pos);
}

TListaPosicion TListaPosicion::Anterior() const{
	TListaPosicion p;
	
	if(pos != NULL) {
		if(pos->anterior != NULL) {
			p.pos = pos->anterior;
		}
	}

	return p;
}

TListaPosicion TListaPosicion::Siguiente() const{
	TListaPosicion p;
	
	if(pos != NULL) {
		if(pos->siguiente != NULL) {
			p.pos = pos->siguiente;
		}
	}

	return p;
}

bool TListaPosicion::EsVacia() const{
	if(pos == NULL) {
		return true;
	}
	else {
		return false;
	}
}

////////////////////////////////////// TListaPoro //////////////////////////////////////
void TListaPoro::Copiar(const TListaPoro &lista) {
	if(!lista.EsVacia()) {
		TListaPosicion p = lista.Primera();
		TListaNodo *n = new TListaNodo(*p.pos);
		primero = ultimo = n;
		p = p.Siguiente();

		while(!p.EsVacia()) {
			TListaNodo *n = new TListaNodo(*p.pos);
			InsertarCola(n);

			p = p.Siguiente();
		}
	}
	else {
		primero = NULL;
		ultimo = NULL;
	}
}

void TListaPoro::InsertarCabeza(TListaNodo *n) {
	n->siguiente = primero;
	primero = n;
	n->anterior = NULL;
	n->siguiente->anterior = n;
}

void TListaPoro::InsertarCola(TListaNodo *n) {
	n->siguiente = NULL;
	n->anterior = ultimo;
	ultimo = n;
	n->anterior->siguiente = n;
}

void TListaPoro::InsertarEntre(TListaNodo *n, const TListaPosicion &p) {
	n->siguiente = p.Siguiente().pos;
	n->anterior = p.pos;
	n->siguiente->anterior = n;
	n->anterior->siguiente = n;
}

TListaPoro::TListaPoro() {
	primero = NULL;
	ultimo = NULL;
}

//CORREGIR
TListaPoro::TListaPoro(const TListaPoro &lista) {
	Copiar(lista);
}

TListaPoro::~TListaPoro() {
	TListaPosicion p, q;
	q = Primera();

	while(!q.EsVacia()) {
		p = q;
		q = q.Siguiente();
		delete p.pos;
	}

	primero = ultimo = NULL;
}

TListaPoro & TListaPoro::operator=(const TListaPoro &lista) {
	if(this->primero != lista.primero) {
		(*this).~TListaPoro();
		Copiar(lista);
	}

	return (*this);
}

bool TListaPoro::operator==(const TListaPoro &lista) const{
	TListaPosicion p, q;
	p = Primera();
	q = lista.Primera();

	if(Longitud() == lista.Longitud()) {
		while(!p.EsVacia()) {
			if(p.pos->e != q.pos->e) {
				return false;
			}

			q = q.Siguiente();
			p = p.Siguiente();
		}
	}
	else {
		return false;
	}

	return true;
}

TListaPoro TListaPoro::operator+(const TListaPoro &lista) {
	TListaPoro l(*this);

	if(!lista.EsVacia()) {
		TListaPosicion p;
		p = lista.Primera();

		while(!p.EsVacia()) {
			//Insertar ya comprueba que no este en la primera lista.
			l.Insertar(p.pos->e);
			p = p.Siguiente();
		}
	}
	
	return l;
}

TListaPoro TListaPoro::operator-(const TListaPoro &lista) {
	TListaPoro l;
	TListaPosicion p;
	p = Primera();

	while(!p.EsVacia()) {
		if(!lista.Buscar(p.pos->e)) {
			l.Insertar(p.pos->e);
		}
		p = p.Siguiente();
	}

	return l;
}

bool TListaPoro::EsVacia() const{
	return (primero == NULL && ultimo == NULL);
}

bool TListaPoro::Insertar(const TPoro &poro) {
	if(EsVacia()) {
		TListaNodo *n = new TListaNodo();
		n->e = poro;
		primero = ultimo = n;

		return true;
	}
	else if(!Buscar(poro)) {
		TListaPosicion p;
		double v, v1, v2;

		p.pos = primero;

		if(Longitud() == 1) {
			TListaNodo *n = new TListaNodo();
			n->e = poro;

			if(poro.Volumen() < p.pos->e.Volumen()) {
				InsertarCabeza(n);
			}
			else {
				InsertarCola(n);
			}

			return true;
		}

		while(!p.EsVacia()) {

			if(p == Ultima()) {
				TListaNodo *n = new TListaNodo();
				n->e = poro;

				InsertarCola(n);
				return true;
			}
			else {
				v = poro.Volumen();
				v1 = p.pos->e.Volumen();
				v2 = p.Siguiente().pos->e.Volumen();

				if(v < v1 && p == Primera()) {
					TListaNodo *n = new TListaNodo();
					n->e = poro;

					InsertarCabeza(n);
					return true;
				}
				else if(v >= v1 && v < v2){
					TListaNodo *n = new TListaNodo();
					n->e = poro;

					InsertarEntre(n, p);
					return true;
				}
			}			

			p = p.Siguiente();
		}

		return false;
	}
	else {
		return false;
	}
}

bool TListaPoro::Borrar(const TPoro &poro) {
	if(!EsVacia() && Buscar(poro)) {
		if(Longitud() == 1) {
			(*this).~TListaPoro();
			return true;
		}
		else {
			TListaPosicion p;
			p = Primera();

			while(!p.EsVacia()) {
				if(p.pos->e == poro) {
					if(p.pos == primero) {
						p.pos->siguiente->anterior = NULL;
						primero = p.pos-> siguiente;
					}
					else if(p.pos == ultimo) {
						p.pos->anterior->siguiente = NULL;
						ultimo = p.pos -> anterior;
					}
					else {
						p.pos->anterior->siguiente = p.pos->siguiente;
						p.pos->siguiente->anterior = p.pos->anterior;
					}
					delete p.pos;
					return true;
				}

				p = p.Siguiente();
			}
		}
	}

	return false;
}

bool TListaPoro::Borrar(const TListaPosicion &origen) {
	return Borrar(origen.pos->e);
}

TPoro TListaPoro::Obtener(const TListaPosicion &origen) const{
	TPoro p;
	if(!EsVacia()) {
		if(origen.EsVacia()) {
			return p;
		}
		else {
			return origen.pos->e;
		}
	}
	else {
		return p;
	}

}

bool TListaPoro::Buscar(const TPoro &poro) const{
	if(!EsVacia()) {
		TListaPosicion p;
		p.pos = primero;

		while(true) {
			if(p.pos->e == poro) {
				return true;
			}
			else if(p.pos == ultimo) {
				return false;
			}

			p = p.Siguiente();
		}
	}
	else {
		return false;
	}
}

int TListaPoro::Longitud() const{
	if(!EsVacia()) {
		TListaPosicion p;
		p.pos = primero;

		int l = 1;

		while( !(p.pos == ultimo) ) {
			l++;
			p = p.Siguiente();
		}

		return l;
	}
	else {
		return 0;
	}
}

TListaPosicion TListaPoro::Primera() const{
	TListaPosicion p;

	if(!EsVacia()) {
		p.pos = primero;
	}

	return p;
}

TListaPosicion TListaPoro::Ultima() const{
	TListaPosicion p;

	if(!EsVacia()) {
		p.pos = ultimo;
	}

	return p;
}

TListaPoro TListaPoro::ExtraerRango(int n1, int n2) {
	TListaPoro l;

	if(n1 <= n2) {
		TListaPosicion p, q;
		p = Primera();
		int i = 1;

		while(!p.EsVacia() && i<=n2) {
			q = p;
			p = p.Siguiente();

			if(i >= n1) {
				l.Insertar(q.pos->e);
				Borrar(q.pos->e);
			}

			i++;
		}
	}

	return l;
}

ostream & operator<<(ostream &os, const TListaPoro &lista) {
	os << "(";
	if(!lista.EsVacia()) {
		TListaPosicion p;
		p = lista.Primera();

		while(!p.EsVacia()) {
			os << lista.Obtener(p);
			if(!p.Siguiente().EsVacia()) {
				os << " ";
			}
			p = p.Siguiente();
		}
	}
	os << ")";

	return os;
}