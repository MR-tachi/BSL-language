#pragma once
#include "Shape.h"
namespace SVG {

class Polyline :
	public Shape
{
public:
	Polyline(std::string);
	~Polyline();
	void information();
	std::string Export();
	void SetOption(std::istream&, std::string&);
	void GetOption(std::string);
private:
	std::string Points;
};

}
