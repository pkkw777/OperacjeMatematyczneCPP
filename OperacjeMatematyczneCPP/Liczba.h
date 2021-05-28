#pragma once
class Liczba
{
public:
	Liczba();
	virtual ~Liczba();
	virtual void WyswietlRownanie() = 0;
	virtual void ObliczPierwiastekRownania() = 0;
	virtual void DodajLiczbyZespolone() = 0;
	virtual void OdejmijLiczbyZespolone() = 0;
};