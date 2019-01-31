#include "Shape.h"

Shape::Shape()
{
	stroke_width = 0;
	opacity = 1;
	fill = "black";
	stroke = "white";
}

Shape::~Shape(){}

std::string Shape::getname()
{
	return Name;
}

