#pragma once
#include <iostream>
using namespace System::Drawing;

class Disparo
{
public:
	Disparo(int XJugador, int YJugador, char direccion);
	~Disparo();

	void dibujar(Graphics^ g);
	void mover(Graphics^ g);

	void setVisible(bool v);
	
	Rectangle getRectangle();
	bool getVisible();
	int getXAncho();
	int getYAlto();
	int getX();
	int getY();


private:
	int x, y;
	char direccion;
	int dx, dy;
	bool visible;
	int ancho;
};

Disparo::Disparo(int XJugador, int YJugador, char direccion) : x(XJugador - 5), y(YJugador), dx(15), dy(15), direccion(direccion), visible(true), ancho(12)
{
}

Disparo::~Disparo()
{
}

void Disparo::dibujar(Graphics^ g)
{
	SolidBrush^ sb = gcnew SolidBrush(Color::Black);
	g->FillEllipse(sb, x, y, ancho, ancho);
}

void Disparo::mover(Graphics^ g)
{
	if (direccion == 'A' && x >= 0)
	{
		x -= dx;
	}
	if (direccion == 'D' && x + ancho <= g->VisibleClipBounds.Width)
	{
		x += dx;
	}
	if (direccion == 'W' && y >= 0)
	{
		y -= dy;
	}
	if (direccion == 'S' && y + ancho <= g->VisibleClipBounds.Height)
	{
		y += dy;
	}
}

void Disparo::setVisible(bool v)
{
	visible = v;
}

Rectangle Disparo::getRectangle()
{
	return Rectangle(x, y, ancho, ancho);
}

bool Disparo::getVisible()
{
	return visible;
}

int Disparo::getXAncho()
{
	return x + ancho;
}

int Disparo::getYAlto()
{
	return y + ancho;
}

int Disparo::getX()
{
	return x;
}

int Disparo::getY()
{
	return y;
}