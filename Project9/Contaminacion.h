#pragma once
#include "Personaje.h"

class Contaminacion : public Personaje
{
public:
	Contaminacion(int ancho, int alto);
	~Contaminacion();

private:
};

Contaminacion::Contaminacion(int ancho, int alto) : Personaje(ancho, alto)
{
	x = (rand() % 1800) + 301;
	y = (rand() % 500) + 101;

}

Contaminacion::~Contaminacion()
{
}