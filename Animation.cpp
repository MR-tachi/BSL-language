#include "Animation.h"



Animation::Animation()
{
}


Animation::~Animation()
{
}

std::string Animation::Export()
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
