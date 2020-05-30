#ifndef GRAYSCALE_HEADER_INCLUDED
#define GRAYSCALE_HEADER_INCLUDED
#include "Files.h"

//класът съдържа командата "Grayscale"

class Grayscale : public File
{
public:
       // прави всички картинки в текущата сесия с нюанси на сивото
	void execute(Files& images);
};
#endif
