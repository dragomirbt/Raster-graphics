#ifndef  NEGATIVE_HEADER_INCLUDED
#define  NEGATIVE_HEADER_INCLUDED
#include "Files.h"

/// класът съдържа командата "Negative"
class Negative : public File
{
public:
	/// прави негатив на всички картинки в текущата сесия
	/// @param images масив от картинки
	void execute(Files& images);
};
#endif 
