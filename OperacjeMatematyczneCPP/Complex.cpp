#include <iostream>
#include <cmath>

class Complex {
public:
    double re, im;

    Complex(double r = 0, double i = 0) : re(r), im(i) {}

    Complex operator+(Complex x) {
        return Complex(re + x.re, im + x.im);
    }

    Complex operator-(Complex x) {
        return Complex(re - x.re, im - x.im);
    }

    Complex operator*(Complex x) {
        return Complex(re * x.re, im * x.im);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.re << " + " << c.im << "i";
        return os;
    }
};
