#include "Polyline.h"
#include <iostream>
#include "SVGEXCEPT.h"

using namespace SVG;

Polyline::Polyline(std::string name) :Shape()
{
	Name = name;
}


Polyline::~Polyline()
{
}

void Polyline::information()
{
	std::cout << "name: " << Name << "  type:  Polyline\n";
}

std::string Polyline::Export()
{
	std::string output = "\n  <polyline points=\"";
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
	output += "\n</polyline>";
	return output;
}

void Polyline::SetOption(std::string name)
{
	std::string tmpname;
	int location;
	location = name.find('-');
	if (location == std::string::npos) // chek anim or no if flase then its animate
	{
		getline(std::cin, tmpname, '(');
		if (tmpname != " ")
			throw undefined_command();
			std::string option;//count option
			getline(std::cin, option, ')');
			getline(std::cin, tmpname);
			if (tmpname != "")
				throw undefined_command();
			if (name == "points")
				Points = option;
			else Shape::SetOption(name, option);
	}
	else
	{
		tmpname = name.substr(0, location - 1); //anim name

		if (name[location + 1] == '>')
		{
			Shape::SetAnim(name);
		}
		else
			throw undefined_command();

	}
}

void Polyline::GetOption(std::string)
{
}
