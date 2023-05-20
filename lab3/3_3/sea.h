#pragma once
#include "ocean.h"

class Sea : public Ocean {

protected:
	string name;		// ��������
	string location;	// ��������������
	double area;		// ������� �����������
	double depth;		// �������

	friend ostream& operator <<(ostream& out, Sea s);
	friend istream& operator >>(istream& in, Sea& s);

public:
	Sea();
	Sea(string n, string l, double a, double d);
	Sea(string n, string l, double a, double d, string n_ocean, string l_ocean, double a_ocean, double d_ocean);
	Sea(string n, string l, double a, double d, Ocean& o);

	string getName();
	string getLocation();
	double getArea();
	double getDepth();

	void show();

}; // end of Sea
