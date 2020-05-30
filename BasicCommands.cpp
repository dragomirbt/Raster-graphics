#include "BasicCommands.h"
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

BasicCommands::BasicCommands()
{
	strcpy(this->name, "");
}
BasicCommands::BasicCommands(const char* name)
{
	strcpy(this->name, name);
}
bool BasicCommands::load(const char* image_name)
{
	ifstream file(image_name, ios::in);
	if (!file)
	{
		cout << "Cannot open image\n";
		file.close();
		return 0;
	}
	char file_format[3]; //MAX_SIZE_FORMAT
	file >> file_format;
	if ((strcmp(file_format, "P1")) && (strcmp(file_format, "P2")) && (strcmp(file_format, "P3")))
	{
		file.close();
		 file.open(image_name, ios::binary);
		if (!file)
		{
			cout << "Cannot open image\n";
			file.close();
			return 0;
		}
	}
	cout << "Image: " << image_name << " added\n";
	file.close();
	return 1;
}
void BasicCommands::help() const
{
	cout << "The following commands are supported:\n";
	cout << "load <image path>	loads image\n";
	cout << "close			closes currently opened file\n";
	cout << "save			saves the currently open file\n";
	cout << "saveas <image path>	saves the currently open file in <image path>\n";
	cout << "help			prints this information\n";
	cout << "exit			exists the program\n";
	cout << "grayscale		turns colored images into black and white\n";
	cout << "monochrome		turns colored images into black and white without grey shades\n";
	cout << "negative		reverses the colors of the image\n";
	cout << "rotate			rotates left or right 90 degrees\n";
	cout << "undo			removes last trnsormation\n";
	cout << "session info		prints information about the current session\n";
	cout << "swith			switches to sesion according to given ID number\n";
	cout << "collage			makes a collage of two images\n";
}
void BasicCommands::exit() const
{
	cout << "Exiting the program...";
}
//other commands
void BasicCommands::add(const char* image)
{
	load(image);
}
