#pragma once
#include "Shape.h"
class Rectangle :
	public Shape
{
public:
	Rectangle(std::string);
	~Rectangle();
	void information();
	std::string Export();
private:
	point loc,r;
	short width, height;
};