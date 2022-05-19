#ifndef T_PORO_H
#define T_PORO_H

#include <iostream>
#include <string.h>

using namespace std;

class TPoro {
	private:
		int x;
		int y;
		double volumen;
		char* color;
		char * toLower(const char *c);
	public:
		//Forma canónica.
		TPoro();
		TPoro(int x, int y, double volumen);
		TPoro(int x, int y, double volumen, char *color);
		TPoro(const TPoro &poro);
		~TPoro();
		TPoro & operator=(const TPoro &poro);

		//Métodos.
		bool operator==(const TPoro &poro) const;
		bool operator!=(const TPoro &poro) const;
		void Posicion(const int &x, const int &y) { this->x = x; this->y = y;};
		void Volumen(const double &volumen) { this->volumen = volumen; };
		void Color(const char *color);
		int PosicionX() const { return x; };
		int PosicionY() const { return y; };
		double Volumen() const { return volumen; };
		char * Color() const { return color; };
		bool EsVacio() const;

	//Funciones amigas.
	friend ostream & operator<<(ostream &os, const TPoro &poro);
};

#endif