#define _USE_MATH_DEFINES

#include "circle.h"
#include "../1_1/triangle.h"
#include <math.h>

Circle::Circle(float r, float x, float y) {
	radius = r;
	x_center = x;
	y_center = y;
}

void Circle::set_circle(float r, float x, float y) {
	radius = r;
	x_center = x;
	y_center = y;
}

float Circle::square() {
	return M_PI * pow(radius, 2);
}

bool Circle::triangle_around(float a, float b, float c) {
	Triangle triangle;
	triangle.set(a, b, c);
	if (!triangle.exst_tr()) return false;

	float triangle_radius = (a * b * c) / (4 * triangle.square());
	return radius == triangle_radius;
}

bool Circle::triangle_in(float a, float b, float c) {
	Triangle triangle;
	triangle.set(a, b, c);
	if (!triangle.exst_tr()) return false;

	float triangle_radius = 2 * triangle.square() / triangle.perimetr();
	return radius == triangle_radius;
}

bool Circle::check_circle(float r, float x_center, float y_center) {
	float radius_sum = r + radius;
	float radius_dif = fabsf(r - radius);
	float distance_between_centers = sqrt(pow((this -> x_center - x_center), 2) + pow((this -> y_center - y_center), 2));

	return (radius_sum > distance_between_centers) and (distance_between_centers > radius_dif);
}
