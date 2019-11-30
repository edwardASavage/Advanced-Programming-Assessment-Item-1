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
	cout << "points:[ ("
		// points overfilling on move() call. (points[4 to 8] added).
		<< points[0]->getX() << "," << points[0]->getY() << ") ("
		<< points[1]->getX() << "," << points[1]->getY() << ") ] "
		<< "radius: " << radius << " area: " << area << endl;
	cout << "" << endl;
}

void Circle::move(int newX, int newY) {
	leftTop->setX(newX);
	leftTop->setY(newY);
	calculatePoints();
	toString();
}

void Circle::scale(float scaleX, float scaleY) {
	if (!(scaleX == scaleY)) { cout << "X and Y scale different, shape will not be circle ... scaling to X only." << endl; }
	radius *= scaleX;
	calculateArea();
	calculatePoints();
	toString();

}

Circle::Circle(int x, int y, int r) : radius(r) {
	leftTop->setX(x);
	leftTop->setY(y);
	calculateArea();
	calculatePoints();
}