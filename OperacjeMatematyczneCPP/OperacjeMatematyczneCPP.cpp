#include "Liczba.h"
#include "LiczbaR.h"
#include "LiczbaZ.h"
#include "Wyniki.h"
#include <vector>
int main()
{

	LiczbaR re;
	re.initialize();

	std::vector<int> tab;
	tab = re.getTab();
	float err = re.getErr();

	LiczbaZ im(tab, err);

	Liczba* licz;
	licz = &re;
	licz->WyswietlRownanie();
	licz->ObliczPierwiastekRownania();
	licz->DodajLiczbyZespolone();
	licz->OdejmijLiczbyZespolone();

	licz = &im;
	licz->ObliczPierwiastekRownania();
	licz->DodajLiczbyZespolone();
	licz->OdejmijLiczbyZespolone();

	float delta = re.getDelta();
	float pdelta = re.getPdelta();
	float x1r = re.getX1r();
	float x2r = re.getX2r();
	float x3r = re.getX3r();
	float x4r = re.getX4r();
	float x1u = im.getX1u();
	float x2u = im.getX2u();
	float x3u = im.getX3u();
	float x4u = im.getX4u();
	float sr = re.getSr();
	float rr = re.getRr();
	float su = im.getSu();
	float ru = im.getRu();

	Wyniki* wynik = new Wyniki(tab, err, delta, pdelta, x1r, x2r, x3r, x4r, x1u, x2u, x3u, x4u, sr, rr, ru, su);;
	//wynik(tab, err, delta, pdelta,x1r,x2r,x3r,x4r, x1u, x2u, x3u, x4u, sr,rr, ru, su);
	//*wynik.wyswietl_wynik();
	wynik->wyswietl_wynik();
	system("PAUSE");
	delete wynik;
	return 0;
}