#pragma once
#include "Personaje.h"

class Guardian : public Personaje
{
public:
	Guardian(int ancho, int alto);
	~Guardian();

	void mover(Graphics^ g, char tecla);

	void disminuir_Vidas();
	int getVidas();
	void setVidas(int v);
	char getDireccion();
	void setDireccion(char v);
	int getInicioX();
	int getInicioY();

private:
	int vidas;
	char direccion;
	int inicioX, inicioY;
};

Guardian::Guardian(int ancho, int alto) : Personaje(ancho, alto)
{
	x = 850;
	y = 430;
	dx = dy = 15;
	idx = idy = 0;
	direccion = 'S';
	vidas = rand() % 10 + 5;
	inicioX = x;
	inicioY = y;
}

Guardian::~Guardian()
{
}

void Guardian::mover(Graphics^ g, char tecla)
{
	switch (tecla)
	{
	case 'A':
		if (x > 0) {
			x -= dx;
			idy = 3;
			direccion = 'A';
		}
		break;

	case 'D':
		if (x + ancho * 1.0 < g->VisibleClipBounds.Width) {
			x += dx;
			idy = 1;
			direccion = 'D';
		}
		break;

	case 'W':
		if (y > 0) {
			y -= dy;
			idy = 2;
			direccion = 'W';
		}
		break;

	case 'S':
		if (y + alto * 1.0 < g->VisibleClipBounds.Height) {
			y += dy;
			idy = 0;
			direccion = 'S';
		}
		break;
	}
	idx++;
	if (idx > 2) { idx = 0; }
}

void Guardian::disminuir_Vidas()
{
	vidas--;
}

int Guardian::getVidas()
{
	return vidas;
}

void Guardian::setVidas(int v)
{
	vidas = v;
}

char Guardian::getDireccion()
{
	return direccion;
}

void Guardian::setDireccion(char v)
{
	direccion = v;
}

int Guardian::getInicioX()
{
	return inicioX;
}

int Guardian::getInicioY()
{
	return inicioY;
}

