#ifndef TRANSFORMATIONS_HEADER_INCLUDED
#define TRANSFORMATIONS_HEADER_INCLUDED
#include "Transformation.h"
#include <vector>
using namespace std;
class Transformations
{
private:
	vector<Transformation> transformations;
public:
	void addTransformation(Transformation trans);
	Transformation& operator[](int index);
	int getSize() const;
	void deleteTransformation(int index);
};
#endif
