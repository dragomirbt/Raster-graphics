#include "Close.h"
#include <iostream>
void Close::execute(Files& images)
{
	const char* last_file_name = images.getLastAddedFile().getImageName();
	images.deleteLastFile();
	std::cout << "Successfully closed " << last_file_name;
}
