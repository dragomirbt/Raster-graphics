#include "Switch.h"
#include<iostream>
void Switch::execute(Files& images, Transformations& transformations, int ID)
{
	int biggest_session_ID = images.getLastAddedFile().getID();
	if (biggest_session_ID < ID)
		cout << "There is no such a session with this ID\n";
	else
	{
		std::cout << "You switched to session with ID: " << ID << "!\n";
		SessionInfo::execute(images, transformations, ID);
	}
}
