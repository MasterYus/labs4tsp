#include "ocean.h"
#include <iostream>

using namespace std;

Ocean::Ocean() {
	name = "";
	location = "";
	area = 0;
	depth = 0;
}

Ocean::Ocean(string n, string l, double a, double d) {
	name = n;
	location = l;
	area = a;
	depth = d;
}

Ocean::Ocean(Ocean& o) {
	name = o.name;
	location = o.location;
	area = o.area;
	depth = o.depth;
}

string Ocean::getName() { return name; }

string Ocean::getLocation() { return location; }

double Ocean::getArea() { return area; }

double Ocean::getDepth() { return depth; }

void Ocean::show() {
	cout << "Океан " << name << ":" << endl;
	cout << "-- местоположение: " << location << endl;
	cout << "-- площадь поверхности: " << area << " кв. км" << endl;
	cout << "-- глубина: " << depth << " м" << endl;
}

ostream& operator <<(ostream& out, Ocean o) {
	out << "Океан " << o.name << ":" << endl;
	out << "-- местоположение: " << o.location << endl;
	out << "-- площадь поверхности: " << o.area << " кв. км" << endl;
	out << "-- глубина: " << o.depth << " м" << endl;
	return out;
}

istream& operator >>(istream& in, Ocean& o) {
	cout << "Введите название океана: ";
	in >> o.name;
	cout << "Введите местоположение океана: ";
	in >> o.location;
	cout << "Введите площадь поверхности океана в кв. км: ";
	in >> o.area;
	cout << "Введите глубину океана в метрах: ";
	in >> o.depth;
	return in;
}
