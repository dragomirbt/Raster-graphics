#ifndef UNDO_HEADER_INCLUDED
#define UNDO_HEADER_INCLUDED
#include "Files.h"
#include "Grayscale.h"
#include "Monochrome.h"
#include "Negative.h"
#include "Rotate.h"

//класът съдържа командата "Undo"

class Undo
{
public:
	// връща всички картинки в текущата сесия в масива към предишният им вид
	// @param transformations масив от трансформации
	// @param images масив от картинки
	void execute(Transformations& transformations, Files& images);
};
#endif
