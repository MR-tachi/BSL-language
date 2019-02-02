#include "Shape.h"
#include <iostream>

using namespace std;

Shape::Shape()
{
}

Shape::~Shape(){}


string Shape::getname()
{
	return Name;
}

void Shape::ShowAnimates()
{
	cout << "   " << Name << " animates:\n     ";
	for (short i = 0; i < Anim.size(); i++)
	{
		std::cout << Anim[i]->getname();
		if (i != Anim.size() - 1)
			cout << "\n     ";
	}
}

void Shape::CreateAnimate(string name)
{
	for(short i=0;i<Anim.size();i++)
		if (name == Anim[i]->getname()) {}
			//throw excp repeatly name
	Anim.push_back(new Animation(name));
}

void Shape::SetOption(string name, string option)
{
	if (name == "stroke_width")
		stroke_width = option;
	else if (name == "opacity")
		opacity = option;
	else if (name == "stroke")
		stroke = option;
	else if (name == "fill")
		fill = option;
	else {}
		//throw excep command
}

void Shape::SetAnim(string animoption)
{
	int loc;
	loc = animoption.find('-');
	if (loc == string::npos) {}
		//throw excp command
	if (animoption[loc+1] != '>') {}
		//throw excp command
	string animname = animoption.substr(0, loc);
	for (short i = 0; i < Anim.size(); i++)
	{
		if (Anim[i]->getname() == animname)
		{
			Anim[i]->SetOption(animoption.substr(loc + 2, std::string::npos));
		}
		{}
		//throw excp not exist
	}
}