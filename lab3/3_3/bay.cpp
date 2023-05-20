#include "bay.h"
#include <iostream>

using namespace std;

Bay::Bay() {
	name = "";
	location = "";
	area = 0;
	depth = 0;
}

Bay::Bay(string n, string l, double a, double d,
	string n_sea, string l_sea, double a_sea, double d_sea,
	string n_ocean, string l_ocean, double a_ocean, double d_ocean
) : Sea(n_sea, l_sea, a_sea, d_sea, n_ocean, l_ocean, a_ocean, d_ocean) {
	name = n;
	location = l;
	area = a;
	depth = d;
}

string Bay::getName() { return name; }

string Bay::getLocation() { return location; }

double Bay::getArea() { return area; }

double Bay::getDepth() { return depth; }

void Bay::show() {
	cout << "Залив " << name << ":" << endl;

	if (Sea::name == "" and Sea::location == "" and Sea::area == 0 and Sea::depth == 0) {
		cout << "- не принадлежит никакому морю" << endl;
		cout << "- принадлежит океану \"" << Ocean::name << "\"" << endl;
		cout << "***" << endl; Ocean::show(); cout << "***" << endl;
	}
	else {
		cout << "- принадлежит морю \"" << Sea::name << "\"" << endl;
		cout << "***" << endl; Sea::show(); cout << "***" << endl;
	}

	cout << "-- местоположение: " << location << endl;
	cout << "-- площадь поверхности: " << area << " кв. км" << endl;
	cout << "-- глубина: " << depth << " м" << endl;
}

ostream& operator <<(ostream& out, Bay b) {
	out << "Залив " << b.name << ":" << endl;
	out << "-- местоположение: " << b.location << endl;
	out << "-- площадь поверхности: " << b.area << " кв. км" << endl;
	out << "-- глубина: " << b.depth << " м" << endl;
	return out;
}

istream& operator >>(istream& in, Bay& b) {
	string choise;
	cout << "Принадлежит ли залив какому-нибудь морю? (да/нет): ";
	in >> choise;

	if (choise == "нет") {
		b.Sea::name = "";
		b.Sea::location = "";
		b.Sea::area = 0;
		b.Sea::depth = 0;
	}
	else if (choise == "да") {
		cout << "- Укажите море, которому принадлежит залив:" << endl;
		cout << "-- Название моря: ";
		in >> b.Sea::name;
		cout << "-- Местоположение моря: ";
		in >> b.Sea::location;
		cout << "-- Площадь поверхности моря в кв. км: ";
		in >> b.Sea::area;
		cout << "-- Глубину моря в метрах: ";
		in >> b.Sea::depth;
	}

	cout << "- Укажите океан, которому принадлежит залив:" << endl;
	cout << "-- Название океана: ";
	in >> b.Ocean::name;
	cout << "-- Местоположение океана: ";
	in >> b.Ocean::location;
	cout << "-- Площадь поверхности океана в кв. км: ";
	in >> b.Ocean::area;
	cout << "-- Глубину океана в метрах: ";
	in >> b.Ocean::depth;

	cout << "Введите название залива: ";
	in >> b.name;
	cout << "Введите местоположение залива: ";
	in >> b.location;
	cout << "Введите площадь поверхности залива в кв. км: ";
	in >> b.area;
	cout << "Введите глубину залива в метрах: ";
	in >> b.depth;

	return in;
}
