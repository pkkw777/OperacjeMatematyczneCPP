#pragma once
#include "Liczba.h"
#include <iostream>
#include <vector>
class LiczbaR :
	public Liczba
{
public:
	LiczbaR();
	~LiczbaR();
	void wyswietl_rownanie();
	void oblicz_pierwiastek_rownania();
	void dodaj_liczby_zespolone();
	void odejmij_liczby_zespolone();
	double oblicz_delte(std::vector<int> tab);
	double sqrt_Newton(double d, double err);
	double sqrt_Heron(double d, double err);

	void initialize();
	std::vector<int> getTab();
	float getErr();
	float getDelta();
	float getPdelta();
	float getX1r();
	float getX2r();
	float getX3r();
	float getX4r();
	float getSr();
	float getRr();
private:
	std::vector<int> tab;
	double delta, pdelta, err;
	int a, b, c;
	double x1r, x2r, x3r, x4r, sr, rr;	
};