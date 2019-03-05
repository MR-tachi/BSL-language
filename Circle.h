#pragma once
#include "Shape.h"
#include <vector>
namespace SVG {

class Circle :
	public Shape
{
public:

	Circle(std::string);
	Circle(std::string x ,std::string y , std::string _r);
	~Circle();
	void information() ;
	std::string Export();
	void SetOption(std::istream&, std::string&);
	void GetOption(std::string);
private:
	point loc;
	std::string r;
};
}