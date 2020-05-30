#ifndef BASICCOMMANDS_HEADER_INCLUDED
#define BASICCOMMANDS_HEADER_INCLUDED
#include<fstream>

using namespace std;
const int MAX_COMMAND_LENGHT = 15;
class BasicCommands
{
private:
	char name[MAX_COMMAND_LENGHT];
public:
	BasicCommands();
	BasicCommands(const char* name);
	//basic comamnds
	bool load(const char* image_name);
	void help() const;
	void exit() const;
	//other commands
	void add(const char* image_name);
};
#endif
