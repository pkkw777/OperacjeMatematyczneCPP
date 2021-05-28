#include "LiczbaZ.h"

LiczbaZ::LiczbaZ(std::vector<int> tab, float err)
{
	this->tab = tab;
	this->err = err;
}

LiczbaZ::LiczbaZ()
{
	delta = 0;
	pdelta = 0;
	err = 0;
	x1u = 0;
	x2u = 0;
	x3u = 0;
	x4u = 0;
	su = 0;
	ru = 0;
}

LiczbaZ::~LiczbaZ()
{

}

void LiczbaZ::wyswietl_rownanie()
{
	if (tab[0] == 0)
	{
		printf("Wspolczynnik a = 0.\n");
	}
	else if (tab[1] < 0 && tab[2] < 0)
	{

		printf("Wzor: %dx^4+(%d)x^2+(%d) = 0\n", tab[0], tab[1], tab[2]);
	}
	else if (tab[1] < 0)
	{

		printf("Wzor: %dx^4+(%d)x^2+%d = 0\n", tab[0], tab[1], tab[2]);
	}
	else if (tab[2] < 0)
	{
		printf("Wzor: %dx^4+%dx^2+(%d) = 0\n", tab[0], tab[1], tab[2]);
	}
	else
	{
		printf("Wzor: %dx^4+%dx^2+%d = 0\n", tab[0], tab[1], tab[2]);
	}
}

void LiczbaZ::oblicz_pierwiastek_rownania()
{
	double a = 0, b = 0, ai = 0, bi = 0;
	double temp = tab[0];
	delta = oblicz_delte(tab);

	if (err == 0)
	{
		if (tab[0] == 0 && tab[1] != 0 && tab[2] != 0)
		{
			a = tab[1];
			b = tab[2];

			std::vector<int> tab2;

			tab2.push_back(a);
			tab2.push_back(tab[0]);
			tab2.push_back(b);

			double deltaN = oblicz_delte(tab2);
			if ((tab[1] > 0 && tab[2] < 0) || (tab[1] < 0 && tab[2] > 0))
			{
			}
			else
			{
				x1u = (tab[0] + sqrt(deltaN)) / (2 * a);
				x2u = (tab[0] - sqrt(deltaN)) / (2 * a);
			}
		}
		else if (tab[2] == 0)
		{
			if (tab[1] < 0 && tab[2] == 0)
			{
				a = tab[0];
				b = tab[1];

				std::vector<int> tab2;

				tab2.push_back(a);
				tab2.push_back(b);
				tab2.push_back(tab[2]);

				double deltaN = oblicz_delte(tab2);

				ai = (-b + sqrt(deltaN)) / (2 * a);
				if (ai < 0)
					ai *= -1;
			}
			else
			{
				pdelta = sqrt(delta);
				a = (-tab[1] + pdelta) / (2 * temp);
				b = (-tab[1] - pdelta) / (2 * temp);
				if (b < 0)
					b *= -1;
				x1u = sqrt(b);
				x2u = -sqrt(b);
			}
		}
		else
		{
			pdelta = sqrt(delta);
			a = -tab[1] / (2 * temp);
			b = -tab[1] / (2 * temp);
			ai = pdelta / (2 * temp);
			bi = -pdelta / (2 * temp);
			if ((tab[0] > 0 && tab[1] == 0 && tab[2] < 0) || (tab[0] < 0 && tab[1] == 0 && tab[2] > 0))
			{
				double t1, t2;
				t1 = tab[2];
				t2 = tab[0];
				a = t1 / t2;
				if (a < 0)
					b = -a;
				else
					b = a;
				x1u = sqrt(sqrt(b));
				x2u = -sqrt(sqrt(b));
			}
			else
			{
				if ((tab[0] < 0 && tab[1] > 0 && tab[2] > 0) || (tab[0] < 0 && tab[1] < 0 && tab[2] > 0))
				{
					x1u = (sqrt(-tab[1] + pdelta)) / (temp);
					x2u = -(sqrt(-tab[1] + pdelta)) / (temp);
				}
				else if ((tab[0] > 0 && tab[1] < 0 && tab[2] < 0) || (tab[0] > 0 && tab[1] > 0 && tab[2] < 0))
				{
					x1u = (sqrt(tab[1] + pdelta)) / (temp);
					x2u = -(sqrt(tab[1] + pdelta)) / (temp);
				}
				else
				{
					x1u = sqrt((sqrt(a*a + ai * ai) - a) / 2);
					x2u = sqrt((sqrt(a*a + ai * ai) - a) / 2);
					x3u = -sqrt((sqrt(b*b + bi * bi) - b) / 2);
					x4u = -sqrt((sqrt(b*b + bi * bi) - b) / 2);
				}
			}
		}
	}
	else if (err > 0.1)
	{
		if (delta == 0)
			pdelta = 0;
		else
			pdelta = sqrt_Newton(delta, err);

		if (tab[0] == 0 && tab[1] != 0 && tab[2] != 0)
		{
			a = tab[1];
			b = tab[2];

			std::vector<int> tab2;

			tab2.push_back(a);
			tab2.push_back(tab[0]);
			tab2.push_back(b);

			double deltaN = oblicz_delte(tab2);
			if ((tab[1] > 0 && tab[2] < 0) || (tab[1] < 0 && tab[2] > 0))
			{
			}
			else
			{
				x1u = (tab[0] + sqrt_Newton(deltaN, err)) / (2 * a);
				x2u = (tab[0] - sqrt_Newton(deltaN, err)) / (2 * a);
			}
		}
		else if (tab[2] == 0)
		{
			if (tab[1] < 0 && tab[2] == 0)
			{
				a = tab[0];
				b = tab[1];

				std::vector<int> tab2;
				tab[0] = a;
				tab[1] = b;
				tab[2] = tab[2];

				tab2.push_back(a);
				tab2.push_back(b);
				tab2.push_back(tab[2]);

				double deltaN = oblicz_delte(tab2);
				ai = (-b + sqrt_Newton(deltaN, err)) / (2 * a);
				if (ai < 0)
					ai *= -1;
			}
			else
			{
				pdelta = sqrt_Newton(delta, err);
				a = (-tab[1] + pdelta) / (2 * temp);
				b = (-tab[1] - pdelta) / (2 * temp);
				if (b < 0)
					b *= -1;
				x1u = sqrt_Newton(b, err);
				x2u = -sqrt_Newton(b, err);
			}
		}
		else
		{
			pdelta = sqrt(delta);
			a = -tab[1] / (2 * temp);
			b = -tab[1] / (2 * temp);
			ai = pdelta / (2 * temp);
			bi = -pdelta / (2 * temp);
			if ((tab[0] > 0 && tab[1] == 0 && tab[2] < 0) || (tab[0] < 0 && tab[1] == 0 && tab[2] > 0))
			{
				double t1, t2;
				t1 = tab[2];
				t2 = tab[0];
				a = t1 / t2;
				if (a < 0)
					b = -a;
				else
					b = a;
				x1u = sqrt_Newton(sqrt_Newton(b, err), err);
				x2u = -sqrt_Newton(sqrt_Newton(b, err), err);
			}
			else
			{
				if ((tab[0] < 0 && tab[1] > 0 && tab[2] > 0) || (tab[0] < 0 && tab[1] < 0 && tab[2] > 0))
				{
					x1u = (sqrt_Newton((-tab[1] + pdelta), err)) / (temp);
					x2u = -(sqrt_Newton((-tab[1] + pdelta), err)) / (temp);
				}
				else if ((tab[0] > 0 && tab[1] < 0 && tab[2] < 0) || (tab[0] > 0 && tab[1] > 0 && tab[2] < 0))
				{
					x1u = (sqrt_Newton((tab[1] + pdelta), err)) / (temp);
					x2u = -(sqrt_Newton((tab[1] + pdelta), err)) / (temp);
				}
				else
				{
					x1u = sqrt_Newton(((sqrt_Newton((a*a + ai * ai), err) - a) / 2), err);
					x2u = sqrt_Newton(((sqrt_Newton((a*a + ai * ai), err) - a) / 2), err);
					x3u = -sqrt_Newton(((sqrt_Newton((b*b + bi * bi), err) - b) / 2), err);
					x4u = -sqrt_Newton(((sqrt_Newton((b*b + bi * bi), err) - b) / 2), err);
				}
			}
		}
	}
	else if (err > 0 && err <= 0.1)
	{
		if (delta == 0)
			pdelta = 0;
		else
			pdelta = sqrt_Heron(delta, err);

		if (tab[0] == 0 && tab[1] != 0 && tab[2] != 0)
		{
			a = tab[1];
			b = tab[2];

			std::vector<int> tab2;

			tab2.push_back(a);
			tab2.push_back(tab[0]);
			tab2.push_back(b);

			double deltaN = oblicz_delte(tab2);
			if ((tab[1] > 0 && tab[2] < 0) || (tab[1] < 0 && tab[2] > 0))
			{

			}
			else
			{
				x1u = (tab[0] + sqrt_Heron(deltaN, err)) / (2 * a);
				x2u = (tab[0] - sqrt_Heron(deltaN, err)) / (2 * a);
			}
		}
		else if (tab[2] == 0)
		{
			if (tab[1] < 0 && tab[2] == 0)
			{
				a = tab[0];
				b = tab[1];

				std::vector<int> tab2;

				tab2.push_back(a);
				tab2.push_back(b);
				tab2.push_back(tab[2]);

				double deltaN = oblicz_delte(tab2);
				ai = (-b + sqrt_Heron(deltaN, err)) / (2 * a);
				if (ai < 0)
					ai *= -1;
			}
			else
			{
				pdelta = sqrt_Heron(delta, err);
				a = (-tab[1] + pdelta) / (2 * temp);
				b = (-tab[1] - pdelta) / (2 * temp);
				if (b < 0)
					b *= -1;
				x1u = sqrt_Heron(b, err);
				x2u = -sqrt_Heron(b, err);
			}
		}
		else
		{
			pdelta = sqrt(delta);
			a = -tab[1] / (2 * temp);
			b = -tab[1] / (2 * temp);
			ai = pdelta / (2 * temp);
			bi = -pdelta / (2 * temp);
			if ((tab[0] > 0 && tab[1] == 0 && tab[2] < 0) || (tab[0] < 0 && tab[1] == 0 && tab[2] > 0))
			{
				double t1, t2;
				t1 = tab[2];
				t2 = tab[0];
				a = t1 / t2;
				if (a < 0)
					b = -a;
				else
					b = a;
				x1u = sqrt_Heron(sqrt_Heron(b, err), err);
				x2u = -sqrt_Heron(sqrt_Heron(b, err), err);
			}
			else
			{
				if ((tab[0] < 0 && tab[1] > 0 && tab[2] > 0) || (tab[0] < 0 && tab[1] < 0 && tab[2] > 0))
				{
					x1u = (sqrt_Heron((-tab[1] + pdelta), err)) / (temp);
					x2u = -(sqrt_Heron((-tab[1] + pdelta), err)) / (temp);
				}
				else if ((tab[0] > 0 && tab[1] < 0 && tab[2] < 0) || (tab[0] > 0 && tab[1] > 0 && tab[2] < 0))
				{
					x1u = (sqrt_Heron((tab[1] + pdelta), err)) / (temp);
					x2u = -(sqrt_Heron((tab[1] + pdelta), err)) / (temp);
				}
				else
				{
					x1u = sqrt_Heron(((sqrt_Heron((a*a + ai * ai), err) - a) / 2), err);
					x2u = sqrt_Heron(((sqrt_Heron((a*a + ai * ai), err) - a) / 2), err);
					x3u = -sqrt_Heron(((sqrt_Heron((b*b + bi * bi), err) - b) / 2), err);
					x4u = -sqrt_Heron(((sqrt_Heron((b*b + bi * bi), err) - b) / 2), err);
				}
			}
		}
	}
}

void LiczbaZ::dodaj_liczby_zespolone()
{
	su = x1u + x2u + x3u + x4u;
}

void LiczbaZ::odejmij_liczby_zespolone()
{
	ru = x1u - x2u - x3u - x4u;
}

double LiczbaZ::oblicz_delte(std::vector<int> tab)
{
	double delta;
	if (tab[0] == 0 && tab[1] == 0)
	{
		return 0;
	}
	delta = (tab[1] * tab[1]) - (4 * tab[0] * tab[2]);
	if (delta < 0)
	{
		delta *= -1;
	}
	return delta;
}

double LiczbaZ::sqrt_Newton(double d, double err)
{
	double a;
	if (tab[0] == 0 && tab[1] == 0)
	{
		return 0;
	}
	if (d == 0)
	{
		a = 0;
		return a;
	}
	a = d / 2;
	for (;;)
	{
		a = (d / a + a) / 2;
		if ((fabs(d / a - a) < err))
			break;
	}
	return a;
}

double LiczbaZ::sqrt_Heron(double d, double err)
{
	double x0 = 1;
	double x = x0;
	if (tab[0] == 0 && tab[1] == 0)
	{
		return 0;
	}
	if (d == 0)
	{
		x = 0;
		return x;
	}
	for (;;)
	{
		x0 = x;
		x = (x0 + d / x0) / 2;
		if (fabs(x - x0) < err)
			break;
	}
	return x;
}

float LiczbaZ::getX1u()
{
	return this->x1u;
}

float LiczbaZ::getX2u()
{
	return this->x2u;
}

float LiczbaZ::getX3u()
{
	return this->x3u;
}

float LiczbaZ::getX4u()
{
	return this->x4u;
}

float LiczbaZ::getSu()
{
	return this->su;
}

float LiczbaZ::getRu()
{
	return this->ru;
}