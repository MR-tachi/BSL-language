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
		if (Anim[i])
		{
			std::cout << Anim[i]->getname();
			if (i != Anim.size() - 1)
				cout << "\n     ";
		}
		else if (i == Anim.size()) {}
			//throw excp not exist
}

void Shape::CreateAnimate(string name)
{
	for(short i=0;i<Anim.size();i++)
		if (name == Anim[i]->getname()) {}
			//throw excp repeatly name
	Anim.push_back(new Animation(name));
}

void Shape::ClearAnim(std::string animname)
{
	for (short i=0;i< Anim.size(); i++)
	{
		if (animname == Anim[i]->getname())
		{
			Animation* tmp = Anim[i];
			cout << "animation " << tmp->getname() << " removed.\n";
			delete tmp;
			tmp = nullptr;
		}
		else if(i == Anim.size()){}
			//throw excp not exist
		
	}
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

void Shape::GetOption(std::string name, std::string option)
{
	if (name == "stroke_width")
		std::cout << std::endl << stroke_width;
	else if (name == "opacity")
		std::cout << std::endl << opacity;
	else if (name == "stroke")
		std::cout << std::endl << stroke;
	else if (name == "fill")
		std::cout << std::endl << fill;
	else {}
	//throw excep command
}