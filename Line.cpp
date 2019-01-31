#include "Line.h"



Line::Line(std::string name) :Shape()
{
	Name = name;
}


Line::~Line()
{
}

void Line::information()
{
}

std::string Line::Export()
{
	std::string output = "\n  <line x1=\"";
	output += start.x;
	output += "\" y1=\"";
	output += start.y;
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
	output += "\n</line>";
	return output;
}
