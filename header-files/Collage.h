#ifndef COLLAGE_HEADER_INCLUDED
#define COLLAGE_HEADER_INCLUDED
#include "Files.h"

//класът съдържа командата "Collage"

class Collage : public File
{
public:
	// създава хоризонтален или вертикален колаж от две картинки и го доабавя в масива от картинки
	void execute(const char* direction, const char* image1, const char* image2, Files& image);
};
#endif
