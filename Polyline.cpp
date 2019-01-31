#include "Polyline.h"



Polyline::Polyline(std::string name):Shape()
{
	Name = name;
}


Polyline::~Polyline()
{
}

void Polyline::information()
{
}

std::string Polyline::Export()
{
	std::string output = "\n  <polygon points=\"";
	for (short i = 0; i < Points.size(); i++)
	{
		output += Points[i]->x;
		output += ",";
		output += Points[i]->y;
		if (i != Points.size() - 1)
			output += " ";
	}
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
	output += "\n</polygon>";
	return output;
}
