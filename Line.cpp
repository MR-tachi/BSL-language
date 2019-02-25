#include "Line.h"
#include<iostream>
#include "SVGEXCEPT.h"

using namespace std;
using namespace SVG;

Line::Line(string name) :Shape()
{
	Name = name;
}


Line::~Line()
{
}

void Line::information()
{
	std::cout << " Name: " << Name << "  Type:  Line\n";
}

string Line::Export()
{
	string output = "\n  <line x1=\"";
	output += start.x;
	output += "\" y1=\"";
	output += start.y;
	output += "\" x2=\"";
	output += end.y;
	output += "\" y2=\"";
	output += end.y;
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

void Line::SetOption(string name)
{
	string tmpname;
	int location;
	location = name.find('-');
	if (location == string::npos) // chek anim or no if flase then its animate
	{
		string option;//count option
		getline(cin, tmpname, '(');
		if (tmpname != " ") 
			throw undefined_command();
		getline(cin, option, ')');
		getline(std::cin, tmpname);
		if (tmpname != "") 
			throw undefined_command();
		if (name == "x1")
			start.x = option;
		else if (name == "y1")
			start.y = option;
		else if (name == "x2")
			end.x = option;
		else if (name == "y2")
			end.y = option;
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

void Line::GetOption(std::string)
{
}
