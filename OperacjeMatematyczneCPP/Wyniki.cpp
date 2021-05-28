#include "Wyniki.h"

Wyniki::Wyniki(std::vector<int> tab, float err, float delta, float pdelta, float x1r, float x2r, float x3r, float x4r, float x1u, float x2u, float x3u, float x4u, float sr, float rr, float ru, float su)
{
	this->tab = tab;
	this->err = err;
	this->delta = delta;
	this->pdelta = pdelta;
	this->x1r = x1r;
	this->x2r = x2r;
	this->x3r = x3r;
	this->x4r = x4r;
	this->x1u = x1u;
	this->x2u = x2u;
	this->x3u = x3u;
	this->x4u = x4u;
	this->sr = sr;
	this->su = su;
	this->rr = rr;
	this->ru = ru;

	wynik.push_back({x1r, x1u});
	wynik.push_back({x2r, x2u});
	wynik.push_back({x3r, x3u});
	wynik.push_back({x4r, x4u});
	wynik.push_back({0, 0 });
	wynik.push_back({0, 0 });
	wynik.push_back({0, 0 });
	wynik.at(4) = wynik.at(0) + wynik.at(1) + wynik.at(2) + wynik.at(3);
	wynik.at(5) = wynik.at(0) - wynik.at(1) - wynik.at(2) - wynik.at(3);
	wynik.at(6) = wynik.at(0) * wynik.at(1) * wynik.at(2) * wynik.at(3);
	int wartownik = 0;
}

Wyniki::Wyniki()
{
	delta = 0;
	pdelta = 0;
	err = 0;
	x1r = 0;
	x2r = 0;
	x3r = 0;
	x4r = 0;
	sr = 0;
	rr = 0;
	x1u = 0;
	x2u = 0;
	x3u = 0;
	x4u = 0;
	su = 0;
	ru = 0;
}


Wyniki::~Wyniki()
{
}

void Wyniki::wyswietl_wynik()
{

	int wartownik = 0;
	if (tab.front() == 0 && tab[1] == 0 && tab.back() != 0)
	{
		printf("Rownanie sprzeczne.\n");
		return;
	}
	else if (tab[0] != 0 && tab[1] == 0 && tab[2] == 0)
	{
		printf("x = 0.\n");
		return;
	}
	else if (tab[1] == 0 && tab[2] == 0)
	{
		printf("Rownanie tozsamosciowe.\n");
		return;
	}
	if (tab[0] == 0 && tab[1] != 0 && tab[2] != 0)
	{

		if ((tab[1] > 0 && tab[2] < 0) || (tab[1] < 0 && tab[2] > 0))
		{
			printf("Delta: %f\n", delta);
			if (delta == 0)
			{
				pdelta = 0;
			}
			printf("Pierwiastek z delty: %f\n", pdelta);
			printf("x1r: %lf\n", wynik.at(0).real());
			printf("x2r: %lf\n", wynik.at(1).real());
		}
		else
		{
			printf("Delta: %f\n", delta);
			if (delta == 0)
			{
				pdelta = 0;
			}
			printf("Pierwiastek z delty: %f\n", pdelta);
			printf("x1u: %lfi\n", wynik.at(0).imag());
			printf("x2u: %lfi\n", wynik.at(1).imag());
		}
		return;
	}
	else if (tab[0] == 0 && tab[1] != 0 && tab[2] != 0 && x1u < 0)
	{
		if (x1u < 0)
		{
			printf("x: %lf\n", wynik.at(0).imag());
		}
		else
		{
			x1u = 0;
			printf("x: %lf\n", wynik.at(0).imag());
		}
		return;
	}
	else if (tab[2] == 0)
	{
		if (tab[0] == 0 && tab[2] == 0)
		{
			printf("x = 0\n");
		}
		else if (tab[1] < 0 && tab[2] == 0)
		{
			printf("Delta: %f\n", delta);
			if (delta == 0)
			{
				pdelta = 0;
			}
			printf("Pierwiastek z delty: %f\n", pdelta);
			printf("x1r: %lf\n", wynik.at(0).real());
			printf("x2r: %lf\n", wynik.at(1).real());
			printf("x3r: %lf\n", wynik.at(2).real());
		}
		else
		{
			printf("Delta: %f\n", delta);
			if (delta == 0)
			{
				pdelta = 0;
			}
			printf("Pierwiastek z delty: %f\n", pdelta);
			printf("x1r: %lf\n", wynik.at(0).real());
			printf("x1u: %lfi\n", wynik.at(0).imag());
			printf("x2u: %lfi\n", wynik.at(1).imag());
		}
		return;
	}
	printf("Delta: %f\n", delta);
	if (delta == 0)
	{
		pdelta = 0;
	}
	printf("Pierwiastek z delty: %f\n", pdelta);
	if (tab[0] == 0 && tab[2] == 0)
	{
		printf("x = %f\n", wynik.at(0).imag());
	}
	else if (tab[2] == 0 || (tab[0] != 0 && tab[1] == 0 && tab[2] != 0))
	{
		if ((tab[0] > 0 && tab[1] == 0 && tab[2] < 0) || (tab[0] < 0 && tab[1] == 0 && tab[2] > 0))
		{
			printf("1. xr: %lf\n", wynik.at(0).real());
			printf("2. xr: %lf\n", wynik.at(1).real());
			printf("3. xu: %lfi\n", wynik.at(0).imag());
			printf("4. xu: %lfi\n", wynik.at(1).imag());
		}
		else
		{
			printf("xr1+xu1: ");  formatuj_liczbe(wynik.at(0).real(), wynik.at(0).imag());
			printf("xr2+xu2: ");  formatuj_liczbe(wynik.at(1).real(), wynik.at(1).imag());
			//printf("xr3+xu3: ");  formatuj_liczbe(wynik.at(2).real(), wynik.at(2).imag());
			std::cout << "xr3+xu3:" << conj(wynik.at(0)) << std::endl;
			printf("xr4+xu4: ");  formatuj_liczbe(wynik.at(3).real(), wynik.at(3).imag());
			printf("Suma liczb rzeczywistych: %f\n", wynik.at(4).real());
			printf("Suma liczb urojonych: %f\n", wynik.at(4).imag());
			printf("Roznica liczb rzeczywistych: %f\n", wynik.at(5).real());
			printf("Roznica liczb urojonych: %f\n", wynik.at(5).imag());
			printf("Wynik mno¿enia liczb zespolonych: %f\n", wynik.at(6).real());
		}
	}
	else
	{
		if ((tab[0] < 0 && tab[1] > 0 && tab[2] > 0) || (tab[0] < 0 && tab[1] < 0 && tab[2] > 0))
		{
			printf("x1r: %lf\n", wynik.at(0).real());
			printf("x2r: %lf\n", wynik.at(1).real());
			printf("x1u: %lfi\n", wynik.at(0).imag());
			printf("x2u: %lfi\n", wynik.at(1).imag());
		}
		else if ((tab[0] > 0 && tab[1] < 0 && tab[2] < 0) || (tab[0] > 0 && tab[1] > 0 && tab[2] < 0))
		{
			printf("x1r: %lf\n", wynik.at(0).real());
			printf("x2r: %lf\n", wynik.at(1).real());
			printf("x1u: %lfi\n", wynik.at(0).imag());
			printf("x2u: %lfi\n", wynik.at(1).imag());
		}
		else
		{
			printf("xr1+xu1: ");  formatuj_liczbe(wynik.at(0).real(), wynik.at(0).imag());
			printf("xr2+xu2: ");  formatuj_liczbe(wynik.at(1).real(), wynik.at(1).imag());
			//printf("xr3+xu3: ");  formatuj_liczbe(wynik.at(2).real(), wynik.at(2).imag());
			std::cout << "xr3+xu3:" << conj(wynik.at(0)) << std::endl;
			printf("xr4+xu4: ");  formatuj_liczbe(wynik.at(3).real(), wynik.at(3).imag());
			printf("Suma liczb rzeczywistych: %f\n", wynik.at(4).real());
			printf("Suma liczb urojonych: %f\n", wynik.at(4).imag());
			printf("Roznica liczb rzeczywistych: %f\n", wynik.at(5).real());
			printf("Roznica liczb urojonych: %f\n", wynik.at(5).imag());
			printf("Wynik mnozenia liczb zespolonych: %f\n", wynik.at(6).real());
		}
	}
}

void Wyniki::formatuj_liczbe(double xr, double xu)
{
	if (xr < 0 && xu < 0)
	{
		printf("(%lf)+(%lf)i\n", xr, xu);
	}
	else if (xr < 0)
	{

		printf("(%lf)+%lfi\n", xr, xu);
	}
	else if (xu < 0)
	{
		printf("%lf+(%lf)i\n", xr, xu);
	}
	else
	{
		printf("%lf+%lfi\n", xr, xu);
	}
}