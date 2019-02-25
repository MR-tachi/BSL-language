#include "Polygon.h"
#include <iostream>
#include "SVGEXCEPT.h"

using namespace std;
using namespace SVG;

Polygon::Polygon(std::string name):Shape()
{
	Name = name;
}


Polygon::~Polygon()
{
}

void Polygon::information()
{
	std::cout << " Name: " << Name << "  Type:  Polygon\n";
}

std::string Polygon::Export()
{
	std::string output = "\n  <polygon points=\"";
	output += Points;
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

void Polygon::SetOption(istream &input, string &name)
{
	std::string tmpname;
	int location;
	location = name.find('-');
	if (location == std::string::npos) // chek anim or no if flase then its animate
	{
		std::string option;//count option
		getline(input, tmpname, '(');
		if (tmpname != " ") 
			throw undefined_command();
		//throw except cmmand
		getline(input, option, ')');
		getline(input, tmpname);
		if (tmpname != "") 
			throw undefined_command();
		//throw excp command
		if (name == "points")
			Points = option;
		else Shape::SetOption(name, option);
	}
	else
	{
		tmpname = name.substr(0, location - 1); //anim name

		if (name[location + 1] == '>')
		{
			Shape::SetAnim(input,name);
		}
		else 
			throw undefined_command();
		//throw excp

	}
}

void Polygon::GetOption(std::string)
{
}
