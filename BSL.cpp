#include "BSL.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Line.h"
#include "Polyline.h"
#include "Polygon.h"
#include "Text.h"
#include "Plot.h"
#include "SVGEXCEPT.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <direct.h>
#include <fstream>

using namespace std;
using namespace SVG;

BSL::BSL(short a, short b)
{
	bck = a;
	font = b;
}


BSL::~BSL()
{
}

void BSL::start()
{
	option(bck, font);
	system("cls");
	while (true)
	{
		setcolor((bck * 16) + font);
		cout << "\n> ";
		string Word;
		cin >> Word;
		try 
		{
			if (Word == "load")
				Loadfile();
			else
				checkcommand(cin, Word);
			setcolor((bck * 16) + font - 1);
			cout << "\n OK";

		}
		catch (exception & exc)
		{
			setcolor((bck * 16) + font + 1);
			cerr << endl << "\a Warning!! :" << exc.what() << endl;
		}
	}
}

void BSL::ShowShapes()
{
	setcolor((bck * 16) + font - 1);
	cout << endl;
	for (short i = 0; i < shapes.size(); i++)
		if (shapes[i] != nullptr)
		shapes[i]->information();
}

void BSL::ClearShape(string &Word)
{

	if (Word == "all" || Word == "ALL")
	{
		while (!shapes.empty())
		{
			Shape * tmp = shapes.at(shapes.size() - 1);
			setcolor((bck * 16) + font - 1);
			cout << "\n Shape " << tmp->getname() << " removed.\n";
			delete tmp;
			tmp = nullptr;
			shapes.pop_back();
		}
	}
	else 
	{
		std::string tmpname;
		int location;
		location = Word.find('-');
		if (location == std::string::npos) // chek anim or no if flase then its animate
		{
			for (short i = 0; i < shapes.size(); i++)
				if (shapes[i]->getname() == Word)
				{
					Shape * tmp = shapes[i];
					setcolor((bck * 16) + font - 1);
					cout << "\n Shape " << tmp->getname() << " removed.\n";
					delete tmp;
					shapes[i] = nullptr;
					break;
				}
				else if(i == shapes.size() - 1)
					throw shape_notexist();
		}
		else
		{
			tmpname = Word.substr(0, location); //anim name
			string animname = Word.substr(location + 2, string::npos);
			if (Word[location + 1] == '>')
			{
				for (short i = 0; i < shapes.size(); i++)
					if(shapes[i]->getname() == tmpname)
						shapes[i]->ClearAnim(animname);
			}
			else throw undefined_command();

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
	cout << "\n> option\t\t\t\t\t\tchange program color";
	cout << "\n> animation \"shape-name\" \"animation name\"\t\tcreate a animation for shape";
	cout << "\n   > set \"shape-name\"->\"animation-name\"->\'dur\' - \'attributename\'";
	cout << "- \'from\' - \'to\' - \'repeatcount\'\tset option of animation";
	cout << "\n   > clear \"shape-name\"->\"animation-name\"\t\tclear the animation";
	cout << "\n   > list animate \"shape-name\"\t\t\t\tshow all animations of shape";
	cout << "\n\n---------------------------------------------------------------------------------------------------------";
	cout << "\n\n  Shape types:\n\tcircle - rectangle - ellipse - line - polygon - polyline - plot - text\n\n";
	cout << "---------------------------------------------------------------------------------------------------------";
}

void BSL::CreateShape(std::istream &input,string &type)
{
	string name;
	input >> name;
	for (short i = 0; i < shapes.size(); i++)
		if (name == shapes[i]->getname())
			throw repeatly_name();
	if (type == "rectangle")
		shapes.push_back(new Rectangle(name));
	else if (type == "circle")
		shapes.push_back(new Circle(name));
	else if (type == "polyline")
		shapes.push_back(new Polyline(name));
	else if (type == "polygon")
		shapes.push_back(new Polygon(name));
	else if (type == "line")
		shapes.push_back(new Line(name));
	else if (type == "elipse")
		shapes.push_back(new Ellipse(name));
	else if (type == "text")
		shapes.push_back(new Text(name));
	else if (type == "plot")
		shapes.push_back(new Plot(name));
	else
		throw undefined_shape();
}

void BSL::CreateAnimate(std::istream &input,std::string &shape)
{
	string name;
	input >> name;
	for (short i = 0; i < shapes.size(); i++)
		if (shape == shapes[i]->getname())
		{
			shapes[i]->CreateAnimate(name);
		}
		else if (i == shapes.size())
			throw shape_notexist();
		
}

void BSL::ShowAnimates(std::istream & input)
{
	string Word;
	input >> Word;
	for (short i = 0; i < shapes.size(); i++)
		if (shapes[i]->getname() == Word)
			if (shapes[i])
				shapes[i]->ShowAnimates();
			else
				throw shape_notexist();
}

void BSL::Loadfile()
{
	string Word;
	string address;
	getline(cin, Word, '\"');
	if (Word != " (")
		throw undefined_command();
	getline(cin, address, '\"');
	cin >> Word;
	if (Word != ")")
		throw undefined_command();
	ifstream file;
	address.insert(0, "programs//");
	file.open(address);
	if (!file)
		throw file_opening();
	while (!file.eof())
	{
		file >> Word;
		if (Word == "#")
		{
			getline(file, Word, '\n');
		}
		else
			checkcommand(file, Word);
	}

}

void BSL::checkcommand(std::istream &input,string Word)
{
	if (Word == "list" || Word == "LIST")
	{
		setcolor((bck * 16) + font - 1);
		getline(input, Word, '\n');
		if (Word == "")
			ShowShapes();
		else
		{
			input >> Word;
			if (Word == "animate")
				ShowAnimates(input);
			else throw undefined_command();
		}
	}
	else if (Word == "-C" || Word == "-c")
	{
		system("cls");
	}
	else if (Word == "animation" || Word == "ANIMATION")
	{
		input >> Word;
		CreateAnimate(input , Word);
	}
	else if (Word == "load"|| Word == "LOAD")
	{
		
	}
	else if (Word == "setAll")
	{
		input >> Word;
		SetAll(input , Word);
	}
	else if (Word == "set" || Word == "SET")
	{
		input >> Word;
		if (Word == "width" || Word == "height")
		{
			string count;
			getline(input, count, '(');
			if (count != " ") 
				throw undefined_command();
			getline(input, count, ')');
			if (count == "") 
				throw undefined_command();
			if (Word == "width")
				width = count;
			else if (Word == "height")
				height = count;
		}
		else SetOption(input, Word);
	}
	else if (Word == "create" || Word == "CREATE")
	{
		input >> Word;
		CreateShape(input , Word);
	}
	else if (Word == "option" || Word == "OPTION")
	{
		cout << "\n\n\t\tchoose font color\n\t\t\t\t";
		for (int i = 0; i < 16; i++)
		{
			setcolor(i);
			cout << i << " ";
		}
		setcolor(font);
		cout << "  : ";
		input >> font;
		cout << "\n\n\t\tchoose background color\n\t\t\t\t";
		for (int i = 0; i < 16; i++)
		{
			setcolor((i * 16) + font);
			cout << i << " ";
		}
		cout << "  : ";
		input >> bck;
		option(bck, font);
	}
	else if (Word == "clear" || Word == "CLEAR")
	{
		input >> Word;
		ClearShape(Word);
	}
	else if (Word == "export" || Word == "EXPORT")
	{
		if (width.empty() && height.empty())
			throw set_frame();
		getline(input, Word, '\"');
		if (Word != " (") 
			throw undefined_command();
		getline(input, Word, '\"');
		ExportFile(Word);
		input >> Word;
		if (Word != ")") 
			throw undefined_command();
	}
	else if (Word == "get" || Word == "GET")
	{
		input >> Word;
		GetOption(Word);
	}
	else if (Word == "exit" || Word == "EXIT")
	{
		cout << "\n\n  Program has Ended.\n\n    press any key to exit....";
		_getwch();
		exit(0);
	}
	else if (Word == "help" || Word == "HELP")
	{
		ShowHelp();
	}
	else 
		throw undefined_command();
}

void BSL::ExportFile(string& filename)
{
	string output;
	output += "<?xml version=\"1.0\"?>\n<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n\"http://www.w3.org/Graphics/SVG/1.1DTD/svg11.dtd\">";
	output += "\n<svg width = \"";
	output += width;
	output += "\" height = \"";
	output += height;
	output += "\" version = \"1.1\"\n\txmlns = \"http://www.w3.org/2000/svg\">";

	for (short i = 0; i < shapes.size(); i++)
		output += shapes[i]->Export();

	output += "\n</svg>\n";
	filename.insert(0, "Export//");
	ofstream file(filename, ios::out);
	if (!file)
	{
		cout << "";
		throw file_opening();

	}
	else 		
		file << output;
		file.close();

}

void BSL::SetOption(istream & input,string& name)
{
	int loc;
	loc = name.find('-');
	if (loc == string::npos) 
		throw undefined_command();
	string tmpname = name.substr(0, loc);//shape name
	if (name[loc + 1] != '>') 
		throw undefined_command();
	for (short i = 0; i < shapes.size() ; i++)
	{
		if (shapes[i]->getname() == tmpname)
		{
			shapes[i]->SetOption(input,name.substr(loc + 2, string::npos));//set shape options entered
		}
		else if (i == shapes.size())
			throw shape_notexist();
	}
}

void BSL::GetOption(std::string & name)
{
	int loc;
	loc = name.find('-');
	if (loc == string::npos) 
		throw undefined_command();

	string tmpname = name.substr(0, loc);//shape name
	if (name[loc + 1] != '>') 
		throw undefined_command();
	for (short i = 0; i < shapes.size(); i++)
	{
		if (shapes[i]->getname() == tmpname)
		{
			shapes[i]->GetOption(name.substr(loc + 2, string::npos));//set shape options entered
		}
		else if (i == shapes.size())
			throw shape_notexist();
	}
}

void BSL::SetAll(istream &input ,string &type)
{
	std::string tmpname;
	std::string option;//count option
	getline(input, tmpname, '(');
	if (tmpname != " ") 
		throw undefined_command();
	getline(input, option, ')');
	getline(input, tmpname);
	if (tmpname != "") 
		throw undefined_command();
	for(short i=0;i<shapes.size();i++)
	shapes[i]->SetOption(type, option);//set option to all shapes
}

void SVG::setcolor(short color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}

void BSL::option(short a, short b)
{
	bck = a;
	font = b;
	char color[9];
	color[0] = 'c';
	color[1] = 'o';
	color[2] = 'l';
	color[3] = 'o';
	color[4] = 'r';
	color[5] = ' ';
	switch (a)
	{
	case 0: color[6] = '0'; break;
	case 1: color[6] = '1'; break;
	case 2: color[6] = '2'; break;
	case 3: color[6] = '3'; break;
	case 4: color[6] = '4'; break;
	case 5: color[6] = '5'; break;
	case 6: color[6] = '6'; break;
	case 7: color[6] = '7'; break;
	case 8: color[6] = '8'; break;
	case 9: color[6] = '9'; break;
	case 10: color[6] = 'a'; break;
	case 11: color[6] = 'b'; break;
	case 12: color[6] = 'c'; break;
	case 13: color[6] = 'D'; break;
	case 14: color[6] = 'E'; break;
	case 15: color[6] = 'F'; break;
	}
	switch (b)
	{
	case 0: color[7] = '0'; break;
	case 1: color[7] = '1'; break;
	case 2: color[7] = '2'; break;
	case 3: color[7] = '3'; break;
	case 4: color[7] = '4'; break;
	case 5: color[7] = '5'; break;
	case 6: color[7] = '6'; break;
	case 7: color[7] = '7'; break;
	case 8: color[7] = '8'; break;
	case 9: color[7] = '9'; break;
	case 10: color[7]= 'A'; break;
	case 11: color[7] = 'B'; break;
	case 12: color[7] = 'C'; break;
	case 13: color[7] = 'D'; break;
	case 14: color[7] = 'E'; break;
	case 15: color[7] = 'F'; break;
	}
	color[8] = '\0';
	system(color);
}