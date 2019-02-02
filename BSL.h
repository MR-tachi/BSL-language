#pragma once
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
	void CreateAnimate(std::string&);
	void ExportFile(std::string&);
	void SetOption(std::string&);
	void ShowAnimates();
	std::string height , width ;
	std::vector<Shape*> shapes;
};