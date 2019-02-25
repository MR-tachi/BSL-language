#include "Animation.h"
#include <iostream>
#include "SVGEXCEPT.h"

using namespace std;

Animation::Animation(string name)
{
	Name = name;
}


Animation::~Animation()
{
}

string Animation::Export()
{
	std::string output = "\n    <animate attributeType=\""; 
	output += att_type;
	output += "\" attributeName=\"";
	output += att_name;
	output += "\" from=\"";
	output += from;
	output += "\" to=\"";
	output += to;
	output += "\"\n\tdur=\"";
	output += dur;
	output += "\" repeatCount=\"";
	output += repeat;
	output += "\"/>";
	return output;
}

string Animation::getname()
{
	return Name;
}

void Animation::SetOption(string option)
{
	string count;//count option
	string tmp;//for check commands
	getline(std::cin, tmp, '(');
	if (tmp != " ") 
		throw undefined_command();
	getline(std::cin, count, ')');
	getline(std::cin, tmp);
	if (tmp != "") 
		throw undefined_command();
	if (option == "dur")
		dur = count;
	else if (option == "attributeType")
		att_type = count;
	else if (option == "attributeName")
		att_name = count;
	else if (option == "from")
		from = count;
	else if (option == "to")
		to = count;
	else if (option == "repeatCount")
		repeat = count;
	else 
		throw undefined_command();
}