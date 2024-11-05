#pragma once
#include "Guardian.h"
#include "Semilla.h"
#include "Agua.h"
#include "Residuo.h"
#include "Disparo.h"
#include <vector>
using namespace std;

class Controlador {
public:
	Controlador(Bitmap^ bmpGuardian, Bitmap^ bmpSemilla, Bitmap^ bmpAgua, Bitmap^ bmpResiduo);
	~Controlador();

	void dibujar_elementos(Graphics^ g, Bitmap^ bmpGuardian, Bitmap^ bmpSemilla, Bitmap^ bmpAgua, Bitmap^ bmpResiduo);
	void agregar_disparos();
	void mover_elementos(Graphics^ g);
	void colision(Graphics^ g);
	void agragarElementos(Graphics^ g, Bitmap^ bmpSemilla, Bitmap^ bmpAgua, Bitmap^ bmpResiduo);
	
	void disminuir_tiempo();
	void setTiempo_disparo(int v);

	bool getDisparar();
	void setDisparar(bool v);
	void disminuirAgua();
	void disminuirSemilla();
	void disminuirResiduo();

	int getTiempo_disparo();
	int getN_Semillas();
	int getN_Agua();
	int getN_Residuo();

	int getCount_Agua();
	int getCount_Semilla();
	int getCount_Residuo();

	Guardian* getGuardian();
	vector<Disparo*>getDisparos();

private:
	Guardian* guardian;
	vector<Semilla*> semilla;
	vector<Agua*> agua;
	vector<Residuo*> residuos;
	vector<Disparo*> disparos;
	int N_Semillas;
	int N_Agua;
	int N_Residuos;
	int tiempo_disparo;
	int tiempo_recursos;
	bool disparar;
	int count_Agua = 0;
	int count_Semilla = 0;
	int count_Residuo = 0;
};

Controlador::Controlador(Bitmap^ bmpGuardian, Bitmap^ bmpSemilla, Bitmap^ bmpAgua, Bitmap^ bmpResiduo)
{
	N_Semillas = 12;
	guardian = new Guardian(bmpGuardian->Width / 4, bmpGuardian->Height / 4);
	for (int i = 0; i < N_Semillas; i++)
	{
		semilla.push_back(new Semilla(bmpSemilla->Width / 5, bmpSemilla->Height));
	}
	N_Agua = 12;
	for (int i = 0; i < N_Agua; i++)
	{
		agua.push_back(new Agua(bmpAgua->Width / 4, bmpAgua->Height));
	}
	N_Residuos = 12;
	for (int i = 0; i < N_Residuos; i++)
	{
		residuos.push_back(new Residuo(bmpResiduo->Width / 3, bmpResiduo->Height));
	}
	tiempo_disparo = 1;
	disparar = false;
	tiempo_recursos = 0;
}

Controlador::~Controlador() 
{
	delete guardian;
	for (auto s : semilla) delete s;
	for (auto a : agua) delete a;
	for (auto r : residuos) delete r;
	for (auto d : disparos) delete d;
}

void Controlador::agregar_disparos()
{
	disparos.push_back(new Disparo(guardian->getX(), guardian->getY(), guardian->getDireccion()));
}

void Controlador::dibujar_elementos(Graphics^ g, Bitmap^ bmpGuardian, Bitmap^ bmpSemilla, Bitmap^ bmpAgua, Bitmap^ bmpResiduo)
{
	for (int i = 0; i < semilla.size(); i++)
	{
		semilla[i]->dibujar(g, bmpSemilla);
	}
	for (int i = 0; i < agua.size(); i++)
	{
		agua[i]->dibujar(g, bmpAgua);
	}
	for (int i = 0; i < residuos.size(); i++)
	{
		residuos[i]->dibujar(g, bmpResiduo);
	}
	for (int i = 0; i < disparos.size(); i++)
	{
		disparos[i]->dibujar(g);
	}
	guardian->dibujar(g, bmpGuardian);
}

void Controlador::mover_elementos(Graphics^ g)
{
	for (int i = 0; i < disparos.size(); i++)
	{
		disparos[i]->mover(g);
	}
}

void Controlador::agragarElementos(Graphics^ g, Bitmap^ bmpSemilla, Bitmap^ bmpAgua, Bitmap^ bmpResiduo)
{
	tiempo_recursos++;

	if (tiempo_recursos >= 60 * 5)
	{
		semilla.push_back(new Semilla(bmpSemilla->Width / 5, bmpSemilla->Height));
		agua.push_back(new Agua(bmpAgua->Width / 4, bmpAgua->Height));
		residuos.push_back(new Residuo(bmpResiduo->Width / 3, bmpResiduo->Height));

		tiempo_recursos = 0;
	}
}


void Controlador::colision(Graphics^ g)
{
	for (int i = 0; i < semilla.size(); i++)
	{
		if (guardian->getRectangle().IntersectsWith(semilla.at(i)->getRectangle()))
		{
			count_Semilla++;
			semilla.at(i)->setVisible(false);
		}
	}

	for (int i = 0; i < agua.size(); i++)
	{
		if (guardian->getRectangle().IntersectsWith(agua.at(i)->getRectangle()))
		{
			count_Agua++;
			agua.at(i)->setVisible(false);
		}
	}

	for (int i = 0; i < residuos.size(); i++)
	{
		if (guardian->getRectangle().IntersectsWith(residuos.at(i)->getRectangle()))
		{
			count_Residuo++;
			residuos.at(i)->setVisible(false);
		}
	}

	for (int i = 0; i < disparos.size(); i++)
	{
		if (disparos[i]->getX() < 0 || disparos[i]->getXAncho() > g->VisibleClipBounds.Width)
		{
			disparos[i]->setVisible(false);
		}
	}

	// eliminar

	for (int i = 0; i < semilla.size(); i++)
	{
		if (!semilla[i]->getVisible())
		{
			semilla.erase(semilla.begin() + i);
		}
	}

	for (int i = 0; i < agua.size(); i++)
	{
		if (!agua[i]->getVisible())
		{
			agua.erase(agua.begin() + i);
		}
	}

	for (int i = 0; i < residuos.size(); i++)
	{
		if (!residuos[i]->getVisible())
		{
			residuos.erase(residuos.begin() + i);
		}
	}
}

Guardian* Controlador::getGuardian() 
{
	return guardian;
}

void Controlador::disminuir_tiempo()
{
	tiempo_disparo--;
}

void Controlador::setTiempo_disparo(int v)
{
	tiempo_disparo = v;
}


void Controlador::setDisparar(bool v)
{
	disparar = v;
}

int Controlador::getTiempo_disparo()
{
	return tiempo_disparo;
}

bool Controlador::getDisparar()
{
	return disparar;
}

int Controlador::getN_Semillas()
{
	return semilla.size();
}

int Controlador::getN_Agua()
{
	return agua.size();
}

int Controlador::getN_Residuo()
{
	return residuos.size();
}

vector<Disparo*> Controlador::getDisparos()
{
	return disparos;
}

int Controlador::getCount_Agua()
{
	return count_Agua;
}

int Controlador::getCount_Semilla()
{
	return count_Semilla;
}

int Controlador::getCount_Residuo()
{
	return count_Residuo;
}

void Controlador::disminuirAgua()
{
	count_Agua--;
}

void Controlador::disminuirSemilla()
{
	count_Semilla--;
}

void Controlador::disminuirResiduo()
{
	count_Residuo--;
}