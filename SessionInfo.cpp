#include "SessionInfo.h"
#include <iostream>
void SessionInfo::execute(Files& images, Transformations& transformations, int cur_ID)
{
	int index = 0;
	int size = transformations.getSize();
	for (int index = 0; index < size; index++)
	{
		if (transformations[index].getID() == cur_ID)
		{
			std::cout << "Current session ID: " << cur_ID << std::endl;
			std::cout << "Name of images in the session: ";
			int im_index = 0;
			while (images[im_index].getID() == cur_ID)
			{
				std::cout << images[im_index].getImageName() << " ";
				im_index++;
				if (im_index == images.getSize())
					break;
			}
			std::cout << std::endl;
			std::cout << "Pending transformations: ";

			for (int i = 0; i < size; i++)
			{
				if(transformations[i].getID() == cur_ID)
					std::cout << transformations[i].getTransformationName() << " ";
			}
			break;
		}
	}
}
