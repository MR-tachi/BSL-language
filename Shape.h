#pragma once
#include <string>
class Shape
{
public:
	Shape();
	~Shape();
	virtual void information() = 0;
	std::string getname();
protected:
	std::string Name;
};

