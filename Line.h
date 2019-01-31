#pragma once
#include "Shape.h"
class Line :
	public Shape
{
public:
	Line(std::string);
	~Line();
	void information();
	std::string Export();
private:
	point start, end;
};

