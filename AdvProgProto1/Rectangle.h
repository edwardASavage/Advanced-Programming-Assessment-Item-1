#pragma once
#include "Shape.h"
#include "Movable.h"
#include <iostream>

class Rectangle : public Shape, public Movable {
private:
	float height;
	float width;
public:

	void calculateArea();
	void calculatePoints();
	void calculatePerimeter();
	void toString();
	void move(int newX, int newY);
	void scale(float scaleX, float scaleY);

	Rectangle(int x, int y, float height, float width);

	friend ostream& operator<<(ostream& out, Rectangle* s);
	

};