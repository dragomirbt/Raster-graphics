#ifndef COLLAGE_HEADER_INCLUDED
#define COLLAGE_HEADER_INCLUDED
#include "Files.h"
class Collage : public File
{
public:
	void execute(const char* direction, const char* image1, const char* image2, Files& image);
};
#endif
