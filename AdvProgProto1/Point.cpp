#include "Point.h"
#include <iostream>
using namespace std;

int Point::getX() const { return x; }
int Point::getY() const { return y; }

void Point::setX(int x) { this->x = x; }
void Point::setY(int y) { this->y = y; }

Point::Point(int x, int y) {
	setX(x);
	setY(y);
}

