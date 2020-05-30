#ifndef UNDO_HEADER_INCLUDED
#define UNDO_HEADER_INCLUDED
#include "Files.h"
#include "Grayscale.h"
#include "Monochrome.h"
#include "Negative.h"
#include "Rotate.h"

class Undo
{
public:
	void execute(Transformations& transformations, Files& images);
};
#endif
