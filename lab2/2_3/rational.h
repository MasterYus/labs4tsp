#pragma once

class Rational {

private:
	int a, b; // числитель и знаменатель

	friend Rational operator -(Rational& r1, Rational& r2);
	friend bool operator ==(Rational& r1, Rational& r2);
	friend bool operator >(Rational& r1, Rational& r2);

public:
	Rational();
	Rational(int a, int b);
	void set(int a, int b);
	void show();
	Rational operator +(Rational& r);
	Rational& operator ++();
	Rational& operator ++(const int);
	Rational& operator =(Rational const& r);

}; // end of Rational
