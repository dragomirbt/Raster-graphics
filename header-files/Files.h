#ifndef FILES_HEADER_INCLUDED
#define FILES_HEADER_INCLUDED
#include <vector>
#include "File.h"

class Files
{
private:
	std::vector<File> array;
public:
	File& operator[](int index);
	void addFile(File file);
	File getLastAddedFile() const;
	int getSize() const;
	void deleteLastFile();
};

#endif
