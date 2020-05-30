#ifndef SWTICH_HEADER_INCLUDED
#define SWITCH_HEADER_INCLUDED
#include "SessionInfo.h"
#include "Files.h"
class Switch : public SessionInfo
{
public:
	void execute(Files& images, Transformations& transformations, int ID);
};
#endif
