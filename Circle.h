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
	void SetOption(std::string);
	void GetOption(std::string);
private:
	point loc;
	std::string r;
};