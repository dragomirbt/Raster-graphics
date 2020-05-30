#ifndef GRAYSCALE_HEADER_INCLUDED
#define GRAYSCALE_HEADER_INCLUDED
#include "Files.h"
class Grayscale : public File
{
public:
	void execute(Files& images);
};
#endif
