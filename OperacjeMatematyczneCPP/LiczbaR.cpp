#include "LiczbaR.h"

LiczbaR::LiczbaR()
{
	delta = 0;
	pdelta = 0;
	err = 0;
	a = 0;
	b = 0;
	c = 0;
	x1r = 0;
	x2r = 0;
	x3r = 0;
	x4r = 0;
	sr = 0;
	rr = 0;
}

LiczbaR::~LiczbaR()
{
	tab.clear();
}

void LiczbaR::WyswietlRownanie()
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

void LiczbaR::ObliczPierwiastekRownania()
{
	double a = 0, b = 0, ai = 0, bi = 0;
	double temp = tab[0];
	delta = ObliczDelte(tab);

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
			double deltaN = ObliczDelte(tab2);
			if ((tab[1] > 0 && tab[2] < 0) || (tab[1] < 0 && tab[2] > 0))
			{
				x1r = (tab[0] + sqrt(deltaN)) / (2 * a);
				x2r = (tab[0] - sqrt(deltaN)) / (2 * a);
			}
			else
			{

			}
		}
		else if (tab[2] == 0)
		{
			if (tab[1] < 0 && tab[2] == 0)
			{
				a = tab[0];
				b = tab[1];

				std::vector<int> tab2;
				tab2[0] = a;
				tab2[1] = b;
				tab2[2] = tab[2];

				tab2.push_back(a);
				tab2.push_back(b);
				tab2.push_back(tab[2]);

				double deltaN = ObliczDelte(tab2);
				ai = (-b + sqrt(deltaN)) / (2 * a);
				if (ai < 0)
					ai *= -1;
				x1r = sqrt(ai);
				x2r = -sqrt(ai);
				x3r = (-b - sqrt(deltaN)) / (2 * a);
			}
			else
			{
				pdelta = sqrt(delta);
				a = (-tab[1] + pdelta) / (2 * temp);
				b = (-tab[1] - pdelta) / (2 * temp);
				x1r = a;
				x2r = a;
				if (b < 0)
					b *= -1;

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
				x1r = sqrt(sqrt(b));
				x2r = -sqrt(sqrt(b));

			}
			else
			{
				if ((tab[0] < 0 && tab[1] > 0 && tab[2] > 0) || (tab[0] < 0 && tab[1] < 0 && tab[2] > 0))
				{
					x1r = (sqrt(tab[1] + pdelta)) / (temp);
					x2r = -(sqrt(tab[1] + pdelta)) / (temp);
				}
				else if ((tab[0] > 0 && tab[1] < 0 && tab[2] < 0) || (tab[0] > 0 && tab[1] > 0 && tab[2] < 0))
				{
					x1r = (sqrt(-tab[1] + pdelta)) / (temp);
					x2r = -(sqrt(-tab[1] + pdelta)) / (temp);
				}
				else
				{
					x1r = sqrt((sqrt(a*a + ai * ai) + a) / 2);
					x2r = -sqrt((sqrt(a*a + ai * ai) + a) / 2);
					x3r = sqrt((sqrt(b*b + bi * bi) + b) / 2);
					x4r = -sqrt((sqrt(b*b + bi * bi) + b) / 2);
				}

			}
		}
	}
	else if (err > 0.1)
	{
		if (delta == 0)
			pdelta = 0;
		else
			pdelta = SqrtNewton(delta, err);

		if (tab[0] == 0 && tab[1] != 0 && tab[2] != 0)
		{
			a = tab[1];
			b = tab[2];

			std::vector<int> tab2;

			tab2.push_back(a);
			tab2.push_back(tab[0]);
			tab2.push_back(b);


			double deltaN = ObliczDelte(tab2);
			if ((tab[1] > 0 && tab[2] < 0) || (tab[1] < 0 && tab[2] > 0))
			{
				x1r = (tab[0] + SqrtNewton(deltaN, err)) / (2 * a);
				x2r = (tab[0] - SqrtNewton(deltaN, err)) / (2 * a);
			}
			else
			{

			}
		}
		else if (tab[0] != 0 && tab[1] == 0 && tab[2] > 0)
		{
			double t1, t2;
			t1 = tab[2];
			t2 = tab[0];
			a = t1 / t2;
			b = -a;
			a = b;
			x1r = SqrtNewton(SqrtNewton(b, err), err);
			x2r = -SqrtNewton(SqrtNewton(b, err), err);
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


				double deltaN = ObliczDelte(tab2);
				ai = (-b + SqrtNewton(deltaN, err)) / (2 * a);
				if (ai < 0)
					ai *= -1;
				x1r = SqrtNewton(ai, err);
				x2r = -SqrtNewton(ai, err);
				x3r = (-b - SqrtNewton(deltaN, err)) / (2 * a);
			}
			else
			{
				pdelta = SqrtNewton(delta, err);
				a = (-tab[1] + pdelta) / (2 * temp);
				b = (-tab[1] - pdelta) / (2 * temp);
				x1r = a;
				x2r = a;
				if (b < 0)
					b *= -1;
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
				x1r = SqrtNewton(SqrtNewton(b, err), err);
				x2r = -SqrtNewton(SqrtNewton(b, err), err);
			}
			else
			{
				if ((tab[0] < 0 && tab[1] > 0 && tab[2] > 0) || (tab[0] < 0 && tab[1] < 0 && tab[2] > 0))
				{
					x1r = (SqrtNewton((tab[1] + pdelta), err)) / (temp);
					x2r = -(SqrtNewton((tab[1] + pdelta), err)) / (temp);
				}
				else if ((tab[0] > 0 && tab[1] < 0 && tab[2] < 0) || (tab[0] > 0 && tab[1] > 0 && tab[2] < 0))
				{
					x1r = (SqrtNewton((-tab[1] + pdelta), err)) / (temp);
					x2r = -(SqrtNewton((-tab[1] + pdelta), err)) / (temp);
				}
				else
				{
					x1r = SqrtNewton(((SqrtNewton((a*a + ai * ai), err) + a) / 2), err);
					x2r = -SqrtNewton(((SqrtNewton((a*a + ai * ai), err) + a) / 2), err);
					x3r = SqrtNewton(((SqrtNewton((b*b + bi * bi), err) + b) / 2), err);
					x4r = -SqrtNewton(((SqrtNewton((b*b + bi * bi), err) + b) / 2), err);
				}
			}
		}
	}
	else if (err > 0 && err <= 0.1)
	{
		if (delta == 0)
			pdelta = 0;
		else
			pdelta = SqrtHeron(delta, err);

		if (tab[0] == 0 && tab[1] != 0 && tab[2] != 0)
		{
			a = tab[1];
			b = tab[2];

			std::vector<int> tab2;
			tab2.push_back(a);
			tab2.push_back(tab[0]);
			tab2.push_back(b);


			double deltaN = ObliczDelte(tab2);
			if ((tab[1] > 0 && tab[2] < 0) || (tab[1] < 0 && tab[2] > 0))
			{
				x1r = (tab[0] + SqrtHeron(deltaN, err)) / (2 * a);
				x2r = (tab[0] - SqrtHeron(deltaN, err)) / (2 * a);
			}
			else
			{
			}
		}
		else if (tab[0] != 0 && tab[1] == 0 && tab[2] > 0)
		{
			double t1, t2;
			t1 = tab[2];
			t2 = tab[0];
			a = t1 / t2;
			b = -a;
			a = b;
			x1r = SqrtHeron(SqrtHeron(b, err), err);
			x2r = -SqrtHeron(SqrtHeron(b, err), err);
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

				double deltaN = ObliczDelte(tab2);
				ai = (-b + SqrtHeron(deltaN, err)) / (2 * a);
				if (ai < 0)
					ai *= -1;
				x1r = SqrtHeron(ai, err);
				x2r = -SqrtHeron(ai, err);
				x3r = (-b - SqrtHeron(deltaN, err)) / (2 * a);
			}
			else
			{
				pdelta = SqrtHeron(delta, err);
				a = (-tab[1] + pdelta) / (2 * temp);
				b = (-tab[1] - pdelta) / (2 * temp);
				x1r = a;
				x2r = a;
				if (b < 0)
					b *= -1;
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
				x1r = SqrtHeron(SqrtHeron(b, err), err);
				x2r = -SqrtHeron(SqrtHeron(b, err), err);
			}
			else
			{
				if ((tab[0] < 0 && tab[1] > 0 && tab[2] > 0) || (tab[0] < 0 && tab[1] < 0 && tab[2] > 0))
				{
					x1r = (SqrtHeron((tab[1] + pdelta), err)) / (temp);
					x2r = -(SqrtHeron((tab[1] + pdelta), err)) / (temp);
				}
				else if ((tab[0] > 0 && tab[1] < 0 && tab[2] < 0) || (tab[0] > 0 && tab[1] > 0 && tab[2] < 0))
				{
					x1r = (SqrtHeron((-tab[1] + pdelta), err)) / (temp);
					x2r = -(SqrtHeron((-tab[1] + pdelta), err)) / (temp);
				}
				else
				{
					x1r = SqrtHeron(((SqrtHeron((a*a + ai * ai), err) + a) / 2), err);
					x2r = -SqrtHeron(((SqrtHeron((a*a + ai * ai), err) + a) / 2), err);
					x3r = SqrtHeron(((SqrtHeron((b*b + bi * bi), err) + b) / 2), err);
					x4r = -SqrtHeron(((SqrtHeron((b*b + bi * bi), err) + b) / 2), err);
				}
			}
		}
	}
}

void LiczbaR::DodajLiczbyZespolone()
{
	sr = x1r + x2r + x3r + x4r;
}

void LiczbaR::OdejmijLiczbyZespolone()
{
	rr = x1r - x2r - x3r - x4r;
}

double LiczbaR::ObliczDelte(std::vector<int> tab)
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

double LiczbaR::SqrtNewton(double d, double err)
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

double LiczbaR::SqrtHeron(double d, double err)
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

void LiczbaR::initialize()
{

	printf("Podaj dokladnosc: \n");
	scanf_s("%lf", &err);

	printf("Podaj wspolczynnik a:");
	std::cin >> a;
	tab.push_back(a);
	printf("Podaj wspolczynnik b:");
	std::cin >> b;
	tab.push_back(b);
	printf("Podaj wspolczynnik c:");
	std::cin >> c;
	tab.push_back(c);

}

std::vector<int> LiczbaR::getTab()
{
	return this->tab;
}

float LiczbaR::getDelta()
{
	return this->delta;
}

float LiczbaR::getPdelta()
{
	return this->pdelta;
}

float LiczbaR::getErr()
{
	return this->err;
}

float LiczbaR::getX1r()
{
	return this->x1r;
}

float LiczbaR::getX2r()
{
	return this->x2r;
}

float LiczbaR::getX3r()
{
	return this->x3r;
}

float LiczbaR::getX4r()
{
	return this->x4r;
}

float LiczbaR::getSr()
{
	return this->sr;
}

float LiczbaR::getRr()
{
	return this->rr;
}