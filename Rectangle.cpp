#include "Rectangle.h"
#include<iostream>


Rectangle::Rectangle(std::string name) :Shape()
{
	Name = name;
}


Rectangle::~Rectangle()
{
}

void Rectangle::information()
{
	std::cout << "name: " << Name << "  type:  Line\n";
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

void Rectangle::SetOption(std::string name)
{
	std::string tmpname;
	int location;
	location = name.find('-');
	if (location == std::string::npos) // chek anim or no if flase then its animate
	{
		std::string option;//count option
		getline(std::cin, tmpname, '(');
		if (tmpname != " ") {}
		//theow except cmmand
		getline(std::cin, option, ')');
		getline(std::cin, tmpname);
		if (tmpname != "") {}
		//throw excp command
		if (name == "x")
			loc.x = option;
		else if (name == "y")
			loc.y = option;
		else if (name == "rx")
			r.x = option;
		else if (name == "ry")
			r.y = option;
		else if (name == "width")
			width = option;
		else if (name == "height")
			height = option;
		else Shape::SetOption(name, option);
	}
	else
	{
		tmpname = name.substr(0, location); //anim name

		if (name[location + 1] == '>')
		{
			Shape::SetAnim(name);// .substr(location + 2, std::string::npos));
		}
		else {}
		//throw excp

	}
}
