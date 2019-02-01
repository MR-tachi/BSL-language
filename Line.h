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
	void SetOption(std::string);
private:
	point start;
	point end;
};

