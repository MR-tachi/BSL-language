#pragma once
#include "Shape.h"
class Polygon :
	public Shape
{
public:
	Polygon(std::string);
	~Polygon();
	void information();
	std::string Export();
	void SetOption(std::string);
private:
	std::vector<point*> Points;
};

