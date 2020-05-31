#ifndef SESSION_INFO_HEADER_INCLUDED
#define SESSION_INFO_HEADER_INCLUDED
#include "Files.h"

//класът съдържа командата "SessionInfo"

class SessionInfo
{
public:
    //извежда информация за текущата сесия (имената на изображения са в сесията, индентификационният номер на сесията,
    //трансформациите, които предстоят да се извърщат
    // @param images масив от картинки
    // @param transformations масив от трансформации
    // @param cur_ID индентификационният номер на текущата сесия    
    void execute(Files& images, Transformations& transformations, int cur_ID);
};
#endif
