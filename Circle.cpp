#include "Circle.h"



Circle::Circle(std::string name):Shape()
{
	Name = name;
}


Circle::~Circle(){}

void Circle::information(){}

std::string Circle::Export()
{
	std::string output = "\n  <circle cx=\"";
	output += loc.x;
	output += "\" cy=\"";
	output += loc.y;
	output += "\" r=\"";
	output += r;
	output += "\" stroke=\"";
	output += stroke;
	output += "\" fill=\"";
	output += fill;
	output += "\" stroke_width=\"";
	output += stroke_width;
	output += "\" opacity=\"";
	output += opacity;
	output += "\">";
	for (short i = 0; i < Anim.size(); i++)
		output += Anim[i]->Export();
	output += "\n</circle>";
	return output;
}
