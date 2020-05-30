#include "Undo.h"

void Undo::execute(Transformations& transformations, Files& images)
{
	int cur_ID = images.getLastAddedFile().getID();
	int t_size = transformations.getSize();
	int i;
	for (i = t_size - 1; i >= 0; i--)
	{
		if (transformations[i].getID() == cur_ID)
		{
			transformations.deleteTransformation(i);
			break;
		}
	}
	if (!(strcmp(transformations[i - 1].getTransformationName(), "grayscale")))
	{
		Grayscale c;
		c.execute(images);
	}
	else if (!(strcmp(transformations[i - 1].getTransformationName(), "monochrome")))
	{
		Monochrome c;
		c.execute(images);
	}
	else if (!(strcmp(transformations[i - 1].getTransformationName(), "negative")))
	{
		Negative c;
		c.execute(images);
	}
	else if (!(strcmp(transformations[i - 1].getTransformationName(), "rotate right")))
	{
		Rotate c;
		c.execute(images, "right");
	}
	else if (!(strcmp(transformations[i - 1].getTransformationName(), "rotate left")))
	{
		Rotate c;
		c.execute(images, "left");
	}
}
