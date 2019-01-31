#pragma once
#include <vector>
#include "Shape.h"

class BSL
{
public:
	BSL();
	~BSL();
	void start();
private:
	short width;
	void ShowShapes();
	void ClearShape(std::string&);
	void ShowHelp();
	short height;
	std::vector<Shape*> shapes;
};

