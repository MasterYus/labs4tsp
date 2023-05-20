#include "rational.h"
#include <iostream>

using namespace std;

Rational::Rational() {
	a = 0;
	b = 0;
}

Rational::Rational(int a, int b) {
	if (b == 0) {
		cout << "Знаменатель дроби не может быть равен нулю!" << endl;
		delete this;
		return;
	}
	
	int divider = b;
	while (divider > 1) {
		if (a % divider == 0 and b % divider == 0) {
			a /= divider;
			b /= divider;
		}

		divider--;
	}

	this->a = a;
	this->b = b;

	if (a > b) {
		this->a = a - b * (a / b);
		this->b = b;
	}
}

void Rational::set(int a, int b) {
	if (b == 0) {
		cout << "Знаменатель дроби не может быть равен нулю!" << endl;
		return;
	}

	int divider = b;
	while (divider > 1) {
		if (a % divider == 0 and b % divider == 0) {
			a /= divider;
			b /= divider;
		}

		divider--;
	}

	this->a = a;
	this->b = b;

	if (a > b) {
		this->a = a - b * (a / b);
		this->b = b;
	}
}

void Rational::show() {
	cout << a << "/" << b << endl;
}

Rational Rational::operator +(Rational& r) {
	int result_a = this->a * r.b + r.a * this->b;
	int result_b = this->b * r.b;

	Rational result(result_a, result_b);
	return result;
}

Rational operator -(Rational& r1, Rational& r2) {
	int result_a = r1.a * r2.b - r2.a * r1.b;
	int result_b = r1.b * r2.b;

	Rational result(result_a, result_b);
	return result;
}

Rational& Rational::operator ++() {
	a++;
	return *this;
}

Rational& Rational::operator ++(const int) {
	Rational r = *this;
	a++;
	return r;
}

bool operator ==(Rational& r1, Rational& r2) {
	return r1.a == r2.a and r1.b == r2.b;
}

bool operator >(Rational& r1, Rational& r2) {
	return r1.a * r2.b > r2.a * r1.b;
}

Rational& Rational::operator =(Rational const& r) {
	a = r.a;
	b = r.b;
	return *this;
}
