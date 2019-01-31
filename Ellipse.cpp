#include "Ellipse.h"



Ellipse::Ellipse(std::string name) :Shape()
{
	Name = name;
}


Ellipse::~Ellipse(){}

void Ellipse::information()
{
}

std::string Ellipse::Export()
{
	std::string output = "\n  <ellipse cx=\n\"";
	output += loc.x;
	output += "\" cy=\"";
	output += loc.y;
	output += "\" rx=\"";
	output += r.x;
	output += "\" ry=\"";
	output += r.y;
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
	output += "\n</ellipse>";
	return output;
}
