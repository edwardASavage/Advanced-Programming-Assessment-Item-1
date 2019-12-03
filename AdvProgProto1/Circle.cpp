#define _USE_MATH_DEFINES
#pragma once
#include "Circle.h"
#include <iostream>
using namespace std;


void Circle::calculateArea() {
	area = M_PI* (radius*radius);
}

void Circle::calculatePoints() {
	int x = leftTop->getX();
	int y = leftTop->getY();
	points.push_back(new Point(x, y));
	// rightBottom, casted to int.
	points.push_back(new Point((int)x + (2*radius), (int)y + (2*radius)));
}

void Circle::calculatePerimeter() {
	perimeter = M_PI * (2*radius);
}


void Circle::toString() {
	calculatePoints();
	calculateArea();
	calculatePerimeter();

	cout << "Circle[r=" << radius << "]"
		<< "\npoints[("

		<< points[0]->getX() << "," << points[0]->getY() << ")("
		<< points[1]->getX() << "," << points[1]->getY() << ")]"
		<< "\narea=" << area << " Perimeter=" << perimeter << endl;
	cout << "" << endl;
}

void Circle::move(int newX, int newY) {
	leftTop->setX(newX);
	leftTop->setY(newY);
}

void Circle::scale(float scaleX, float scaleY) {
	if (scaleX != scaleY)
	{
		cout << "Circle requires isotropic functionality. only scaleX parameter used." << endl;
	}
	radius *= scaleX;

}

Circle::Circle(int x, int y, int r) : radius(r) {
	leftTop->setX(x);
	leftTop->setY(y);
}

Circle::~Circle()
{
}


ostream& operator<<(ostream& out,  Circle* c)
{
	c->calculatePoints();
	c->calculateArea();
	c->calculatePerimeter();

	out << "Circle[r=" << c->radius << "]"
		<< "\npoints[("

		<< c->points[0]->getX() << "," << c->points[0]->getY() << ")("
		<< c->points[1]->getX() << "," << c->points[1]->getY() << ")]"
		<< "\narea=" << c->area << " Perimeter=" << c->perimeter << "\n" << endl;

	return out;
}
