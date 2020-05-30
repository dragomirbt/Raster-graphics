#include "Collage.h"
#include <iostream>
void Collage::execute(const char* direction, const char* image1_name, const char* image2_name, Files& images)
{
	File image1;
	File image2;
	File outimage;
	int size = images.getSize();
	int count_steps = 0;
	for (int i = 0; i < size; i++)
	{
		if (!(strcmp(images[i].getImageName(), image1_name)))
		{
			image1 = images[i];
			count_steps++;
		}
		if (!(strcmp(images[i].getImageName(), image2_name)))
		{
			 image2 = images[i];
			count_steps++;
		}
		if (count_steps == 2)
			break;
	}
	char image_name[BUFF_SIZE];
	int cur_ID = images.getLastAddedFile().getID();
	if (image1.getID() == cur_ID && image2.getID() == cur_ID) // same session
	{
		char* extention1 = getExtention(image1_name);
		char* extention2 = getExtention(image2_name);
		if (!(strcmp(extention1, extention2))) // same format
		{
			int height1 = image1.getHeight();
			int width1 = image1.getWidth();
			int height2 = image2.getHeight();
			int width2 = image2.getWidth();
			if (height1 == height2 && width1 == width2) //same dimension
			{
				if (!(strcmp(direction, "horizontal")))
				{
					outimage.setHeight(height1);
					outimage.setWidth(width1 + width2);
					int outimage_height = outimage.getHeight();
					int outimage_width = outimage.getWidth();
					int** matrix1 = image1.getMatrix();
					int** matrix2 = image2.getMatrix();
					int** outimage_matrix = outimage.getMatrix();
					for (int i = 0; i < image1.getHeight(); i++)
					{
						for (int j = 0; j < image1.getWidth(); j++)
							outimage_matrix[i][j] = matrix1[i][j];
					}
					for (int k = 0; k < image2.getHeight(); k++)
					{
						for (int m = image1.getWidth(); m < outimage_width; m++)
							outimage_matrix[k][m] = matrix2[k][m];
					}
					strcpy(image_name, "collage.");
					strcat(image_name, extention1);
					outimage.setImageName(image_name);
					images.addFile(outimage);
					cout << "New collage " << '"' << image_name << '"' << " created.\n";
				}
				else if (!(strcmp(direction, "vertical")))
				{
					outimage.setHeight(height1 + height2);
					outimage.setWidth(width1);
					int outimage_height = outimage.getHeight();
					int outimage_width = outimage.getWidth();
					int** matrix1 = image1.getMatrix();
					int** matrix2 = image2.getMatrix();
					int** outimage_matrix = outimage.getMatrix();
					for (int i = 0; i < image1.getHeight(); i++)
					{
						for (int j = 0; j < image1.getWidth(); j++)
							outimage_matrix[i][j] = matrix1[i][j];
					}
					for (int k = image1.getHeight(); k < outimage_height; k++)
					{
						for (int m = image1.getWidth(); m < outimage_width; m++)
							outimage_matrix[k][m] = matrix2[k][m];
					}
					strcpy(image_name, "collage.");
					strcat(image_name, extention1);
					outimage.setImageName(image_name);
					images.addFile(outimage);
					cout << "New collage " << '"' << image_name << '"' << " created.\n";
				}
			}
			else
				std::cout << "Cannot make a collage with different dimensions!\n";
		}
		else
			std::cout << "Cannot make a collage from different types! " << '(' <<
			extention1 << " and " << extention2 << ')' << std::endl;

		
	}
	else
		std::cout << "Session error!\n";
}
