#pragma once
#include <iostream>
using namespace System::Drawing;

class Personaje
{
public:
	Personaje(int ancho, int alto);
	Personaje();
	~Personaje();

	void dibujar(Graphics^ g, Bitmap^ bmp);
	virtual void mover();
	Rectangle getRectangle();

	int getX();
	int getY();
	void setX(int v);
	void setY(int v);
	bool getVisible();
	void setVisible(bool v);

protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int idx, idy;
	bool visible;
};

Personaje::Personaje(int ancho, int alto) : ancho(ancho), alto(alto), visible(true)
{
}

Personaje::Personaje()
{

}

Personaje::~Personaje()
{
}

void Personaje::dibujar(Graphics^ g, Bitmap^ bmp) 
{
	Rectangle seccion = Rectangle(idx * ancho, idy * alto, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho * 0.4, alto * 0.4);
	g->DrawImage(bmp, zoom, seccion, GraphicsUnit::Pixel);
}

void Personaje::mover()
{

}

Rectangle Personaje::getRectangle() { return Rectangle(x, y, ancho * 0.4, alto * 0.4); }

int Personaje::getX()
{
	return x;
}

int Personaje::getY()
{
	return y;
}

void Personaje::setX(int v)
{
	x = v;
}

void Personaje::setY(int v)
{
	y = v;
}

bool Personaje::getVisible()
{
	return visible;
}

void Personaje::setVisible(bool v)
{
	visible = v;
}