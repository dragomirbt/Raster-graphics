#ifndef TRANSFORMATION_HEADER_INCLUDED
#define TRANSFORMATION_HEADER_INCLUDED

const int BUFF_SIZE = 64;

//класът описва информацията, която съдържа една трансформация
/* член данни:
	- индентификационен номер
	- име на трансформацията
*/
class Transformation
{
private:
	int ID;
	char transformation_name[BUFF_SIZE];
public:
	// конструктор по подаден индентификационен номер и име на трансформацията
	Transformation(int ID, const char* transformation_name);
	// променя индентификационния номер 
	// @param ID индентификационен номер
	void setID(int ID);
	// порменя името на трансформацията
	// @param transformation_name име на трансформацията
	void setTransformationName(const char* transformation_name);
	// @returns int индентификационния номер 
	int getID() const;
	// @returns const char* името на трансформацията
	const char* getTransformationName() const;
};
#endif
