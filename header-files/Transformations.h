#ifndef TRANSFORMATIONS_HEADER_INCLUDED
#define TRANSFORMATIONS_HEADER_INCLUDED
#include "Transformation.h"
#include <vector>
using namespace std;

/// класът описва масив от трансформации
///
/// член данни: масив от Transformation
class Transformations
{
private:
	vector<Transformation> transformations;
public:
	/// добавя трансформация към масива
	/// @param trans трансформация (обект от тип Transformation) 
	void addTransformation(Transformation trans);
	/// предифиниран оператор []
	Transformation& operator[](int index);
	/// @returns int текущият брой на трансформациите в масива
	int getSize() const;
	/// изтрива трансформация в масива по подаден index
	/// @param index индекс в масива
	void deleteTransformation(int index);
};
#endif
