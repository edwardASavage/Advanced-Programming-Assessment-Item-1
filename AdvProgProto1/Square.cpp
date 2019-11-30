#pragma once
#include "Square.h"
#include <iostream>
using namespace std;

void Square::calculateArea() {
	area = (double)edge * (double)edge;
};

void Square::calculatePoints() {
	int x = leftTop->getX();
	int y = leftTop->getY();
	points.clear();
	// leftTop
	points.push_back(new Point(x, y));

	// rightTop
	points.push_back(new Point(x + edge, y));
	//leftBottom
	points.push_back(new Point(x, y + edge));
	//rightBottom
	points.push_back(new Point(x + edge, y + edge));
}

void Square::calculatePerimeter() {
	perimeter = edge * 4;
}

void Square::toString() {
	cout << "points:[ ("
		// points overfilling on move() call. (points[4 to 8] added).
		<< points[0]->getX() << "," << points[0]->getY() << ") ("
		<< points[1]->getX() << "," << points[1]->getY() << ") ("
		<< points[2]->getX() << "," << points[2]->getY() << ") ("
		<< points[3]->getX() << "," << points[3]->getY() << ") ] "
		<< " edge: " << edge<< " area: " << area << " perimeter: " << perimeter << endl;
	cout << "" << endl;
}

void Square::move(int newX, int newY) {
	leftTop->setX(newX);
	leftTop->setY(newY);
	calculatePoints();
	toString();
}

void Square::scale(float scaleX, float scaleY) {
	if (!(scaleX == scaleY)) { cout << "X and Y scale different, shape will not be square ... scaling to X only."; }
	edge *= scaleX;
	calculateArea();
	calculatePoints();
	toString();

}

Square::Square(int x, int y, int e) : edge(e) {
	leftTop->setX(x);
	leftTop->setY(y);
	calculatePerimeter();
	calculateArea();
	calculatePoints();
}