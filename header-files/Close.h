#ifndef CLOSE_HEADER_INCLUDED
#define CLOSE_HEADER_INCLUDED
#include "Files.h"

/// класът съдържа командата "Close"
class Close
{
public:
	/// изтрива последно добавеният файл в масива от файлове
	/// @param images Масив от картинки
	void execute(Files& images);
};
#endif
