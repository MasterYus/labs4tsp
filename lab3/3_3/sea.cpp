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
	cout << "���� " << name << ":" << endl;

	if (Ocean::name == "" and Ocean::location == "" and Ocean::area == 0 and Ocean::depth == 0) {
		cout << "- �������� ���������� (�� ����������� �������� ������)" << endl;
	}
	else {
		cout << "- ����������� ������ \"" << Ocean::name << "\"" << endl;
		cout << "***" << endl; Ocean::show(); cout << "***" << endl;
	}

	cout << "-- ��������������: " << location << endl;
	cout << "-- ������� �����������: " << area << " ��. ��" << endl;
	cout << "-- �������: " << depth << " �" << endl;
}

ostream& operator <<(ostream& out, Sea s) {
	out << "���� " << s.name << ":" << endl;
	out << "-- ��������������: " << s.location << endl;
	out << "-- ������� �����������: " << s.area << " ��. ��" << endl;
	out << "-- �������: " << s.depth << " �" << endl;
	return out;
}

istream& operator >>(istream& in, Sea& s) {
	string choise;
	cout << "�������� �� ���� ����������? (��/���): ";
	in >> choise;

	if (choise == "��") {
		s.Ocean::name = "";
		s.Ocean::location = "";
		s.Ocean::area = 0;
		s.Ocean::depth = 0;
	}
	else if (choise == "���") {
		cout << "- ������� �����, �������� ����������� ����:" << endl;
		cout << "-- �������� ������: ";
		in >> s.Ocean::name;
		cout << "-- �������������� ������: ";
		in >> s.Ocean::location;
		cout << "-- ������� ����������� ������ � ��. ��: ";
		in >> s.Ocean::area;
		cout << "-- ������� ������ � ������: ";
		in >> s.Ocean::depth;
	}

	cout << "������� �������� ����: ";
	in >> s.name;
	cout << "������� �������������� ����: ";
	in >> s.location;
	cout << "������� ������� ����������� ���� � ��. ��: ";
	in >> s.area;
	cout << "������� ������� ���� � ������: ";
	in >> s.depth;

	return in;
}
