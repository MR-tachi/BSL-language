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
	virtual std::string Export() = 0;
	std::string getname();
	void ShowAnimates();
	void CreateAnimate(std::string);
	virtual void SetOption(std::string) = 0;
	void ClearAnim(std::string);
protected:
	std::string Name;
	std::string stroke_width;
	std::string opacity;
	std::string stroke;
	std::string fill;
	std::vector<Animation*> Anim;
	void SetOption(std::string, std::string);
	void SetAnim(std::string);
};

struct point
{
	std::string x;
	std::string y;
};