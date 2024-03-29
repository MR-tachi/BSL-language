#pragma once
#include "Shape.h"
namespace SVG
{

class Text :
	public Shape
{
public:
	Text(std::string);
	Text(std::string x, std::string y, std::string s, std::string t);
	~Text();
	void information();
	std::string Export();
	void SetOption(std::istream&, std::string&);
	void GetOption(std::string);

private:
	point loc;
	std::string size;
	std::string font;
	std::string text;
};


}