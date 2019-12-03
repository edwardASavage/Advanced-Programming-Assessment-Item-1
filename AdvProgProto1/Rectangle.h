#pragma once
#include "Shape.h"
#include "Movable.h"
#include <iostream>

class Rectangle : public Shape, public Movable {
private:
	int height;
	int width;
public:

	void calculateArea();
	void calculatePoints();
	void calculatePerimeter();
	void toString();
	void move(int newX, int newY);
	void scale(float scaleX, float scaleY);

	Rectangle(int x, int y, int height, int width);

	friend ostream& operator<<(ostream& out, Rectangle* s);
	

};