#ifndef FILES_HEADER_INCLUDED
#define FILES_HEADER_INCLUDED
#include <vector>
#include "File.h"
 
// класът описва масив от картинки (File)
//член данни: Масив от File
class Files
{
private:
	std::vector<File> array;
public:
	// предифиниран оператор []
	File& operator[](int index);
	// функция, която добавя картинка в масива
	void addFile(File file);
	//функция, която връща File последната добавена картинка в масива
	File getLastAddedFile() const;
	// функция, която връща броят на картинките в масива
	int getSize() const;
	// функция, която изтрива последната картинка от масива
	void deleteLastFile();
};
#endif
