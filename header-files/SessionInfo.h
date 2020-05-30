#ifndef SESSION_INFO_HEADER_INCLUDED
#define SESSION_INFO_HEADER_INCLUDED
#include "Files.h"

class SessionInfo
{
public:
    void execute(Files& images, Transformations& transformations, int cur_ID);
};
#endif
