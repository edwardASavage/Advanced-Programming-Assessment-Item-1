#pragma once
#include "Point.h"
#include <vector>
using namespace std;

class Shape {
protected:
	float area = 0;
	float perimeter= 0;
	Point* leftTop = new Point(0,0);
	vector<Point*> points;
public:
	virtual void calculateArea() = 0;
	virtual void calculatePoints() = 0;
	virtual void calculatePerimeter() = 0;
	virtual void toString() = 0;
};