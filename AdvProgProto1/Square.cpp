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

void Square::scale(float scaleX, float scaleY) {

	if (scaleX != scaleY)
	{
		cout << "Square requires isotropic functionality. only scaleX parameter used." << endl;
		edge *= scaleX;
	}
}

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

	//rightBottom
	points.push_back(new Point(x + edge, y + edge));
	//leftBottom
	points.push_back(new Point(x, y + edge));
}

void Square::toString() {
	calculatePoints();
	calculateArea();
	calculatePerimeter();


	cout << "Square[e=" << edge << "]"
		<< "\npoints[("
		<< points[0]->getX() << "," << points[0]->getY() << ")("
		<< points[1]->getX() << "," << points[1]->getY() << ")("
		<< points[2]->getX() << "," << points[2]->getY() << ")("
		<< points[3]->getX() << "," << points[3]->getY() << ")]"
		<< "\narea=" << area << " Perimeter=" << perimeter << endl;
	cout << "" << endl;
}

ostream& operator<<(ostream& out, Square* s)
{
	s->calculatePoints();
	s->calculateArea();
	s->calculatePerimeter();


	out <<  "Square[e=" << s->edge << "]"
		<< "\npoints[("
		<< s->points[0]->getX() << "," << s->points[0]->getY() << ")("
		<< s->points[1]->getX() << "," << s->points[1]->getY() << ")("
		<< s->points[2]->getX() << "," << s->points[2]->getY() << ")("
		<< s->points[3]->getX() << "," << s->points[3]->getY() << ")]"
		<< "\narea=" << s->area << " Perimeter=" << s->perimeter <<"\n"<< endl;

	return out;
}
