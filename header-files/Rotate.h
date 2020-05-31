#ifndef ROTATE_HEADER_INCLUDED
#define ROTATE_HEADER_INCLUDED
#include "Files.h"

/// класът съдържа командата "Rotate"
class Rotate : public File
{
public:
    /// завърта всички картинки на 90 градуса в текущата сесия наляво или надясно
    /// @param images масив от картинки
    /// @param direction посока в която се завърта картинката 
    void execute(Files& images, const char* direction);
};
#endif
