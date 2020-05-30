#ifndef MONOCHROME_HEADER_INCLUDED
#define MONOCHROME_HEADER_INCLUDED
#include "Files.h"

class Monochrome : public File
{
public:
    void execute(Files& images);
};
#endif
