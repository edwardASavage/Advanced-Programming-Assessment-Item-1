#pragma once
class Point {
private:
	int x, y;
public:
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);

	Point(int x, int y);
};