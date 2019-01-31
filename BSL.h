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
	void ShowShapes();
	void ClearShape(std::string&);
	void ShowHelp();
	void CreateShape(std::string&);
	void ExportFile(std::string);
	short height , width ;
	std::vector<Shape*> shapes;
};