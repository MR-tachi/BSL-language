#pragma once
#include <string>
#include <vector>
#include "Animation.h"
class Shape
{
public:
	Shape();
	~Shape();
	virtual void information() = 0;
	virtual std::string Export()=0;
	std::string getname();
protected:
	std::string Name;
	short stroke_width , opacity ;
	std::string stroke , fill;
	std::vector<Animation*> Anim;
};

struct point
{
	short x, y;
};

