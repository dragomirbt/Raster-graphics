#ifndef SAVEAS_HEADER_INCLUDED
#define SAVEAS_HEADER_INCLUDED
#include "Files.h"

//класът съдържа командата "Saveas"

class SaveAs : public File
{
public:
	// запазва досега напрвените промени върху картинките в текущата сесия във файлове в нова директория
	bool execute(Files& images, const char* image_path);
};
#endif
