#pragma once
#include "Square.h"
#include <iostream>
using namespace std;

// construct square
Square::Square(int x, int y, int e) : edge(e) {
	leftTop->setX(x);
	leftTop->setY(y);
}

void Square::calculateArea() { area =edge * edge; };

void Square::calculatePerimeter() { perimeter = edge * 4; }

void Square::scale(float scaleX, float scaleY) {
	//ensure params are isotropic.
	if (scaleX != scaleY)
	{
		cout << "Parameters for Square are required to be isotropic. scaling to X only...\n" << endl;
	}
	edge *= scaleX;
}

void Square::move(int newX, int newY) {
	leftTop->setX(newX);
	leftTop->setY(newY);
}

void Square::calculatePoints() {
	int x = leftTop->getX();
	int y = leftTop->getY();
	// clear vector before filling.
	points.clear();
	// leftTop.
	points.push_back(new Point(x, y));
	// rightTop.
	points.push_back(new Point(x + (int)edge, y));
	//rightBottom.
	points.push_back(new Point(x + (int)edge, y + (int)edge));
	//leftBottom.
	points.push_back(new Point(x, y + (int)edge));
}

void Square::toString() {
	// perform adjustments before printing.
	calculatePoints();
	calculateArea();
	calculatePerimeter();
	cout << "\nSquare[e=" << edge << "]"
		<< "\npoints[("
		<< points[0]->getX() << "," << points[0]->getY() << ")("
		<< points[1]->getX() << "," << points[1]->getY() << ")("
		<< points[2]->getX() << "," << points[2]->getY() << ")("
		<< points[3]->getX() << "," << points[3]->getY() << ")]"
		<< "\narea=" << area << " Perimeter=" << perimeter <<"\n"<< endl;
	cout << "" << endl;
}

// operator overload for cout <<.
ostream& operator << (ostream& out, Square* s)
{
	s->calculatePoints();
	s->calculateArea();
	s->calculatePerimeter();
	out << "\nSquare[e=" << s->edge << "]"
		<< "\npoints[("
		<< s->points[0]->getX() << "," << s->points[0]->getY() << ")("
		<< s->points[1]->getX() << "," << s->points[1]->getY() << ")("
		<< s->points[2]->getX() << "," << s->points[2]->getY() << ")("
		<< s->points[3]->getX() << "," << s->points[3]->getY() << ")]"
		<< "\narea=" << s->area << " Perimeter=" << s->perimeter  << "\n" << endl;
	return out;
}
