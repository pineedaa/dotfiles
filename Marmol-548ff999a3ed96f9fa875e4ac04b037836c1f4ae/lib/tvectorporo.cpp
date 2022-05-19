#include "../include/tvectorporo.h"

void TVectorPoro::Copiar(const TVectorPoro &vector) {
	dimension = vector.Longitud();

	if(dimension != 0) {
		datos = new TPoro[dimension];
		for(int i=0; i<dimension; i++) {
			datos[i] = vector[i+1];
		}
	}
	else {
		datos = NULL;
	}
}

TVectorPoro::TVectorPoro() : error() {
	dimension = 0;
	datos = NULL;
}

TVectorPoro::TVectorPoro(int dimension) : error() {
	if(dimension <= 0) {
		this->dimension = 0;
		datos = NULL;
	}
	else {
		this->dimension = dimension;
		datos = new TPoro[dimension];
	}
}

TVectorPoro::TVectorPoro(const TVectorPoro &vector) : error(vector.error) {
	Copiar(vector);
}

TVectorPoro::~TVectorPoro() {
	dimension = 0;
	if(datos!=NULL) {
		delete [] datos;
		datos = NULL;
	}
}

TVectorPoro & TVectorPoro::operator=(const TVectorPoro &vector) {
	if((*this) != vector) {
		(*this).~TVectorPoro();
		Copiar(vector);
	}

	return *this;
}

bool TVectorPoro::operator==(const TVectorPoro &vector) const {
	bool igual=true;

	if(dimension == vector.Longitud()) {
		for(int i=0; i<dimension && igual; i++) {
			if(vector[i+1]!=datos[i]) {
				igual=false;
			}
		}
	}
	else {
		igual=false;
	}

	return igual;
}

bool TVectorPoro::operator!=(const TVectorPoro &vector) const {
	if((*this) == vector) {
		return false;
	}
	else {
		return true;
	}
}

bool TVectorPoro::Redimensionar(const int &tam) {
	if(tam <= 0) {
		return false;
	}
	else if(tam == dimension) {
		return false;
	}
	else if(tam > dimension) {
		TPoro *aux = new TPoro[dimension];
		for(int i=0; i<dimension; i++) {
			aux[i] = datos[i];
		}

		delete [] datos;
		datos = new TPoro[tam];

		for(int i=0; i<dimension; i++) {
			datos[i] = aux[i];
		}

		delete [] aux;
		aux = NULL;
	}
	else {
		TPoro *aux = new TPoro[tam];
		for(int i=0; i<tam; i++) {
			aux[i] = datos[i];
		}

		delete [] datos;
		datos = new TPoro[tam];

		for(int i=0; i<tam; i++) {
			datos[i] = aux[i];
		}
	}

	dimension = tam;
	return true;
}

TPoro & TVectorPoro::operator[](const int &indice) {
	if(indice > 0) {
		return datos[indice - 1];
	}
	else {
		return error;
	}
}

TPoro TVectorPoro::operator[](const int &indice) const{
	if(indice > 0) {
		return datos[indice - 1];
	}
	else {
		return error;
	}
}

int TVectorPoro::Cantidad() const {
	int c = 0;
	for(int i=0; i<dimension; i++) {
		if(!datos[i].EsVacio()) {
			c++;
		}
	}

	return c;
}


ostream & operator<<(ostream &os, const TVectorPoro &vector) {
	os << "[";
	for(int i=0; i<vector.dimension; i++) {
		os << i+1 << " ";
		os << vector[i+1];
		if(i < vector.dimension-1) {
			 os << " ";
		}
	}
	os << "]";

	return os;
}