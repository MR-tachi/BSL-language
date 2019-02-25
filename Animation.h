#pragma once
#include <string>

namespace SVG
{

class Animation
{
public:
	Animation(std::string);
	~Animation();
	std::string Export();
	std::string getname();
	void SetOption(std::istream &, std::string&);
private:
	std::string Name;
	std::string att_type;
	std::string att_name;
	std::string from;
	std::string to;
	std::string dur;
	std::string repeat;
};
}