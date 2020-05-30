#include "Rotate.h"
#include<iostream>
#include <cstring>
void Rotate::execute(Files& images, const char* direction)
{
	int index = 0;
	do
	{
		if (!(strcmp(direction,"left")))
		{
			
			int** matrix = images[index].getMatrix();
			int height = images[index].getHeight();
			int width = images[index].getWidth();

			int** new_matrix;
			new_matrix = new int* [width];   //swapping the values becasue we r going to rotate the matrix
			for (int n = 0; n < width; n++)  // and width and height will be swaped
				new_matrix[n] = new int[height];

			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
					new_matrix[j][i] = matrix[i][width - (j + 1)];
			}
			images[index].setHeight(width);
			images[index].setWidth(height);
			images[index].setMatrix(new_matrix);
			index++;
		}
		else if (!(strcmp(direction,"right")))
		{

			int** matrix = images[index].getMatrix();
			int height = images[index].getHeight();
			int width = images[index].getWidth();

			int** new_matrix;
			new_matrix = new int* [width];   //swapping the values becasue we r going to rotate the matrix
			for (int n = 0; n < width; n++)  // and width and height will be swaped
				new_matrix[n] = new int[height];

			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
					new_matrix[j][i] = matrix[height - (i + 1)][j];
			}
			images[index].setHeight(width);
			images[index].setWidth(height);
			images[index].setMatrix(new_matrix);
			index++;
		}
		if (index == images.getSize())
			break;
	} while (images[index].getID() == images[index - 1].getID());
}
