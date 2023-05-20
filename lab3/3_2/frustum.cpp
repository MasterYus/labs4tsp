#include "frustum.h"

Frustum::Frustum() : Cone() { radius = height = 0; }

Frustum::Frustum(double r, double h, double h2) : Cone(r, h) {
	radius = r - (r * h2) / h; // следует из подобия треугольников
	height = h2;
}

Frustum::Frustum(double x, double y, double z, double r, double h, double h2) : Cone(x, y, z, r, h) {
	radius = r - (r * h2) / h; // следует из подобия треугольников
	height = h2;
}

Frustum::Frustum(Cone& C, double h2) : Cone(C) {
	radius = C.getRadius() - (C.getRadius() * h2) / C.getHeight(); // следует из подобия треугольников
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
		cout << "\n--- Радиусы большего и меньшего оснований конусов равны";
		comparisons["Радиусы"] = true;
	}
	else {
		cout << "\n--- Радиусы большего и меньшего оснований конусов не равны";
		comparisons["Радиусы"] = false;
	}

	if (this->area() == f2.area()) {
		cout << "\n--- Площади конусов равны";
		comparisons["Площади"] = true;
	}
	else {
		cout << "\n--- Площади конусов не равны";
		comparisons["Площади"] = false;
	}

	if (this->volume() == f2.volume()) {
		cout << "\n--- Объёмы конусов равны";
		comparisons["Объёмы"] = true;
	}
	else {
		cout << "\n--- Объёмы конусов не равны";
		comparisons["Объёмы"] = false;
	}

	if (this->height == f2.height) {
		cout << "\n--- Высоты конусов равны";
		comparisons["Высоты"] = true;
	}
	else {
		cout << "\n--- Высоты конусов не равны";
		comparisons["Высоты"] = false;
	}

	if (this->x == f2.x and this->y == f2.y and this->z == f2.z) {
		cout << "\n--- Координаты точек центров больших оснований конусов равны";
		comparisons["Центры"] = true;
	}
	else {
		cout << "\n--- Координаты точек центров больших оснований конусов не равны";
		comparisons["Центры"] = false;
	}

	return comparisons;
}

ostream& operator <<(ostream& out, Frustum f) {
	out << "Координаты центра большего основания: (" << f.x << "; " << f.y << "; " << f.z << ")" << endl;
	out << "Координаты центра меньшего основания: (" << f.x << "; " << f.y << "; " << f.z + f.height << ")" << endl;
	out << "R = " << f.Cone::radius << " (радиус большего основания)" << endl;
	out << "r = " << f.radius << " (радиус меньшего основания)" << endl;
	out << "h = " << f.height << " (высота - расстояние от центра большего основания до центра меньшего)" << endl;
	return out;
}

istream& operator >>(istream& in, Frustum& f) {
	cout << "\nВведите координаты центра большего основания через пробел: ";
	in >> f.x >> f.y >> f.z;
	cout << "\nВведите радиус большего основания: ";
	in >> f.Cone::radius;
	cout << "\nВведите радиус меньшего основания: ";
	in >> f.radius;
	cout << "\nВведите высоту (расстояние от центра большего основания до центра меньшего): ";
	in >> f.height;
	return in;
}
