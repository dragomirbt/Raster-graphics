#include "Files.h"

File& Files::operator[](int index)
{
	return array[index];
}
void Files::addFile(File file) 
{
	array.push_back(file);
}
File Files::getLastAddedFile() const
{
	int size = array.size();
	return array[size - 1];
}
int Files::getSize() const
{
	return array.size();
}
void Files::deleteLastFile()
{
	array.pop_back();
}
