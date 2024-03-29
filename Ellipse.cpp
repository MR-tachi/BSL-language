#include "Ellipse.h"
#include <iostream>
#include "SVGEXCEPT.h"

using namespace std;
using namespace SVG;

Ellipse::Ellipse(std::string name) :Shape()
{
	Name = name;
}


Ellipse::~Ellipse(){}

void Ellipse::information()
{
std::cout << "Name: " << Name << "  Type:  Ellipse\n";
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

void Ellipse::SetOption(istream &input, string &name)
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
		//theow except cmmand
		getline(input, option, ')');
		getline(input, tmpname);
		if (tmpname != "") 
			throw undefined_command();
		//throw excp command
		if (name == "rx")
			r.x = option;
		else if (name == "ry")
			r.y = option;
		else if (name == "cx")
			loc.x = option;
		else if (name == "cy")
			loc.y = option;
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

void Ellipse::GetOption(std::string)
{
}
