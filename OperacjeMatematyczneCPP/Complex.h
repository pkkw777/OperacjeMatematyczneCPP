#pragma once

class Complex {
public:
    Complex(double r = 0.0, double i = 0.0) : re(r), im(i) {}
    ~Complex() {}

    Complex operator+(Complex& rhs) {
        return Complex(re + rhs.re, im + rhs.im);
    }

    Complex operator-(Complex& rhs) {
        return Complex(re - rhs.re, im - rhs.im);
    }

    Complex operator*(Complex& rhs) {
        return Complex(re * rhs.re - im * rhs.im, re * rhs.im + im * rhs.re);
    }

private:
    double re, im;
};
