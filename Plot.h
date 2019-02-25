#pragma once
#include "Shape.h"
#include "Rectangle.h"
#include "Line.h"
#include "Polyline.h"
#include "Text.h"

namespace SVG {

class Plot :
	public Shape
{
public:	
	Plot(std::string);
	~Plot();
	void information();
	std::string Export();
	void SetOption(std::string);
	void GetOption(std::string);

private:
	point loc;
	std::string data;
	std::string type;
	std::string title;
	
};

} 
