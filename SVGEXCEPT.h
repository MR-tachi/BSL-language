#pragma once
#include <stdexcept>
#include <iostream>
namespace SVG
{
class undefined_command :
	public std::runtime_error
{
public: undefined_command()
	: std::runtime_error("The command you enter is not defined. Use \"help\" command for guide.")
{
	std::cin.ignore(INT_MAX, '\n');
}
};

class shape_notexist:
	public std::runtime_error
{
public: shape_notexist()
	: std::runtime_error("The shape not exist. Use \"list\" to see exist shapes.") { std::cin.ignore(INT_MAX, '\n'); }
};

class undefined_shape :
	public std::runtime_error
{
public: undefined_shape()
	: std::runtime_error("The shape undefined in this program. Use \"help\" to see defined shapes.") { std::cin.ignore(INT_MAX, '\n'); }
};

class repeatly_name :
	public std::runtime_error
{
public: repeatly_name()
	: std::runtime_error("The name you entered already has exist. Use\"list\" to see exist shapes.") { std::cin.ignore(INT_MAX, '\n'); }
};
class set_frame :
	public std::runtime_error
{
public: set_frame()
	: std::runtime_error("You dont set picture frame. Use\"help\" to see guide.") { std::cin.ignore(INT_MAX, '\n'); }
};

class file_opening :
	public std::runtime_error
{
public: file_opening()
	: std::runtime_error("File can not open. Fix the problem and try again.") { std::cin.ignore(INT_MAX, '\n'); }
};
}