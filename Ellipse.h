#pragma once
#include "Shape.h"
namespace SVG {

class Ellipse :
	public Shape
{
public:
	Ellipse(std::string);
	~Ellipse();
	void information();
	std::string Export();
	void SetOption(std::istream&, std::string&);
	void GetOption(std::string);
private:
	point loc;
	point r;
};

}
