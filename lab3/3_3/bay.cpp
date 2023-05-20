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
	cout << "����� " << name << ":" << endl;

	if (Sea::name == "" and Sea::location == "" and Sea::area == 0 and Sea::depth == 0) {
		cout << "- �� ����������� �������� ����" << endl;
		cout << "- ����������� ������ \"" << Ocean::name << "\"" << endl;
		cout << "***" << endl; Ocean::show(); cout << "***" << endl;
	}
	else {
		cout << "- ����������� ���� \"" << Sea::name << "\"" << endl;
		cout << "***" << endl; Sea::show(); cout << "***" << endl;
	}

	cout << "-- ��������������: " << location << endl;
	cout << "-- ������� �����������: " << area << " ��. ��" << endl;
	cout << "-- �������: " << depth << " �" << endl;
}

ostream& operator <<(ostream& out, Bay b) {
	out << "����� " << b.name << ":" << endl;
	out << "-- ��������������: " << b.location << endl;
	out << "-- ������� �����������: " << b.area << " ��. ��" << endl;
	out << "-- �������: " << b.depth << " �" << endl;
	return out;
}

istream& operator >>(istream& in, Bay& b) {
	string choise;
	cout << "����������� �� ����� ������-������ ����? (��/���): ";
	in >> choise;

	if (choise == "���") {
		b.Sea::name = "";
		b.Sea::location = "";
		b.Sea::area = 0;
		b.Sea::depth = 0;
	}
	else if (choise == "��") {
		cout << "- ������� ����, �������� ����������� �����:" << endl;
		cout << "-- �������� ����: ";
		in >> b.Sea::name;
		cout << "-- �������������� ����: ";
		in >> b.Sea::location;
		cout << "-- ������� ����������� ���� � ��. ��: ";
		in >> b.Sea::area;
		cout << "-- ������� ���� � ������: ";
		in >> b.Sea::depth;
	}

	cout << "- ������� �����, �������� ����������� �����:" << endl;
	cout << "-- �������� ������: ";
	in >> b.Ocean::name;
	cout << "-- �������������� ������: ";
	in >> b.Ocean::location;
	cout << "-- ������� ����������� ������ � ��. ��: ";
	in >> b.Ocean::area;
	cout << "-- ������� ������ � ������: ";
	in >> b.Ocean::depth;

	cout << "������� �������� ������: ";
	in >> b.name;
	cout << "������� �������������� ������: ";
	in >> b.location;
	cout << "������� ������� ����������� ������ � ��. ��: ";
	in >> b.area;
	cout << "������� ������� ������ � ������: ";
	in >> b.depth;

	return in;
}
