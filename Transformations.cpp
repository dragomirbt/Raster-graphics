#include "Transformations.h"

void Transformations::addTransformation(Transformation trans)
{
	transformations.push_back(trans);
}
Transformation& Transformations::operator[](int index)
{
	return transformations[index];
}
int Transformations::getSize() const
{
	return transformations.size();
}
void Transformations::deleteTransformation(int index)
{
	transformations.erase(transformations.begin() + index);
}
