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
	void wyswietl_rownanie();
	void oblicz_pierwiastek_rownania();
	void dodaj_liczby_zespolone();
	void odejmij_liczby_zespolone();
	double oblicz_delte(std::vector<int> tab);
	double sqrt_Newton(double d, double err);
	double sqrt_Heron(double d, double err);

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