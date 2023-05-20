#pragma once

#include "../3_1/cone.h"
#include <map>

class Frustum : Cone {

private:
	double radius;	// радиус меньшего основания
	double height;	// высота от центра большего основания до центра меньшего

	friend ostream& operator <<(ostream& out, Frustum f);
	friend istream& operator >>(istream& in, Frustum &f);

public:
	Frustum();
	Frustum(double r, double h, double h2); // конструктор усечённого конуса с центром большего основания в начале координат
	Frustum(double x, double y, double z, double r, double h, double h2); // конструктор произвольного усечённого конуса
	Frustum(Cone& C, double h2); // конструктор копирования

	// Функции доступа
	void setRadius(double r);
	void setHeight(double h);
	double getRadiusFrustum();
	
	double area(); // площадь полной поверхности
	double volume(); // объём
	map<string, bool> compare(Frustum& f2); // метод сравнения конусов
};
