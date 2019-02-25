#include "Circle.h"
#include <iostream>
#include "SVGEXCEPT.h"

Circle::Circle(std::string name):Shape()
{
	Name = name;
}


Circle::~Circle(){}

void Circle::information()
{
	std::cout << "name: " << Name << "  type:  Circle\n";

}

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

void Circle::SetOption(std::string name)
{
	std::string tmpname;
	int location;
	location = name.find('-');
	if (location == std::string::npos) // chek anim or no if flase then its animate
	{
		std::string option;//count option
		getline(std::cin, tmpname, '(');
		if (tmpname != " ") 
			throw undefined_command();
		//theow except cmmand
		getline(std::cin, option, ')');
		getline(std::cin, tmpname);
		if (tmpname != "") 
			throw undefined_command();
		//throw excp command
		if (name == "r")
			r = option;
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
			Shape::SetAnim(name);		}
		else 
			throw undefined_command();
		//throw excp

	}
}

void Circle::GetOption(std::string name)
{
	std::string tmpname;
	int location;
	location = name.find('-');
	if (location == std::string::npos) // chek anim or no if flase then its animate
	{
		std::string option;//count option
		getline(std::cin, tmpname, '(');
		if (tmpname != " ") 
			throw undefined_command();
		//theow except cmmand
		getline(std::cin, option, ')');
		getline(std::cin, tmpname);
		if (tmpname != "") 
			throw undefined_command();
		//throw excp command
		if (name == "r")
			std::cout << std::endl << r;
		else if (name == "cx")
			std::cout << std::endl << loc.x;
		else if (name == "cy")
			std::cout << std::endl << loc.y;
		else Shape::GetOption(name, option);
	}
	else
	{
		tmpname = name.substr(0, location - 1); //anim name

		if (name[location + 1] == '>')
		{
			Shape::SetAnim(name.substr(location + 2, std::string::npos));
		}
		else 
			throw undefined_command();

	}
}
