#pragma once
#include "Rectangle.h"
#include <iostream>
using namespace std;


void Rectangle::calculateArea() {
	area = height * width;
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
	calculatePoints();
	calculateArea();
	calculatePerimeter();

	cout << "Rectangle[h=" << height << ",w=" << width << "]"
		<< "\npoints[("
		<< points[0]->getX() << "," << points[0]->getY() << ")("
		<< points[1]->getX() << "," << points[1]->getY() << ")("
		<< points[2]->getX() << "," << points[2]->getY() << ")("
		<< points[3]->getX() << "," << points[3]->getY() << ")]"
		<< "\narea=" << area << " Perimeter=" << perimeter << endl;

		cout << "" << endl;
}
void Rectangle::move(int newX, int newY) {

	leftTop->setX(newX);
	leftTop->setY(newY);
}
void Rectangle::scale(float scaleX, float scaleY) {
	width *= scaleY;
	height *= scaleX;
}

Rectangle::Rectangle(int x, int y, int h, int w) : height(h), width(w){
	leftTop->setX(x);
	leftTop ->setY(y);

}

Rectangle::~Rectangle()
{

	cout << "Rectangle destroyed";
}

ostream& operator<<(ostream& out, Rectangle* r)
{
	r->calculatePoints();
	r->calculateArea();
	r->calculatePerimeter();

	out << "Rectangle[h=" << r->height << ",w=" << r->width << "]"
		<< "\npoints[("
		<< r->points[0]->getX() << "," << r->points[0]->getY() << ")("
		<< r->points[1]->getX() << "," << r->points[1]->getY() << ")("
		<< r->points[2]->getX() << "," << r->points[2]->getY() << ")("
		<< r->points[3]->getX() << "," << r->points[3]->getY() << ")]"
		<< "\narea=" << r->area << " Perimeter=" << r->perimeter << endl;

	return out;
}
