#pragma once
#include "Shape.h"
#include "Movable.h"
#include <iostream>

class Square : public Shape, public Movable {
private:
	float edge;
public:

	void calculateArea();
	void calculatePoints();
	void calculatePerimeter();
	void toString();
	void move(int newX, int newY);
	void scale(float scaleX, float scaleY);
	friend ostream& operator << (ostream& out, Square* s);

	Square(int x, int y, int edge);

};