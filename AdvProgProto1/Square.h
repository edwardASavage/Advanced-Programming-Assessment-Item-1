#pragma once
#include "Shape.h"
#include "Movable.h"

class Square : public Shape, public Movable {
private:
	double edge;
public:


	void calculateArea();
	void calculatePoints();
	void calculatePerimeter();
	void toString();
	void move(int newX, int newY);
	void scale(float scaleX, float scaleY);


	Square(int x, int y, int edge);

};