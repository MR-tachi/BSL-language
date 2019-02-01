#include "Polygon.h"
#include <iostream>


Polygon::Polygon(std::string name):Shape()
{
	Name = name;
}


Polygon::~Polygon()
{
}

void Polygon::information()
{
}

std::string Polygon::Export()
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

void Polygon::SetOption(std::string name)
{
	std::string tmpname;
	int location;
	location = name.find('-');
	if (location == std::string::npos) // chek anim or no if flase then its animate
	{
		if (name == "points")
		{
			bool flag = true;
			while (flag == true)
			{
				point* tmp = new point;
				getline(std::cin, tmp->x, ',');
				getline(std::cin, tmp->y, ' ');
				if (tmp->y.back() == ')')
				{
					flag = false;
					tmp->y.pop_back();
				}
				Points.push_back(tmp);
			}
		}
		else
		{

			std::string option;//count option
			getline(std::cin, tmpname, '(');
			if (tmpname != " (") {}
			//throw except cmmand
			getline(std::cin, option, ')');
			std::cin >> tmpname;
			if (tmpname != ")") {}
			//throw excp command
			else Shape::SetOption(name, option);
		}
	}
	else
	{
		tmpname = name.substr(0, location - 1); //anim name

		if (name[location + 1] == '>')
		{
			Shape::SetAnim(name.substr(location + 2, std::string::npos));
		}
		else {}
		//throw excp

	}
}
