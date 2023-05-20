#pragma once
#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>

using namespace std;

const double PI = M_PI;

class Cone {

protected:
    double x, y, z; // ���������� ������ ���������
    double radius;  // ������
    double height;  // ������

    friend ostream& operator <<(ostream& out, Cone c);

public:
    Cone();
    Cone(double r, double h); // ����������� ������ � ������� � ������ ���������
    Cone(double x, double y, double z, double r, double h); // ����������� ������������� ������

    // ������� �������
    void setCoordinate(double x, double y, double z);
    void setRadius(double r);
    void setHeight(double h);
    double getRadius();
    double getHeight();

    double area(); // ������� ������ �����������
    double volume(); // �����

}; // end of Cone
