#pragma once
#include "Shape.h"

namespace SVG
{

class Line :
	public Shape
{
public:
	Line(std::string);
	~Line();
	void information();
	std::string Export();
	void SetOption(std::istream&,std::string&);
	void GetOption(std::string);
private:
	point start;
	point end;
};

}