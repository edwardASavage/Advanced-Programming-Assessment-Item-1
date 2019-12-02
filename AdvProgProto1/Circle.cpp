#define _USE_MATH_DEFINES
#pragma once
#include "Circle.h"
#include <iostream>
using namespace std;


void Circle::calculateArea() {
	area = radius;
}

void Circle::calculatePoints() {
	int x = leftTop->getX();
	int y = leftTop->getY();
	points.clear();
	// leftTop
	points.push_back(new Point(x, y));

	// rightBottom
	points.push_back(new Point(x + radius, y));
}

void Circle::calculatePerimeter() {
	perimeter = M_PI * (radius * 2);
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
		radius *= scaleX;
	}

}

Circle::Circle(int x, int y, int r) : radius(r) {
	leftTop->setX(x);
	leftTop->setY(y);
}