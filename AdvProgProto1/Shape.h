#pragma once
#include "Point.h"
#include <vector>
using namespace std;

class Shape {
protected:
	double area;
	double perimeter;
	Point* leftTop = new Point(0,0);
	vector<Point*> points;
public:
	virtual void calculateArea() = 0;
	virtual void calculatePoints() = 0;
	virtual void calculatePerimeter() = 0;
};