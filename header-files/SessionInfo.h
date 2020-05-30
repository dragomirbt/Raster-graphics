#ifndef SESSION_INFO_HEADER_INCLUDED
#define SESSION_INFO_HEADER_INCLUDED
#include "Files.h"

//класът съдържа командата "SessionInfo"

class SessionInfo
{
public:
    //извежда информация за текущата сесия (имената на изображения са в сесията, индентификационният номер на сесията,
    //трансформациите, които предстоят да се извърщат
    void execute(Files& images, Transformations& transformations, int cur_ID);
};
#endif
