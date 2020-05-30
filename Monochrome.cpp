#include "Monochrome.h"

void Monochrome::execute(Files& images)
{
	int index = 0;
	do
	{
		const char* extention = getExtention(images[index].getImageName());
		if (!(strcmp(extention, "ppm")) || !(strcmp(extention, "PPM")) || !(strcmp(extention, "pgm")) || !(strcmp(extention, "PGM")))
		{
			int** matrix = images[index].getMatrix();
			int height = images[index].getHeight();
			int width = images[index].getHeight();
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (matrix[i][j] != 0)
					{
						if (j % 2 != 0)
							matrix[i][j] = 1;
						else
							matrix[i][j] = 0;
						
					}
				}
			}
			images[index].setMatrix(matrix);
			index++;
		}
	} while (images[index].getID() == images[index - 1].getID());
}
