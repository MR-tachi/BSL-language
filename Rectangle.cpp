#include "Rectangle.h"



Rectangle::Rectangle(std::string name) :Shape()
{
	Name = name;
}


Rectangle::~Rectangle()
{
}

void Rectangle::information()
{
}

std::string Rectangle::Export()
{
	std::string output = "\n  <rect x=\"";
	output += loc.x;
	output += "\" y=\"";
	output += loc.y;
	output += "\" rx=\"";
	output += r.x;
	output += "\" ry=\"";
	output += r.y;
	output += "\" width=\"";
	output += width;
	output += "\" height=\"";
	output += height;
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
	output += "\n</rect>";
	return output;
}
