#include "Complex.h"



//Complex::Complex()
//{
//}


Complex::~Complex()
{
}

Complex operator+(Complex x, Complex y)
{
	return Complex(x.re + y.re, x.im + y.im);
}

Complex operator-(Complex x, Complex y)
{
	return Complex(x.re - y.re, x.im - y.im);
}

Complex operator*(Complex x, Complex y)
{
	return Complex(x.re * y.re, x.im * y.im);
}