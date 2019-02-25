#include "Text.h"
#include<iostream>
#include "SVGEXCEPT.h"
using namespace std;



Text::Text(std::string name)
{
	Name = name;
}

Text::~Text()
{
}

void Text::information()
{
	std::cout << "name: " << Name << "  type:  Text\n";
}

std::string Text::Export()
{
	string output = "\n  <text x=\"";
	output += loc.x;
	output += "\" y=\"";
	output += loc.y;
	output += "\" font-size=\"";
	output += size;
	output += "\" font-family=\"";
	output += font;
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
	output += text;
	output += "\n</text>";
	return output;
}

void Text::SetOption(std::string name)
{
	string tmpname;
	int location;
	location = name.find('-');
	if (location == string::npos) // chek anim or no if flase then its animate
	{
		string option;//count option
		getline(cin, tmpname, '(');
		if (tmpname != " ") {}
		//theow except cmmand
		getline(cin, option, ')');
		getline(std::cin, tmpname);
		if (tmpname != "") {}
		//throw excp command
		if (name == "x")
			loc.x = option;
		else if (name == "y")
			loc.y = option;
		else if (name == "font-size")
			size = option;
		else if (name == "font-family")
			font = option;
		else if (name == "text")
			text = option;
		else Shape::SetOption(name, option);
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
		//throw excp

	}
}

void Text::GetOption(std::string name)
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
		//theow except cmmand
		getline(cin, option, ')');
		getline(std::cin, tmpname);
		if (tmpname != "") 
			throw undefined_command();
		//throw excp command
		if (name == "x")
			loc.x = option;
		else if (name == "y")
			loc.y = option;
		else if (name == "font-size")
			size = option;
		else if (name == "font-family")
			font = option;
		else if (name == "text")
			text = option;
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
		//throw excp

	}
}
