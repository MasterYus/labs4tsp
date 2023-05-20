#include "frustum.h"

Frustum::Frustum() : Cone() { radius = height = 0; }

Frustum::Frustum(double r, double h, double h2) : Cone(r, h) {
	radius = r - (r * h2) / h; // ������� �� ������� �������������
	height = h2;
}

Frustum::Frustum(double x, double y, double z, double r, double h, double h2) : Cone(x, y, z, r, h) {
	radius = r - (r * h2) / h; // ������� �� ������� �������������
	height = h2;
}

Frustum::Frustum(Cone& C, double h2) : Cone(C) {
	radius = C.getRadius() - (C.getRadius() * h2) / C.getHeight(); // ������� �� ������� �������������
	height = h2;
}

void Frustum::setRadius(double r) {
	Cone::radius = r;
	radius = Cone::radius - (Cone::radius * height) / Cone::height;
}

void Frustum::setHeight(double h) { 
	height = h;
	radius = Cone::radius - (Cone::radius * height) / Cone::height;
}

double Frustum::getRadiusFrustum() { return radius; }

double Frustum::area() {
	Cone cone_small(x, y, z + height, radius, Cone::height - height);
	double area_total = Cone::area();
	double area_small = cone_small.area();
	return area_total - area_small + 2 * PI * radius * radius;
}

double Frustum::volume() {
	Cone cone_small(x, y, z + height, radius, Cone::height - height);
	double volume_total = Cone::volume();
	double volume_small = cone_small.volume();
	return volume_total - volume_small;
}

map<string, bool> Frustum::compare(Frustum& f2) {
	map <string, bool> comparisons;

	if (this->Cone::radius == f2.Cone::radius and this->radius == f2.radius) {
		cout << "\n--- ������� �������� � �������� ��������� ������� �����";
		comparisons["�������"] = true;
	}
	else {
		cout << "\n--- ������� �������� � �������� ��������� ������� �� �����";
		comparisons["�������"] = false;
	}

	if (this->area() == f2.area()) {
		cout << "\n--- ������� ������� �����";
		comparisons["�������"] = true;
	}
	else {
		cout << "\n--- ������� ������� �� �����";
		comparisons["�������"] = false;
	}

	if (this->volume() == f2.volume()) {
		cout << "\n--- ������ ������� �����";
		comparisons["������"] = true;
	}
	else {
		cout << "\n--- ������ ������� �� �����";
		comparisons["������"] = false;
	}

	if (this->height == f2.height) {
		cout << "\n--- ������ ������� �����";
		comparisons["������"] = true;
	}
	else {
		cout << "\n--- ������ ������� �� �����";
		comparisons["������"] = false;
	}

	if (this->x == f2.x and this->y == f2.y and this->z == f2.z) {
		cout << "\n--- ���������� ����� ������� ������� ��������� ������� �����";
		comparisons["������"] = true;
	}
	else {
		cout << "\n--- ���������� ����� ������� ������� ��������� ������� �� �����";
		comparisons["������"] = false;
	}

	return comparisons;
}

ostream& operator <<(ostream& out, Frustum f) {
	out << "���������� ������ �������� ���������: (" << f.x << "; " << f.y << "; " << f.z << ")" << endl;
	out << "���������� ������ �������� ���������: (" << f.x << "; " << f.y << "; " << f.z + f.height << ")" << endl;
	out << "R = " << f.Cone::radius << " (������ �������� ���������)" << endl;
	out << "r = " << f.radius << " (������ �������� ���������)" << endl;
	out << "h = " << f.height << " (������ - ���������� �� ������ �������� ��������� �� ������ ��������)" << endl;
	return out;
}

istream& operator >>(istream& in, Frustum& f) {
	cout << "\n������� ���������� ������ �������� ��������� ����� ������: ";
	in >> f.x >> f.y >> f.z;
	cout << "\n������� ������ �������� ���������: ";
	in >> f.Cone::radius;
	cout << "\n������� ������ �������� ���������: ";
	in >> f.radius;
	cout << "\n������� ������ (���������� �� ������ �������� ��������� �� ������ ��������): ";
	in >> f.height;
	return in;
}
