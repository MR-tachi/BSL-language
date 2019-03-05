#include "Plot.h"
#include <iostream>
#include <fstream>
#include "Rectangle.h"
#include "Line.h"
#include "Polyline.h"
#include "Text.h"
#include "SVGEXCEPT.h"
#include "Circle.h"
using namespace std;
using namespace SVG;

Plot::Plot(std::string name)
{
	Name = name;
}
Plot::~Plot()
{
}

void Plot::information()
{
	std::cout << " Name: " << Name << "  Type:  Plot\n";
}

std::string Plot::Export()
{
	string plotexport;
		
	//create a plot in svg 
	double x = stod(loc.x);
	double y = stod(loc.y);
	double h = stod(hw.y);
	double w = stod(hw.x);

	Line l1(loc.x, loc.y, loc.x, to_string(y + w), "black");
	Line l2(loc.x, to_string(y + w), to_string(x + h), to_string(y + w), "black");
	Line l3(to_string(x + h), to_string(y + w), to_string(x + h), loc.y, "black");
	Line l4(to_string(x + h), loc.y, loc.x, loc.y, "black");
	Text t1(to_string(x + 20), to_string(y - 2), "20", title);

	if (anim == "true")
	{
		l1.CreateAnimate(loc.y, to_string(y + 100), "1s", "0s", "opacity");
		l2.CreateAnimate(loc.x, to_string(x + 100), "1s", "0s", "opacity");
		l3.CreateAnimate(to_string(y + 100), loc.y, "1s", "0s", "opacity");
		l4.CreateAnimate(to_string(x + 100), loc.x, "1s", "0s", "opacity");
		t1.CreateAnimate("0", "1", "4s", "0s", "opacity");
	}

	plotexport += l1.Export();
	plotexport += l2.Export();
	plotexport += l3.Export();
	plotexport += l4.Export();
	plotexport += t1.Export();

	ifstream input;
	string address = "data//";
	address += data;
	input.open(address);
	//open data file and read from file
	points.clear();
	while (!input.eof())
	{
		string tmp;
		point *tmppoint = new point;
		getline(input, tmp, ',');
		double tmpint = stod(tmp);
		tmpint += x;
		tmppoint->x = to_string(tmpint);
		getline(input, tmp, '\n');
		tmpint = stod(tmp);
		tmpint = y + w - tmpint;
		tmppoint->y = to_string(tmpint);
		points.push_back(tmppoint);
	}
	//check type plot
	if (type == "line")
	{
		string tmppoints;
		for (int i = 0; i < points.size(); i++)
		{
			tmppoints += points[i]->x;
			tmppoints += ",";
			tmppoints += points[i]->y;
			tmppoints += " ";
		}
		Polyline p(tmppoints,"none","red");
		if (anim == "true")
			p.CreateAnimate("0", "1", "2s", "0s", "opacity");
		plotexport += p.Export();
	}
	else if (type == "scatter")
	{
		for (int i = 0; i < points.size(); i++)
		{
			Circle c(points[i]->x, points[i]->y, "5");
			if (anim == "true")
				c.CreateAnimate("0", "5", "4s", "0s", "r");
		plotexport += c.Export();
		}
	}
	else if (type == "bar")
	{

	}
	else if (type == "histogram")
	{

	}



	
	//export svg
	return plotexport;
}

void Plot::SetOption(istream &input, string &name)
{
	string tmpname;
	int location;
	location = name.find('-');
	string option;//count option
	getline(input, tmpname, '(');
	if (tmpname != " ")
		throw undefined_command();
	getline(input, option, ')');
	getline(input, tmpname);
	if (tmpname != "")
		throw undefined_command();
	if (name == "x")
		loc.x = option;
	else if (name == "y")
		loc.y = option;
	else if (name == "data")
		data = option;
	else if (name == "title")
		title = option;
	else if (name == "type")
		type = option;
	else if (name == "animated")
		anim = option;
	else if (name == "height")
		hw.x = option;
	else if (name == "width")
		hw.y = option;
	else
		throw undefined_command();

}

void Plot::GetOption(std::string name)
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
		if (name == "x")
			std::cout << std::endl << loc.x;
		else if (name == "y")
			std::cout << std::endl << loc.y;
		else if (name == "data")
			std::cout << std::endl << data;
		else if (name == "title")
			std::cout << std::endl << title;
		else if (name == "type")
			std::cout << std::endl << type;
		else
			throw undefined_command();
	}
}