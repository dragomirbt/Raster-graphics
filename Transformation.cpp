#include "Transformation.h"
#include <cstring>

Transformation::Transformation(int ID, const char* transformation_name)
{
	this->ID = ID;
	strcpy(this->transformation_name, transformation_name);
}
int Transformation::getID() const
{
	return ID;
}
const char* Transformation::getTransformationName() const
{
	return transformation_name;
}
void Transformation::setID(int ID)
{
	this->ID = ID;
}
void Transformation::setTransformationName(const char* transformation_name)
{
	strcpy(this->transformation_name, transformation_name);
}
