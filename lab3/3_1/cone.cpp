#include "cone.h"

Cone::Cone() { x = y = z = radius = height = 0; }

Cone::Cone(double r, double h) {
    x = y = z = 0.0;
    radius = r;
    height = h;
}

Cone::Cone(double x, double y, double z, double r, double h) {
    this->x = x;
    this->y = y;
    this->z = z;
    radius = r;
    height = h;
}

void Cone::setCoordinate(double x, double y, double z) { this->x = x; this->y = y; this->z = z; }

void Cone::setRadius(double r) { radius = r; }

void Cone::setHeight(double h) { height = h; }

double Cone::getRadius() { return radius; }

double Cone::getHeight() { return height; }

double Cone::area() {
    double l = sqrt(height * height + radius * radius);
    return PI * radius * (radius + l);
}

double Cone::volume() {
    return PI * radius * radius * height / 3;
}

ostream& operator <<(ostream& out, Cone c) {
    out << "(";
    out << c.x << "; ";
    out << c.y << "; ";
    out << c.z;
    out << ") | ";
    out << "r = " << c.radius << " | ";
    out << "h = " << c.height << endl;
    return out;
}
