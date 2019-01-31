#pragma once
#include "Shape.h"
#include <vector>
class Circle :
	public Shape
{
public:

	Circle(std::string);
	~Circle();
	void information() ;
	std::string Export();
private:
	point loc;
	short r;
};