#pragma once
class Complex
{
public:
	Complex(double r, double i) { re = r, im = i; }
	Complex(double r) { re = r, im = 0; }
	Complex() { re = im = 0; }
	~Complex();

	friend Complex operator+(Complex x, Complex y);
	friend Complex operator-(Complex x, Complex y);
	friend Complex operator*(Complex x, Complex y);
private:
	double re, im;
};

