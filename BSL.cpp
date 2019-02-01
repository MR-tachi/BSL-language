#include "BSL.h"
#include <iostream>
#include <string>
#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Line.h"
#include "Polyline.h"
#include "Polygon.h"
#include <fstream>

using namespace std;

BSL::BSL()
{
}


BSL::~BSL()
{
}

void BSL::start()
{
	while (true)
	{
		cout << "\n> ";
		string Word;
		cin >> Word;
		if (Word == "list" || Word == "LIST")
		{
			if (cin.eof())
				ShowShapes();
			else 
			{
				cin >> Word;
				if (Word == "animate")
					ShowAnimates();
				else {}
					//throw excp undifined command
			}
		}
		else if (Word == "set" || Word == "SET")
		{
			cin >> Word;
			if (Word == "width")
				width = Word;
			else if (Word == "height")
				height = Word;
			else SetOption(Word);
		}
		else if (Word == "create" || Word == "CREATE")
		{
			cin >> Word;
			CreateShape(Word);
		}
		else if (Word == "clear" || Word == "CLEAR")
		{
			cin >> Word;
			ClearShape(Word);
		}
		else if (Word == "export" || Word == "EXPORT")
		{
			if (width.empty() && height.empty()) {}
				//throw exception dont set w & h
			getline(cin, Word, '\"');
			if (Word != " (") {}
				//throw exc undif command
			getline(cin, Word,'\"');
			ExportFile(Word);
			cin >> Word;
			if (Word != ")") {};
				//throw excpect undifined command
		}
		else if (Word == "exit" || Word == "EXIT")
		{
			cout << "\n\nProgram has Ended\n";
			break;
		}
		else if (Word == "help" || Word == "HELP")
		{
			ShowHelp();
		}
		//theow exception undifined command
		else cout <<endl<< Word << "\a undifend command. use \"help\" for guide\n";
	}
}

void BSL::ShowShapes()
{
	for (short i = 0; i < shapes.size(); i++)
		shapes[i]->information();
}

void BSL::ClearShape(string & Word)
{
	if (Word == "all" || Word == "ALL")
	{
		while (!shapes.empty())
		{
			Shape * tmp = shapes.at(shapes.size() - 1);
			cout << "shape " << tmp->getname() << " removed.\n";
			delete tmp;
			tmp = nullptr;
			shapes.pop_back();
		}
	}
	else
	{
		for (short i = 0; i < shapes.size(); i++)
			if (shapes[i]->getname() == Word)
			{
				Shape * tmp = shapes[i];
				cout << "shape " << tmp->getname() << " removed.\n";
				delete tmp;
				tmp = nullptr;
				break;
				if (i == shapes.size() - 1)
					cout << "\nerror!! :" << Word << " not found.\n";
			}
	}

}

void BSL::ShowHelp()
{
	cout << "\n> create \"shape-type\" \"shape-name\"\t\t\tcreate a new shape";
	cout << "\n> set width/height\t\t\t\t\tset resolution of picture";
	cout << "\n> clear \'shape-name\' - \'all\'\t\t\t\tclear the shape(s)";
	cout << "\n> list \t\t\t\t\t\t\tshow all shapes created";
	cout << "\n> set \"shape-name\"->\'x\' - \'y\' - \'height\' - \'fill\'\tset option of shape";
	cout << "\n> get \"shape-name\"->\'x\' - \'y\' - \'height\' - \'fill\'\tget option of shape";
	cout << "\n> export (\"file-name.svg\")\t\t\t\texport the picture to export folder\n\n";
	cout << "\n> animation \"shape-name\" \"animation name\"\t\tcreate a animation for shape";
	cout << "\n   > set \"shape-name\"->\"animation-name\"->\'dur\' - \'attributename\'";
	cout << "- \'from\' - \'to\' - \'repeatcount\'\tset option of animation";
	cout << "\n   > clear \"shape-name\"->\"animation-name\"\t\tclear the animation";
	cout << "\n   > list animate \"shape-name\"\t\t\t\tshow all animations of shape\n\n";
	cout << "---------------------------------------------------------------------------------------------------------";
	cout << "\n\n  Shape types:\n\tcircle - rectangle - ellipse - line - polygon - polyline\n\n";
	cout << "---------------------------------------------------------------------------------------------------------";
}

void BSL::CreateShape(string &type)
{
	string name;
	cin >> name;
	for (short i = 0; i < shapes.size() ; i++ )
		if (name == shapes[i]->getname()) {}
		//throw exception reapeatly name
	if (type == "rectangle")
		shapes.push_back(new Rectangle(name));
	else if (type=="circle")
		shapes.push_back(new Circle(name));
	else if (type == "polyline")
		shapes.push_back(new Polyline(name));
	else if (type == "polygon")
		shapes.push_back(new Polygon(name));
	else if (type == "line")
		shapes.push_back(new Line(name));
	else if (type == "elipse")
		shapes.push_back(new Ellipse(name));
	else 
		//throw exception udinfined shape
		cout<< endl << type << "\a undifend type. use \"help\" for guide\n";
}

void BSL::ShowAnimates()
{
	string Word;
	cin >> Word;
	for (short i = 0; i < shapes.size(); i++)
		if (shapes[i]->getname() == Word)
			shapes[i]->ShowAnimates();
		else {}
			//throw excp not exist
}

void BSL::ExportFile(string& filename)
{
	string output;
	output += "<?xml version=\"1.0\"?>\n<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n\"http://www.w3.org/Graphics/SVG/1.1DTD/svg11.dtd\">";
	output += "\n<svg width = \"";
	output += width;
	output += "\" height = \"";
	output += "\" version = \"1.1\"\n\txmlns = \"http://www.w3.org/2000/svg\">";

	for (short i = 0; i < shapes.size(); i++)
		output += shapes[i]->Export();

	output += "\n</svg>\n";
	filename.insert(0, "Export//");
	ofstream file(filename, ios::out);
	if (!file)
	{
		cout << "";
		//throw exception file coudnt open

	}
	else 		
		file << output;
		file.close();

}

void BSL::SetOption(string& name)
{
	int loc;
	loc = name.find('-');
	if (loc == string::npos) {}
		//throw excep undifined command
	string tmpname = name.substr(0, loc-1);//shape name
	if (name[loc + 1] != '>') {}
		//throw excep undifined command
	for (short i = 0; i < shapes.size() ; i++)
	{
		if (shapes[i]->getname() == tmpname)
		{
			shapes[i]->SetOption(name.substr(loc + 2, string::npos));//set shape options entered
		}
		else if (i == shapes.size()) {}
				//throw excep not exist
	}
}