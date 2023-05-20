#include "triangle.h"
#include <iostream>

bool Triangle::exst_tr() {
	return ((a < b + c) and (b < a + c) and (c < a + b));
}

void Triangle::set(double a, double b, double c) {
	this->a = a;
	this->b = b;
	this->c = c;
}

void Triangle::show() {
	std::cout << "Сторона a: " << a << std::endl;
	std::cout << "Сторона b: " << b << std::endl;
	std::cout << "Сторона c: " << c << std::endl;
}

double Triangle::perimetr() {
	return a + b + c;
}

double Triangle::square() {
	double p = perimetr() / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
