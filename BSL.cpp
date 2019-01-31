#include "BSL.h"
#include <iostream>
#include <string>

using namespace std;

BSL::BSL()
{
	width = 300; //default value
	height = 300; //default value
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
			ShowShapes();
		else if (Word == "create" || Word == "CREATE")
		{

		}
		else if (Word == "clear" || Word == "CLEAR")
		{
			cin >> Word;
			ClearShape(Word);
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
		else cout <<endl<< Word << " undifend. use \"> help\" for guide\n";
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
	cout << "\n> animation \"shape-name\" \"animation name\"\t\tcreate a animation for shape";
	cout << "\n   > set \"shape-name\"->\"animation-name\"->\'dur\' - \'attributename\' - \'from\' - \'to\' - \'repeatcount\'\tset option of animation";
	cout << "\n   > clear \"shape-name\"->\"animation-name\"\t\tclear the animation";
	cout << "\n   > list animate \"shape-name\"\t\t\t\tshow all animations of shape";
	cout << "\n> export (\"file-name.svg\")\t\t\t\texport the picture to export folder\n";
}
