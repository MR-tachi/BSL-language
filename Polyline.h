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
	void SetOption(std::string);
private:
	std::vector<point*> Points;
};

