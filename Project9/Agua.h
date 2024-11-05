#pragma once
#include "Personaje.h"
#include <vector>
using namespace std;

class Agua : public Personaje
{
public:
	Agua(int ancho, int alto);
	Agua();
	~Agua();

private:
	vector<int> aguaX;
	vector<int> aguaY;
};

Agua::Agua(int ancho, int alto) : Personaje(ancho, alto)
{
	//x = (rand() % 800) + 450;
	//y = (rand() % 800) + 350;

	vector<int> aguaX = { 300, 400, 500, 1700, 700, 1000, 300, 1200, 800, 1100, 1300 };
	vector<int> aguaY = { 800, 700, 600, 200, 300, 100, 400, 500 };

	for (int i = 0; i < aguaX.size(); i++)
	{
		int randomIndex = rand() % aguaX.size();

		x = aguaX[randomIndex];
	}

	for (int i = 0; i < aguaY.size(); i++)
	{
		int randomIndex = rand() % aguaY.size();

		y = aguaY[randomIndex];
	}

	idx = rand() % 2;
	idy = 0;
}

Agua::Agua()
{

}

Agua::~Agua()
{
}
