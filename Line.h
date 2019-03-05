#pragma once
#include "Shape.h"

namespace SVG
{

class Line :
	public Shape
{
public:
	Line(std::string);
	Line(std::string x1, std::string y1, std::string x2, std::string y2 , std::string s);
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