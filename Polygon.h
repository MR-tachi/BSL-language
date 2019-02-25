#pragma once
#include "Shape.h"
namespace SVG {

class Polygon :
	public Shape
{
public:
	Polygon(std::string);
	~Polygon();
	void information();
	std::string Export();
	void SetOption(std::istream&, std::string&);
	void GetOption(std::string);
private:
	std::string Points;
};

}
