#ifndef TRANSFORMATION_HEADER_INCLUDED
#define TRANSFORMATION_HEADER_INCLUDED

const int BUFF_SIZE = 64;
class Transformation
{
private:
	int ID;
	char transformation_name[BUFF_SIZE];
public:
	Transformation(int ID, const char* transformation_name);
	void setID(int ID);
	void setTransformationName(const char* transformation_name);
	int getID() const;
	const char* getTransformationName() const;
};
#endif
