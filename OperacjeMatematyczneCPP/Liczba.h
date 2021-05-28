#pragma once
class Liczba
{
public:
	Liczba();
	virtual ~Liczba();
	virtual void wyswietl_rownanie() = 0;
	virtual void oblicz_pierwiastek_rownania() = 0;
	virtual void dodaj_liczby_zespolone() = 0;
	virtual void odejmij_liczby_zespolone() = 0;
};