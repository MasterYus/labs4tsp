#include "sea.h"
#include <iostream>

using namespace std;

Sea::Sea() {
	name = "";
	location = "";
	area = 0;
	depth = 0;
}

Sea::Sea(string n, string l, double a, double d) : Ocean() {
	name = n;
	location = l;
	area = a;
	depth = d;
}

Sea::Sea(string n, string l, double a, double d,
		 string n_ocean, string l_ocean, double a_ocean, double d_ocean) : Ocean(n_ocean, l_ocean, a_ocean, d_ocean)
{
	name = n;
	location = l;
	area = a;
	depth = d;
}

Sea::Sea(string n, string l, double a, double d, Ocean& o) : Ocean(o) {
	name = n;
	location = l;
	area = a;
	depth = d;
}

string Sea::getName() { return name; }

string Sea::getLocation() { return location; }

double Sea::getArea() { return area; }

double Sea::getDepth() { return depth; }

void Sea::show() {
	cout << "Море " << name << ":" << endl;

	if (Ocean::name == "" and Ocean::location == "" and Ocean::area == 0 and Ocean::depth == 0) {
		cout << "- является внутренним (не принадлежит никакому океану)" << endl;
	}
	else {
		cout << "- принадлежит океану \"" << Ocean::name << "\"" << endl;
		cout << "***" << endl; Ocean::show(); cout << "***" << endl;
	}

	cout << "-- местоположение: " << location << endl;
	cout << "-- площадь поверхности: " << area << " кв. км" << endl;
	cout << "-- глубина: " << depth << " м" << endl;
}

ostream& operator <<(ostream& out, Sea s) {
	out << "Море " << s.name << ":" << endl;
	out << "-- местоположение: " << s.location << endl;
	out << "-- площадь поверхности: " << s.area << " кв. км" << endl;
	out << "-- глубина: " << s.depth << " м" << endl;
	return out;
}

istream& operator >>(istream& in, Sea& s) {
	string choise;
	cout << "Является ли море внутренним? (да/нет): ";
	in >> choise;

	if (choise == "да") {
		s.Ocean::name = "";
		s.Ocean::location = "";
		s.Ocean::area = 0;
		s.Ocean::depth = 0;
	}
	else if (choise == "нет") {
		cout << "- Укажите океан, которому принадлежит море:" << endl;
		cout << "-- Название океана: ";
		in >> s.Ocean::name;
		cout << "-- Местоположение океана: ";
		in >> s.Ocean::location;
		cout << "-- Площадь поверхности океана в кв. км: ";
		in >> s.Ocean::area;
		cout << "-- Глубину океана в метрах: ";
		in >> s.Ocean::depth;
	}

	cout << "Введите название моря: ";
	in >> s.name;
	cout << "Введите местоположение моря: ";
	in >> s.location;
	cout << "Введите площадь поверхности моря в кв. км: ";
	in >> s.area;
	cout << "Введите глубину моря в метрах: ";
	in >> s.depth;

	return in;
}
