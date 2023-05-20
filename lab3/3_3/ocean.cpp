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
	cout << "����� " << name << ":" << endl;
	cout << "-- ��������������: " << location << endl;
	cout << "-- ������� �����������: " << area << " ��. ��" << endl;
	cout << "-- �������: " << depth << " �" << endl;
}

ostream& operator <<(ostream& out, Ocean o) {
	out << "����� " << o.name << ":" << endl;
	out << "-- ��������������: " << o.location << endl;
	out << "-- ������� �����������: " << o.area << " ��. ��" << endl;
	out << "-- �������: " << o.depth << " �" << endl;
	return out;
}

istream& operator >>(istream& in, Ocean& o) {
	cout << "������� �������� ������: ";
	in >> o.name;
	cout << "������� �������������� ������: ";
	in >> o.location;
	cout << "������� ������� ����������� ������ � ��. ��: ";
	in >> o.area;
	cout << "������� ������� ������ � ������: ";
	in >> o.depth;
	return in;
}
