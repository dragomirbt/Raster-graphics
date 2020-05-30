#ifndef FILE_HEADER_INCLUDED
#define FILE_HEADER_INCLUDED
#include "Transformations.h"
#include <fstream>
#include <vector>
#include <string>
using namespace std;
const int MAX_SIZE_FILE_FORMAT = 4;
const int MAX_IMAGE_NAME_SIZE = 15;

class File
{
private:
	char file_format[MAX_SIZE_FILE_FORMAT];
	unsigned width;
	unsigned height;
	unsigned max_value_for_color;
	int** matrix;
	int ID;
	char image_name[MAX_IMAGE_NAME_SIZE];
protected:
	virtual char* getExtention(const char* image_name) const;
public:
	File();
	File(const char* image_name);
	File(const File& other);
	File& operator=(const File& other);
	~File();
	
	void setFileFormat(const char* file_format);
	void setWidth(unsigned width);
	void setHeight(unsigned height);
	void setMaxValueForColor(unsigned max_value_for_color);
	void setMatrix(int** matrix);
	void setID(int ID);
	const char* getFileFormat() const;
	unsigned getWidth() const;
	unsigned getHeight() const;
	unsigned getMaxValueForColor() const;
	int** getMatrix() const;
	int getID() const;
	const char* getImageName() const;
	void setImageName(const char* image_name);	
};

#endif
