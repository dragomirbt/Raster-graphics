#ifndef SAVE_HEADER_INCLUDED
#define SAVE_HEADER_INCLUDED
#include "Files.h"

class Save : public File
{
public:
	bool execute(Files& images);
};
#endif
