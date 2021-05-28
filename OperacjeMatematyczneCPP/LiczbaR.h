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
	void WyswietlRownanie();
	void ObliczPierwiastekRownania();
	void DodajLiczbyZespolone();
	void OdejmijLiczbyZespolone();
	double ObliczDelte(std::vector<int> tab);
	double SqrtNewton(double d, double err);
	double SqrtHeron(double d, double err);

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