#pragma once
#include "Shape.h"

namespace SVG {

class BSL
{
public:
	BSL(short, short);
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
	void GetOption(std::string&);
	void SetAll(std::string&);
	void ShowAnimates();
	std::string height , width ;
	std::vector<Shape*> shapes;
	short bck, font;
	void checkcommand(std::string);
	void option(short, short);
};

void setcolor(short color);
}