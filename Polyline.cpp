#include "Polyline.h"
#include <iostream>


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
	std::string output = "\n  <polygon points=\"";
	output += Points;
	/*for (short i = 0; i < Points.size(); i++)
	{
		output += Points[i]->x;
		output += ",";
		output += Points[i]->y;
		if (i != Points.size() - 1)
			output += " ";
	}*/
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

void Polyline::SetOption(std::string name)
{
	std::string tmpname;
	int location;
	location = name.find('-');
	if (location == std::string::npos) // chek anim or no if flase then its animate
	{
		getline(std::cin, tmpname, '(');
		if (tmpname != " ") {}
		//throw except cmmand
			std::string option;//count option
			getline(std::cin, option, ')');
			getline(std::cin, tmpname);
			if (tmpname != "") {}
			//throw excp command
			if (name == "points")
			{
				Points = option;




				/*bool flag = true;
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
				}*/
			}
		//else
		//{

			else Shape::SetOption(name, option);
		//}
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
