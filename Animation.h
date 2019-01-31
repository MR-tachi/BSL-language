#pragma once
#include <string>

class Animation
{
public:
	Animation();
	~Animation();
	std::string Export();
private:
	std::string att_type;
	std::string att_name;
	int from;
	int to;
	std::string dur;
	std::string repeat;
};