#define _USE_MATH_DEFINES

#include "figure.h"
#include <iostream>
#include <math.h>

using namespace std;

Figure::Figure(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
	this->x1 = x1; this->y1 = y1;
	this->x2 = x2; this->y2 = y2;
	this->x3 = x3; this->y3 = y3;
	this->x4 = x4; this->y4 = y4;

	a = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	b = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
	c = sqrt(pow((x4 - x3), 2) + pow((y4 - y3), 2));
	d = sqrt(pow((x1 - x4), 2) + pow((y1 - y4), 2));

	P = a + b + c + d;
	S = square();
}

void Figure::show() {
	cout << "Координаты вершины 1: " << "(" << x1 << ", " << y1 << ")" << endl;
	cout << "Координаты вершины 2: " << "(" << x2 << ", " << y2 << ")" << endl;
	cout << "Координаты вершины 3: " << "(" << x3 << ", " << y3 << ")" << endl;
	cout << "Координаты вершины 4: " << "(" << x4 << ", " << y4 << ")" << endl;
	
	cout << "Длина стороны a: " << a << endl;
	cout << "Длина стороны b: " << b << endl;
	cout << "Длина стороны c: " << c << endl;
	cout << "Длина стороны d: " << d << endl;
	
	cout << "Периметр: " << P << endl;
	if (S > 0)
		cout << "Площадь: " << S << endl;
	else
		cout << "Для расчёта площади недостаточно входных данных." << endl;
}

float Figure::square() {
	if (is_rectangle())
		return a * b;
	else if (is_romb()) {
		float d1 = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
		float d2 = sqrt(pow((x4 - x2), 2) + pow((y4 - y2), 2));
		return 0.5 * d1 * d2;
	}
	else if (is_in_circle())
		return sqrt((P / 2 - a) * (P / 2 - b) * (P / 2 - c) * (P / 2 - d));
	else
		return 0;
}

bool Figure::is_prug() {
	return (a < b + c + d) and
		   (b < a + c + d) and
		   (c < a + b + d) and
		   (d < a + b + c);
}

bool Figure::is_rectangle() {
	float diagonal_sq = pow((x3 - x1), 2) + pow((y3 - y1), 2);
	return a == c and b == d and diagonal_sq == pow(a, 2) + pow(b, 2);
}

bool Figure::is_romb() {
	return a == b and b == c and c == d and d == a;
}

bool Figure::is_square() {
	return is_rectangle() and is_romb();
}

bool Figure::is_in_circle() {

	float cosA = ((x2 - x1) * (x4 - x1) + (y2 - y1) * (y4 - y1)) / (a * d);
	float cosB = ((x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2)) / (a * b);
	float cosC = ((x2 - x3) * (x4 - x3) + (y2 - y3) * (y4 - y3)) / (b * c);
	float cosD = ((x3 - x4) * (x1 - x4) + (y3 - y4) * (y1 - y4)) / (c * d);
	
	float angleA = acos(cosA);
	float angleB = acos(cosB);
	float angleC = acos(cosC);
	float angleD = acos(cosD);
	
	return angleA + angleC == angleB + angleD and
		   PI_M_DELTA <= angleB + angleD and angleB + angleD <= PI_P_DELTA;
}

bool Figure::is_out_circle() {
	return a + c == b + d;
}
