#ifndef FILE_HEADER_INCLUDED
#define FILE_HEADER_INCLUDED
#include "Transformations.h"
#include <fstream>
#include <vector>
#include <string>
using namespace std;
const int MAX_SIZE_FILE_FORMAT = 4;
const int MAX_IMAGE_NAME_SIZE = 15;

/// класът описва информацията която съдържа една картинка
///
/// член данни:
///	- формат на картинката
///	- ширина
///	- височина
///	- максимална стойност за цвят
///	- матрица
///	- индентификационен номер
///	- име на картинката

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
	/// взема разширението на дадена картинка по подадено име
	/// @param  image_name Името на картинката
	virtual char* getExtention(const char* image_name) const;
public:
	/// конструктор по подразбиране
	File();
	/// конструктор по подадено име на картинка
	File(const char* image_name);
	/// копи конструктор
	File(const File& other);
	/// предефиниран оператор за присвояване
	File& operator=(const File& other);
	/// деструктор
	~File();

	/// променя формата на картинката
	/// @param  file_format форматът на картинката
	void setFileFormat(const char* file_format);
	/// променя широчината на картинката
	/// @param  width широчината на картинката
	void setWidth(unsigned width);
	/// променя височината на картинката
	/// @param  height височината на картинката
	void setHeight(unsigned height);
	/// променя максималната стойност за цвят на картинката
	/// @param  max_value_for_color максималната стойност за цвят на картинката
	void setMaxValueForColor(unsigned max_value_for_color);
	/// променя сойностите в матрицата на картинката
	/// @param  matrix матрицата на картинката
	void setMatrix(int** matrix);
	/// променя индентификационния номер на картинката
	/// @param  ID индентификационният на картинката
	void setID(int ID);
	/// @returns const char* формат на картинката
	const char* getFileFormat() const;
	/// @returns unsigned широчина на картинката
	unsigned getWidth() const;
	/// @returns unsigned височина на картинката
	unsigned getHeight() const;
	/// @returns unsigned максимална стойност за цвят на картинката
	unsigned getMaxValueForColor() const;
	/// @returns int** матрица на картинката
	int** getMatrix() const;
	/// @returns int индентификационен номер на картинката
	int getID() const;
	/// @returns const char* име на картинката
	const char* getImageName() const;
	/// променя името на картинката
	/// @param image_name име на картинката
	void setImageName(const char* image_name);
};
#endif
