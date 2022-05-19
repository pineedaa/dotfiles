#include "../include/tavlporo.h"

//////////////////////////////////////////TNodoAVL//////////////////////////////////////////
TNodoAVL::TNodoAVL() : item(), iz(), de() {
	fe = 0;
}

TNodoAVL::TNodoAVL(const TNodoAVL &nodo) : item(nodo.item), iz(nodo.iz), de(nodo.de) {
	fe = nodo.fe;
}

TNodoAVL::~TNodoAVL() {
	fe = 0;
}

TNodoAVL & TNodoAVL::operator=(const TNodoAVL &nodo) {
	if(this != &nodo) {
		item = nodo.item;

		if(nodo.iz.raiz != NULL && nodo.de.raiz != NULL) {
			iz = nodo.iz;
			de = nodo.de;
		}
		else {
			iz.raiz = NULL;
			de.raiz = NULL;
		}
	}

	return (*this);
}

//////////////////////////////////////////TAVLPoro//////////////////////////////////////////

TPoro TAVLPoro::BuscarMayor() const
{
	TPoro p;
	TNodoAVL *pNodo=NULL;

	pNodo=raiz;
	while(pNodo->de.raiz!=NULL)
	{
		pNodo=pNodo->de.raiz;
	}
	p=pNodo->item;
	return p;
}


void TAVLPoro::InordenAux(TVectorPoro &vector, int &pos) const {
	if(!EsVacio()) {
		raiz->iz.InordenAux(vector, pos);
		vector[pos] = raiz->item;
		pos++;
		raiz->de.InordenAux(vector, pos);
	}
}

void TAVLPoro::PreordenAux(TVectorPoro &vector, int &pos) const {
	if(raiz != NULL) {
		vector[pos] = raiz->item;
		pos++;
		raiz->iz.PreordenAux(vector, pos);
		raiz->de.PreordenAux(vector, pos);
	}
}

void TAVLPoro::PostordenAux(TVectorPoro &vector, int &pos) const {
	if(raiz != NULL) {
		raiz->iz.PostordenAux(vector, pos);
		raiz->de.PostordenAux(vector, pos);
		vector[pos] = raiz->item;
		pos++;
	}
}

void TAVLPoro::Copiar(const TAVLPoro &arbol) {
	if(arbol.raiz != NULL) {
		TNodoAVL *n = new TNodoAVL();
		n->item = arbol.raiz->item;

		n->fe = arbol.raiz->fe;
		
		raiz = n;
		(raiz->iz).Copiar(arbol.raiz->iz);
		(raiz->de).Copiar(arbol.raiz->de);
	}
	else {
		raiz = NULL;
	}
}
TNodoAVL * TAVLPoro::HijoDerecha() const {
	return raiz->de.raiz;
}

TAVLPoro::TAVLPoro() {
	raiz = NULL;
}

TAVLPoro::TAVLPoro(const TAVLPoro &arbol) {
	Copiar(arbol);
}

TAVLPoro::~TAVLPoro() {
	if(raiz != NULL) {
		delete raiz;
		raiz = NULL;
	}
}

TAVLPoro & TAVLPoro::operator=(const TAVLPoro &arbol) {
	if(this != &arbol){
		(*this).~TAVLPoro();
		Copiar(arbol);
	}
	return (*this);
}

bool TAVLPoro::operator==(const TAVLPoro &arbol) const {
	if(arbol.Inorden() == Inorden()) {
		return true;
	}
	else {
		return false;
	}
}

bool TAVLPoro::operator!=(const TAVLPoro &arbol) const {
	return !((*this) == arbol);
}

bool TAVLPoro::EsVacio() const {
	return raiz == NULL;
}

void TAVLPoro::Reequilibrar(){
	//Por la derecha
	if(raiz->fe==2){
		if(raiz->de.raiz->fe==1 || raiz->de.raiz->fe==0) {
			rotacionDD();
		}
		else if(raiz->de.raiz->fe==-1) {
			rotacionDI();
		}

	}
	//Por la izquierda
	else if(raiz->fe==-2) {
		if(raiz->iz.raiz->fe==1) {
			rotacionID();
		}
		else if(raiz->iz.raiz->fe==-1 || raiz->iz.raiz->fe==0) {
			rotacionII();
		}
	}
}

void TAVLPoro::rotacionDD(){
	TAVLPoro B,D,C;

	B=(*this);
	D=raiz->de;
	C=raiz->de.raiz->iz;

	(*this)=D;
	raiz->iz=B;
	raiz->iz.raiz->de=C;
	
}
void TAVLPoro::rotacionID(){
	TAVLPoro F,B,D,C,E;

	F=(*this);
	B=raiz->iz;
	D=raiz->iz.raiz->de;
	E=raiz->iz.raiz->de.raiz->de;
	C=raiz->iz.raiz->de.raiz->iz;

	(*this)=D;
	raiz->iz=B;
	raiz->iz.raiz->de=C;
	raiz->de=F;
	raiz->de.raiz->iz=E;
}
void TAVLPoro::rotacionDI(){
	TAVLPoro B,F,D,C,E;

	B=(*this);
	F=raiz->de;
	D=raiz->de.raiz->iz;
	C=raiz->de.raiz->iz.raiz->iz;
	E=raiz->de.raiz->iz.raiz->de;

	(*this)=D;
	raiz->iz=B;
	raiz->de=F;
	raiz->iz.raiz->de=C;
	raiz->de.raiz->iz=E;

}
void TAVLPoro::rotacionII(){
	TAVLPoro D,B,C;
	
	D=(*this);
	B=raiz->iz;
	C=raiz->iz.raiz->de;
	
	(*this)=B;
	raiz->de=D;
	raiz->de.raiz->iz=C;
}

bool TAVLPoro::Insertar(const TPoro &poro) {

	bool correcto=false;
	if(raiz != NULL) {
			double v = poro.Volumen();
			double vr = Raiz().Volumen();

			//No se pueden insertar duplicados.
			if(poro == raiz->item) {
				return false;
			}
			else if(Hoja()) {
				if(v > vr) {
					raiz->de.raiz = new TNodoAVL();
					raiz->de.raiz->item = poro;
					return true;
				}
				else {
					raiz->iz.raiz = new TNodoAVL();
					raiz->iz.raiz->item = poro;
					return true;
				}
			}
			else {
				if(v > vr) {
					if((raiz->de).Insertar(poro)){
						//Se actualiza el factor de equilibrio y se llama a reequilibrar.
						this->raiz->fe = this->raiz->de.Altura() - this->raiz->iz.Altura();
						Reequilibrar();

						return true;
					}
				}
				else {
					if((raiz->iz).Insertar(poro)){
						this->raiz->fe = this->raiz->de.Altura() - this->raiz->iz.Altura();
						Reequilibrar();

						return true;
					}
				}
			}

		}
		else {
			raiz = new TNodoAVL();
			raiz->item = poro;
			raiz->fe=0;
			return true;
		}
return correcto;
}

bool TAVLPoro::Buscar(const TPoro &poro) const {
	if(!EsVacio()) {
		if(raiz->item == poro) {
			return true;
		}
		else {
			if(poro.Volumen() > raiz->item.Volumen()) {
				(raiz->de).Buscar(poro);
			}
			else {
				(raiz->iz).Buscar(poro);
			}
		}
	}
	else {
		return false;
	}
}

bool TAVLPoro::Hoja() const {
	if(raiz != NULL && raiz->iz.raiz == NULL && raiz->de.raiz == NULL) {
		return true;
	}

	return false;
}

int TAVLPoro::Altura() const {
	if(!EsVacio()) {
		if(Hoja()) {
			return 1;
		}
		else if(raiz->iz.Altura() > raiz->de.Altura()) {
			return (1 + raiz->iz.Altura());
		}
		else {
			return (1 + raiz->de.Altura());
		}
	}
	else {
		return 0;
	}
}

int TAVLPoro::Nodos() const {
	if(!EsVacio()) {
		return (1 + (raiz->de).Nodos() + (raiz->iz).Nodos());
	}
	else {
		return 0;
	}
}

int TAVLPoro::NodosHoja() const {
	if(!EsVacio()) {
		if(Hoja()) {
			return 1;
		}
		else {
			return ((raiz->de).NodosHoja() + (raiz->iz).NodosHoja());
		}
	}
	else {
		return 0;
	}
}

TVectorPoro TAVLPoro::Inorden() const {
	int posicion = 1;
	TVectorPoro v(Nodos());

	InordenAux(v, posicion);

	return v;
}

TVectorPoro TAVLPoro::Preorden() const {
	int posicion = 1;
	TVectorPoro v(Nodos());
	PreordenAux(v, posicion);

	return v;
}

TVectorPoro TAVLPoro::Postorden() const {
	int posicion = 1;
	TVectorPoro v(Nodos());
	PostordenAux(v, posicion);

	return v;
}

bool TAVLPoro::Borrar(const TPoro &poro) {
	bool correcto=false;

if(!EsVacio()) {
		if(raiz->item == poro) {
			//Si es hoja se borra directamente
			if(Hoja()) {
				(*this).~TAVLPoro();
			}
			//Tiene un solo hijo a la izquierda
			else if(raiz->iz.raiz != NULL && raiz->de.raiz == NULL) {
				TNodoAVL *n = raiz;
				raiz = raiz->iz.raiz;
				n->iz.raiz = NULL;
				delete n;
			}
			//Tiene un solo hijo a la derecha
			else if(raiz->iz.raiz == NULL && raiz->de.raiz != NULL) {
				TNodoAVL *n = raiz;
				raiz = raiz->de.raiz;
				n->de.raiz = NULL;
				delete n;
			}
			//Tiene dos hijos
			else {
				TNodoAVL *n = raiz;
				raiz = HijoDerecha();
				//Comprobamos que el nodo al que apuntaba no es HijoDerecha para evitar bucles.
				if(n->iz.raiz != raiz) {
					raiz->iz.raiz = n->iz.raiz;
				}
				if(n->de.raiz != raiz) {
					raiz->de.raiz = n->de.raiz;
				}
				n->de.raiz = NULL;
				n->iz.raiz = NULL;
				delete n;
			}

			return true;
		}
		else if(poro.Volumen() > raiz->item.Volumen()){
			if((raiz->de).Borrar(poro)){
				this->raiz->fe = this->raiz->de.Altura() - this->raiz->iz.Altura();
				Reequilibrar();

				return true;
			}
		}
		else {
			if((raiz->iz).Borrar(poro)){
				this->raiz->fe = this->raiz->de.Altura() - this->raiz->iz.Altura();
				Reequilibrar();

				return true;
			}
		}
	}
	else {
		return false;
	}
return correcto;
}

TPoro TAVLPoro::Raiz() const {
	if(!EsVacio()) {
		return raiz->item;
	}
	else {
		TPoro error;
		return error;
	}
}

ostream & operator<<(ostream &os, const TAVLPoro &arbol) {
	os << arbol.Inorden();

	return os;
}
