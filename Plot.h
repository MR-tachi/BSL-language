#pragma once
#include "Shape.h"
class Plot :
	public Shape
{
public:	
	Plot(std::string);
	~Plot();
	void information();
	std::string Export();
	void SetOption(std::string);
	void GetOption(std::string);

private:
	point loc;
	std::string data;
	std::string type;
	std::string title;
	
};

