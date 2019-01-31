#pragma once
#include "Shape.h"
class Polyline :
	public Shape
{
public:
	Polyline(std::string);
	~Polyline();
	void information();
	std::string Export();
private:
	std::vector<point*> Points;
};

