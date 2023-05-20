#pragma once
#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>

using namespace std;

const double PI = M_PI;

class Cone {

protected:
    double x, y, z; // координаты центра основания
    double radius;  // радиус
    double height;  // высота

    friend ostream& operator <<(ostream& out, Cone c);

public:
    Cone();
    Cone(double r, double h); // конструктор конуса с центром в начале координат
    Cone(double x, double y, double z, double r, double h); // конструктор произвольного конуса

    // Функции доступа
    void setCoordinate(double x, double y, double z);
    void setRadius(double r);
    void setHeight(double h);
    double getRadius();
    double getHeight();

    double area(); // площадь полной поверхности
    double volume(); // объём

}; // end of Cone
