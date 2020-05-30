#include "SaveAs.h"
#include <iostream>
#include <fstream>
using namespace std;

bool SaveAs::execute(Files& images, const char* image_path)
{
    int i = 0;
	const char* file_format = images[i].getFileFormat();
	int height = images[i].getHeight();
	int width = images[i].getWidth();
	int** matrix = images[i].getMatrix();
	int max_value_for_color = images[i].getMaxValueForColor();
	const char* image_name = images[i].getImageName();
	const char* extention = getExtention(image_name);
	ofstream file(image_path, ios::out);
	if (!file)
	{
		cout << "Cannot open file!\n";
		return -1;
	}
	if (strcmp(file_format, "P1") && (strcmp(file_format, "P2")) && (strcmp(file_format, "P3"))) // if binary
	{
		file.close();
		file.open(image_path, ios::out | ios::binary);
		if (!file)
		{
			cout << "Cannot open file!\n";
			return -1;
		}
		if (!(strcmp(extention, "PBM")) && (!(strcmp(extention, "pbm"))))
		{
			file.write((const char*)&file_format, sizeof(file_format)); file << endl;
			file.write((const char*)&width, sizeof(width)); file << ' ';
			file.write((const char*)&height, sizeof(height)); file << endl;
			for (int r = 0; r < height; r++)
			{
				for (int c = 0; c < width; c++)
					file.write((const char*)&matrix[r][c], sizeof(int)); file << ' ';
				file << endl;
			}
			file.close();
		}
		else //if not pbm adding max size for color
		{
			file.write((const char*)&file_format, sizeof(file_format)); file << endl;
			file.write((const char*)&width, sizeof(width)); file << ' ';
			file.write((const char*)&height, sizeof(height)); file << endl;
			file.write((const char*)&max_value_for_color, sizeof(max_value_for_color)); file << endl;
			for (int r = 0; r < height; r++)
			{
				for (int c = 0; c < width; c++)
					file.write((const char*)&matrix[r][c], sizeof(int)); file << ' ';
					file << endl;
			}
			file.close();
		}
	}
	else //if ASCII
  	{
		if (!(strcmp(extention, "PBM")) && (!(strcmp(extention, "pbm"))))
		{
			file << file_format << endl << width << ' ' << height << endl;
			for (int r = 0; r < height; r++)
			{
				for (int c = 0; c < width; c++)
					file << matrix[r][c] << ' ';
				file << endl;
			}
			file.close();
		}
		else //adding max value for color
		{
			file << file_format << endl << width << ' ' << height << endl << max_value_for_color << endl;
			for (int r = 0; r < height; r++)
			{
				for (int c = 0; c < width; c++)
				file << matrix[r][c] << ' ';
				file << endl;
			}
			file.close();
		}
	}
	i++;
	return 1;
}
