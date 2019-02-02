#pragma once
#include "Shape.h"
class Rectangle :
	public Shape
{
public:
	Rectangle(std::string);
	~Rectangle();
	void information();
	std::string Export();
	void SetOption(std::string);
	void GetOption(std::string);
	//void SetAll(std::string, std::string);
private:
	point loc;
	point r;
	std::string width;
	std::string height;
};