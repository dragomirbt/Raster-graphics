#ifndef MONOCHROME_HEADER_INCLUDED
#define MONOCHROME_HEADER_INCLUDED
#include "Files.h"

// класът съдържа командата "Monochrome"

class Monochrome : public File
{
public:
    // всички картинки в текущата сесия стават черно-бели
    void execute(Files& images);
};
#endif
