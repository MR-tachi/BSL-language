#include "Animation.h"
#include <iostream>

using namespace std;

Animation::Animation()
{
}


Animation::~Animation()
{
}

string Animation::Export()
{
	std::string output = "\n    <animate attributeType=\""; 
	output += att_type;
	output += "\" attributeName = \"";
	output += att_name;
	output += "\" from = \"";
	output += from;
	output += "\" to = \"";
	output += to;
	output += "\"\n\tdur = \"";
	output += dur;
	output += "\" repeatCount = \"";
	output += repeat;
	output += "\"/>";
	return output;
}

string Animation::getname()
{
	return name;
}

void Animation::SetOption(string option)
{
	string count;//count option
	string tmp;//for check commands
	getline(std::cin, tmp, '(');
	if (tmp != " (") {}
	//theow except cmmand
	getline(std::cin, count, ')');
	cin >> tmp;
	if (tmp != ")") {}
	//throw excp command
	if (option == "dur")
		dur = count;
	else if (option == "att_type")
		att_type = count;
	else if (option == "att_name")
		att_name = count;
	else if (option == "from")
		from = count;
	else if (option == "to")
		to = count;
	else if (option == "repeat")
		repeat = count;
	else {}
		//throw exp command
}