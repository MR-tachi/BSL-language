#pragma once
#include <string>
#include <vector>
#include "Animation.h"

namespace SVG
{

class Shape
{
public:
	Shape();
	~Shape();
	virtual void information() = 0;
	virtual std::string Export() = 0;
	std::string getname();
	void ShowAnimates();
	void CreateAnimate(std::string);
	virtual void SetOption(std::istream&,std::string&) = 0;
	virtual void GetOption(std::string) = 0;
	void ClearAnim(std::string);
	void SetOption(std::string, std::string);
protected:
	std::string Name;
	std::string stroke_width;
	std::string opacity;
	std::string stroke;
	std::string fill;
	std::vector<Animation*> Anim;
	void GetOption(std::string, std::string);
	void SetAnim(std::istream&,std::string&);
};

struct point
{
	std::string x;
	std::string y;
};
}