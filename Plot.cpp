#include "Plot.h"
#include <iostream>
#include <fstream>
#include "SVGEXCEPT.h"
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
	//open data file and read from file
	ifstream input; 

	//check type plot

	//create a plot in svg 

	//export svg

	return std::string();
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
