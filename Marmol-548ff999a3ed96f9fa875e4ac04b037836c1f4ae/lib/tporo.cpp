#include "../include/tporo.h"

using namespace std;

char * TPoro::toLower(const char *c)
{	
	char *col = new char[strlen(c)+1];
	strcpy(col, c);

	for (unsigned int i = 0; i < strlen(col); i++) {
		if (col[i] >= 'A' && col[i] <= 'Z') {
			col[i] = col[i]+32;
		}
	}

	return col;
}

TPoro::TPoro() {
	x = 0;
	y = 0;
	volumen = 0;
	color = NULL;
}

TPoro::TPoro(int x, int y, double volumen) {
	this->x = x;
	this->y = y;
	this->volumen = volumen;
	color = NULL;
}

TPoro::TPoro(int x, int y, double volumen, char *color) {
	this->x = x;
	this->y = y;
	this->volumen = volumen;
	if(color != NULL) {
		this->color = new char[strlen(color)+1];
		this->color = toLower(color);
	}
	else {
		this->color = NULL;
	}
}

TPoro::TPoro(const TPoro &poro)
{
	x = poro.PosicionX();
	y = poro.PosicionY();
	volumen = poro.Volumen();
	if(poro.Color() != NULL) {
		color = new char[strlen(poro.Color())+1];
		strcpy(color, poro.Color());
	}
	else {
		color = NULL;
	}
}

TPoro::~TPoro()
{
	x = 0;
	y = 0;
	volumen = 0;
	if (color != NULL) {
		delete color;
		color = NULL;
	}
}

void TPoro::Color(const char *color) {
	if(color!=NULL) {
		if(this->color != NULL) {
			delete this->color;
		}
		this->color = new char[strlen(color)+1];
		this->color = toLower(color);
	}
}

TPoro & TPoro::operator=(const TPoro &poro)
{
	if((*this) != poro) {
		(*this).~TPoro();
		x = poro.PosicionX();
		y = poro.PosicionY();
		volumen = poro.Volumen();
		this->Color(poro.Color());
	}

	return (*this);
}


// VIOLASION POR ACA
bool TPoro::operator==(const TPoro & poro) const
{
	if (this->PosicionX() == poro.PosicionX() && this->PosicionY() == poro.PosicionY() && volumen == poro.Volumen()) {
		if((color == NULL && poro.Color() != NULL) || (color != NULL && poro.Color() == NULL)) {
			return false;
		}
		else if(color == NULL && poro.Color() == NULL) {
			return true;
		}
		else if(strcmp(color, poro.Color()) == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

bool TPoro::operator!=(const TPoro & poro) const
{
	//Supongo que hay que poner el contenido de this porque this es un puntero que señala a "este" objeto.
	if ((*this) == poro) {
		return false;
	}
	return true;
}

bool TPoro::EsVacio() const
{
	if (x == 0 && y == 0 && volumen == 0 && color == NULL) {
		return true;
	}
	return false;
}

/*Al ser una funcion amiga, deja acceder a los atributos privados
 *por lo tanto no hace falta utilizar los getters.
 */
ostream & operator<<(ostream &os, const TPoro &poro)
{
	if (!poro.EsVacio()) {
		//Fijar precision 2 decimales;
		os.setf(ios::fixed);
		os.precision(2);

		os << "(" << poro.x << ", " << poro.y << ") " << poro.volumen << " ";
		if (poro.color != NULL) {
			os << poro.color;
		}
		else {
			os << "-";
		}
	}
	else {
		os << "()";
	}
	return os;
}
