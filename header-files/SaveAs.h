#ifndef SAVEAS_HEADER_INCLUDED
#define SAVEAS_HEADER_INCLUDED
#include "Files.h"

class SaveAs : public File
{
public:
	bool execute(Files& images, const char* image_path);
};
#endif
