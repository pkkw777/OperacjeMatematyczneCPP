#pragma once
#include <iostream>
#include <vector>
#include <complex>
class Wyniki
{
public:
	Wyniki(std::vector<int> tab, float err, float delta, float pdelta, float x1r, float x2r, float x3r, float x4r, float x1u, float x2u, float x3u, float x4u, float sr, float rr, float ru, float su);
	Wyniki();
	~Wyniki();
	void wyswietl_wynik();
	void formatuj_liczbe(double xr, double xu);
private:
	std::vector<int> tab;
	std::vector<std::complex<double>> wynik;
	double delta, pdelta, err;
	double x1r, x2r, x3r, x4r, sr, rr;
	double x1u, x2u, x3u, x4u, su, ru;
};