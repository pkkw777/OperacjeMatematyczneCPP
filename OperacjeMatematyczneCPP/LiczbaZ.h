#pragma once
#include "Liczba.h"
#include <iostream>
#include <vector>
class LiczbaZ :
	public Liczba
{
public:
	LiczbaZ(std::vector<int> tab, float err);
	LiczbaZ();
	~LiczbaZ();
	void WyswietlRownanie();
	void ObliczPierwiastekRownania();
	void DodajLiczbyZespolone();
	void OdejmijLiczbyZespolone();
	double ObliczDelte(std::vector<int> tab);
	double SqrtNewton(double d, double err);
	double SqrtHeron(double d, double err);

	float getX1u();
	float getX2u();
	float getX3u();
	float getX4u();
	float getSu();
	float getRu();
private:
	std::vector<int> tab;
	double delta, pdelta, err;
	double x1u, x2u, x3u, x4u, su, ru;
};