#include "File.h"
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_EXTENTION_SIZE = 4;
File::File()
{
	strcpy(file_format, "");
	width = 35;
	height = 35;
	max_value_for_color = 0;
	matrix = new int* [height];
	for (int i = 0; i < height; i++)
		matrix[i] = new int[width];
	ID = 0;
	strcpy(image_name, "");
}
File::File(const char* image_name)

{
	strcpy(this->image_name, image_name);
	ID = 0;
	ifstream file(image_name);
	char file_format[MAX_SIZE_FILE_FORMAT];
	unsigned width, height, max_value_for_color;
	file >> file_format >> width >> height;
	const char* extention = getExtention(image_name); 
	if (strcmp(file_format,"P1") && (strcmp(file_format, "P2")) && (strcmp(file_format, "P3"))) // if binary
	{
		file.close();
		file.open(image_name, ios::in | ios::binary);
		strcpy(this->file_format, file_format);
		this->width = width;	
		this->height = height;
		if (strcmp(extention, "PBM") && strcmp(extention, "pbm"))
		{
			file.read((char*)&max_value_for_color, sizeof(unsigned));
			this->max_value_for_color = max_value_for_color;
		}
		else
			this->max_value_for_color = 0;
		if (!(strcmp(extention, "PPM")) || !(strcmp(extention, "ppm")))
		{
			this->height = height * 3;
			matrix = new int* [this->height];
			for (int i = 0; i < this->height; i++)
				matrix[i] = new int[this->width];

			for (int i = 0; i < this->height; i++)	
			{
				for (int j = 0; j < this->width; j++)
					file.read((char*)matrix[i][j], sizeof(unsigned));
			}
			file.close();
		}

		matrix = new int* [height];
		for (int i = 0; i < height; i++)
			matrix[i] = new int[width];

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				file.read((char*)matrix[i][j], sizeof(unsigned));
		}
		file.close();
    }
	else //if ASCII
	{
		strcpy(this->file_format, file_format);
		this->width = width;
		this->height = height;
		if (strcmp(extention, "PBM") && strcmp(extention, "pbm"))
		{
			file >> max_value_for_color;
			this->max_value_for_color = max_value_for_color;
		}
		else
			this->max_value_for_color = 0;

			if (!(strcmp(extention, "PPM")) || !(strcmp(extention, "ppm")))
			{
				this->height = height * 3;
				matrix = new int* [this->height];
				for (int i = 0; i < this->height; i++)
					matrix[i] = new int[this->width];
				for (int i = 0; i < this->height; i++)
				{
					for (int j = 0; j < this->width; j++)
						file >> matrix[i][j];
				}
				file.close();
			}
			else
			{
				matrix = new int* [height];
				for (int i = 0; i < height; i++)
					matrix[i] = new int[width];

				for (int i = 0; i < height; i++)
				{
					for (int j = 0; j < width; j++)
						file >> matrix[i][j];
				}
				file.close();
			}
	}
	delete[] extention;
	extention = nullptr;
}
File::File(const File& other)
{
	strcpy(this->image_name, other.image_name);
	strcpy(file_format, other.file_format);
	width = other.width;
	height = other.height;
	matrix = new int* [height];
	for (int f = 0; f < height; f++)
		matrix[f] = new int[width];
	max_value_for_color = other.max_value_for_color;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			matrix[i][j] = other.matrix[i][j];
	}
	ID = other.ID;
}
File& File:: operator=(const File& other)
{
	if (this != &other)
	{
		strcpy(this->image_name, other.image_name);
		strcpy(file_format,other.file_format);
		width = other.width;
		height = other.height;
		max_value_for_color = other.max_value_for_color;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				this->matrix[i][j] = other.matrix[i][j];
		}
		ID = other.ID;
	}
	return *this;
}
File::~File()
{
	for (int i = 0; i < height; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = nullptr;
}

char* File::getExtention(const char* image_name) const
{
	char* extention = new char[MAX_EXTENTION_SIZE];
	int extention_size = MAX_EXTENTION_SIZE;
	int i = strlen(image_name);
	while (image_name[i] != '.')
	{
		extention[extention_size-1] = image_name[i];
		i--;
		extention_size--;
	}
	return extention;
}
void File::setFileFormat(const char* file_format)
{
	strcpy(this->file_format, file_format);
}
void File::setWidth(unsigned width)
{
	this->width = width;
}
void File::setHeight(unsigned height)
{
	this->height = height;
}
void File::setMaxValueForColor(unsigned max_value_for_color)
{
	this->max_value_for_color = max_value_for_color;
}
void File::setMatrix(int** matrix) 
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			this->matrix[i][j] = matrix[i][j];
	}
}
void File::setID(int ID)
{
	this->ID = ID;
}
const char* File::getFileFormat() const
{
	return file_format;
}
unsigned File::getWidth() const
{
	return width;
}
unsigned File::getHeight() const
{
	return height;
}
unsigned File::getMaxValueForColor() const
{
	return max_value_for_color;
}
int** File::getMatrix() const
{
	return matrix;
}
int File::getID() const
{
	return ID;
}
const char* File::getImageName() const
{
	return image_name;
}
void File::setImageName(const char* image_name)
{
	strcpy(this->image_name,image_name);
}
