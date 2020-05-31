#ifndef BASICCOMMANDS_HEADER_INCLUDED
#define BASICCOMMANDS_HEADER_INCLUDED
#include<fstream>

using namespace std;

const int MAX_COMMAND_LENGHT = 15;
/// класът се използва за работа с по-простите команди от командния ред (help,exit)  както и подобните команди (add,load)
///
/// член данни - име на командата
class BasicCommands
{
private:
	char name[MAX_COMMAND_LENGHT];
public:
	 /// конструктор по подразбиране
	BasicCommands();
	/// конструктор с параметър име на команда
	BasicCommands(const char* name);

	/// зарежда файл по нужния начин (binary, ascii)
	/// @param image_name Име на картинката
	bool load(const char* image_name);
	/// принтира командите, с които разполага приложението
	void help() const;
	/// излиза от програмата
	void exit() const;

	/// добавя/зарежда файл по нужния начин в текуща сесия
	/// @param image_name Име на картинката
	void add(const char* image_name);
};
#endif
