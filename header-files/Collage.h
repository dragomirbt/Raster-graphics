#ifndef COLLAGE_HEADER_INCLUDED
#define COLLAGE_HEADER_INCLUDED
#include "Files.h"

//класът съдържа командата "Collage"

class Collage : public File
{
public:
	// създава хоризонтален или вертикален колаж от две картинки и го доабавя в масива от картинки
	// @param direction ориентацията на картинката (може да е хоризонтална или вертикална)
	// @param image1_name името на първата картинка
	// @param image2_name името на втората картинка
	// @param images масивът, от който са картинките
	void execute(const char* direction, const char* image1_name, const char* image2_name, Files& images);
};
#endif
