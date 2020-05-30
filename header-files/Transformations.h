#ifndef TRANSFORMATIONS_HEADER_INCLUDED
#define TRANSFORMATIONS_HEADER_INCLUDED
#include "Transformation.h"
#include <vector>
using namespace std;

// класът описва масив от трансформации
// член данни: масив от Transformation
class Transformations
{
private:
	vector<Transformation> transformations;
public:
	//добавя трансформация към масива
	void addTransformation(Transformation trans);
	// предифиниран оператор []
	Transformation& operator[](int index);
	// връша int текущият брой на трансформациите в масива
	int getSize() const;
	// изтрива трансформация в масива по подаден index
	void deleteTransformation(int index);
};
#endif
