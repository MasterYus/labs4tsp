#pragma once

#include "../3_1/cone.h"
#include <map>

class Frustum : Cone {

private:
	double radius;	// ������ �������� ���������
	double height;	// ������ �� ������ �������� ��������� �� ������ ��������

	friend ostream& operator <<(ostream& out, Frustum f);
	friend istream& operator >>(istream& in, Frustum &f);

public:
	Frustum();
	Frustum(double r, double h, double h2); // ����������� ���������� ������ � ������� �������� ��������� � ������ ���������
	Frustum(double x, double y, double z, double r, double h, double h2); // ����������� ������������� ���������� ������
	Frustum(Cone& C, double h2); // ����������� �����������

	// ������� �������
	void setRadius(double r);
	void setHeight(double h);
	double getRadiusFrustum();
	
	double area(); // ������� ������ �����������
	double volume(); // �����
	map<string, bool> compare(Frustum& f2); // ����� ��������� �������
};
