#pragma once
#include "Shape.h"
#include "Movable.h"
#include <iostream>

class Circle : public Shape, public Movable {
private:
	double radius;
public:

	void calculateArea();
	void calculatePoints();
	void calculatePerimeter();
	void toString();
	void move(int newX, int newY);
	void scale(float scaleX, float scaleY);
	friend ostream& operator << (ostream& out, Circle* c);

	Circle(int x, int y, int radius);

	

};