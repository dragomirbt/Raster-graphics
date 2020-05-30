#include "Negative.h"

void Negative::execute(Files& images)
{
	int index = 0;
	do
	{
		const char* extention = getExtention(images[index].getImageName());
		if (!(strcmp(extention, "pbm")) || !(strcmp(extention, "PBM")))
		{
			int height = images[index].getHeight();
			int width = images[index].getWidth();
			int** matrix = images[index].getMatrix();
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
					matrix[i][j] = 1 - matrix[i][j]; // 1 because its only 1 or 0
			}
			images[index].setMatrix(matrix);
			index++;
		}
		else
		{
			int max_value_for_color = images[index].getMaxValueForColor();
			int height = images[index].getHeight();
			int width = images[index].getWidth();
			int** matrix = images[index].getMatrix();
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
					matrix[i][j] = max_value_for_color - matrix[i][j];
			}
			images[index].setMatrix(matrix);
			index++;
		}
		if (index == images.getSize())
			break;
	} while (images[index].getID() == images[index-1].getID());
}
