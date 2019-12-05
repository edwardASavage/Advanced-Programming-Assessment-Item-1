#include "Point.h"
#include <iostream>
using namespace std;

int Point::getX() const { return x; }
int Point::getY() const { return y; }

void Point::setX(int newX) { x = newX; }
void Point::setY(int newY) { y = newY; }

Point::Point(int x, int y) {
	setX(x);
	setY(y);
}

