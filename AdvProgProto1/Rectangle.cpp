#pragma once
#include "Rectangle.h"
#include <iostream>
using namespace std;


void Rectangle::calculateArea() {
	area = (double)height * (double)width;
}

void Rectangle::calculatePoints() {

	int x = leftTop->getX();
	int y = leftTop->getY();
	points.clear();
	// leftTop
	points.push_back(new Point(x, y));
	// rightTop
	points.push_back(new Point(x + width, y));
	//rightBottom
	points.push_back(new Point(x + width, y + height));
	//leftBottom
	points.push_back(new Point(x , y + height));

}

void Rectangle::calculatePerimeter() {
	perimeter = ((height * 2) + (width * 2));
}

void Rectangle::toString() {
	calculateArea();
	calculatePoints();
	cout << "points:[ ("
		// points overfilling on move() call. (points[4 to 8] added).
		<< points[0]->getX() << "," << points[0]->getY() << ") ("
		<< points[1]->getX() << "," << points[1]->getY() << ") ("
		<< points[2]->getX() << "," << points[2]->getY() << ") ("
		<< points[3]->getX() << "," << points[3]->getY() << ") ] "
		<< " height: " << height << " width: " << width
		<< " area: " << area << endl;
		cout << "" << endl;
}
void Rectangle::move(int newX, int newY) {

	leftTop->setX(newX);
	leftTop->setY(newY);
	calculatePoints();
	toString();
}
void Rectangle::scale(float scaleX, float scaleY) {
	width *= scaleX;
	height *= scaleY;
	toString();
}

Rectangle::Rectangle(int x, int y, int h, int w) : height(h), width(w){
	leftTop->setX(x);
	leftTop ->setY(y);

}