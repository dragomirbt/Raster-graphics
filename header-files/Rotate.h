#ifndef ROTATE_HEADER_INCLUDED
#define ROTATE_HEADER_INCLUDED
#include "Files.h"

//класът съдържа командата "Rotate"

class Rotate : public File
{
public:
   // завърта картинка на 90 градуса наляво или надясно
    void execute(Files& images, const char* direction);
};
#endif
