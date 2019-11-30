#pragma once
#include "Square.h"
#include <iostream>
using namespace std;



Square::Square(int x, int y, int e) : edge(e) {
	leftTop->setX(x);
	leftTop->setY(y);
}

void Square::calculateArea() { area = (double)edge * (double)edge; };

void Square::calculatePerimeter() { perimeter = edge * 4; }

void Square::scale(float scaleX, float scaleY) { edge *= scaleX; }

void Square::move(int newX, int newY) {
	leftTop->setX(newX);
	leftTop->setY(newY);
	cout << "moved";
}

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

void Square::toString() {
	calculatePerimeter();
	calculateArea();
	calculatePoints();
	cout << "points:[ ("
		<< points[0]->getX() << "," << points[0]->getY() << ") ("
		<< points[1]->getX() << "," << points[1]->getY() << ") ("
		<< points[2]->getX() << "," << points[2]->getY() << ") ("
		<< points[3]->getX() << "," << points[3]->getY() << ") ] "
		<< " edge: " << edge << " area: " << area << " perimeter: " << perimeter << endl;
	cout << "" << endl;
}