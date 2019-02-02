#pragma once
#include "Shape.h"
class Text :
	public Shape
{
public:
	Text(std::string);
	~Text();
	void information();
	std::string Export();
	void SetOption(std::string);
private:
	point loc;
	std::string size;
	std::string font;
	std::string text;
};