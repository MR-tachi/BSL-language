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
	void CreateShape(std::istream &,std::string&);
	void CreateAnimate(std::istream &,std::string&);
	void ExportFile(std::string&);
	void SetOption(std::istream&,std::string&);
	void GetOption(std::string&);
	void SetAll(std::istream &, std::string&);
	void ShowAnimates(std::istream &);
	void Loadfile();
	std::string height , width ;
	std::vector<Shape*> shapes;
	short bck, font;
	void checkcommand(std::istream &,std::string);
	void option(short, short);
};

void setcolor(short color);
}