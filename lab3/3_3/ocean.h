#pragma once
#include <string>

using namespace std;

class Ocean {

protected:
	string name;		// название
	string location;	// местоположение
	double area;		// площадь поверхности
	double depth;		// глубина

	friend ostream& operator <<(ostream& out, Ocean o);
	friend istream& operator >>(istream& in, Ocean& o);

public:
	Ocean();
	Ocean(string n, string l, double a, double d);
	Ocean(Ocean& o);

	string getName();
	string getLocation();
	double getArea();
	double getDepth();

	void show();

}; // end of Ocean
