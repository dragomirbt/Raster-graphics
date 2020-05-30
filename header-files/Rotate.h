#ifndef ROTATE_HEADER_INCLUDED
#define ROTATE_HEADER_INCLUDED
#include "Files.h"

class Rotate : public File
{
public:
    void execute(Files& images, const char* direction);
};
#endif
