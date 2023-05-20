#pragma once
#include "sea.h"

class Bay : public Sea {

protected:
	string name;		// название
	string location;	// местоположение
	double area;		// площадь поверхности
	double depth;		// глубина

	friend ostream& operator <<(ostream& out, Bay b);
	friend istream& operator >>(istream& in, Bay& b);

public:
	Bay();
	Bay(string n, string l, double a, double d,
		string n_sea, string l_sea, double a_sea, double d_sea,
		string n_ocean, string l_ocean, double a_ocean, double d_ocean);

	string getName();
	string getLocation();
	double getArea();
	double getDepth();

	void show();

}; // end of Bay
