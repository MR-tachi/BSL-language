#pragma once
#include <string>

class Animation
{
public:
	Animation();
	~Animation();
	std::string Export();
	std::string getname();
	void SetOption(std::string);
private:
	std::string name;
	std::string att_type;
	std::string att_name;
	std::string from;
	std::string to;
	std::string dur;
	std::string repeat;
};