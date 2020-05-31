#ifndef SWTICH_HEADER_INCLUDED
#define SWITCH_HEADER_INCLUDED
#include "SessionInfo.h"
#include "Files.h"

//класът съдържа командата "Switch"

class Switch : public SessionInfo
{
public:
	// превключва към друга сесия, според подаден индентификационен номер
   	// @param images масив от картинки
    	// @param transformations масив от трансформации
    	// @param ID индентификационен номер	
	void execute(Files& images, Transformations& transformations, int ID);
};
#endif
