#ifndef SAVE_HEADER_INCLUDED
#define SAVE_HEADER_INCLUDED
#include "Files.h"

// класът съдържа командата "Save"

class Save : public File
{
public:
	// запазва направените промени върху картинките в масива във файловете
	bool execute(Files& images);
};
#endif
