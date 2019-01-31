#pragma once
#include "Shape.h"
class Ellipse :
	public Shape
{
public:
	Ellipse(std::string);
	~Ellipse();
	void information();
	std::string Export();
private:
	point loc;
	point r;
};

