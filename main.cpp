#include "Files.h"
#include "BasicCommands.h"
#include "Transformation.h"
#include "Transformations.h"
#include "Grayscale.h"
#include "Monochrome.h"
#include "Rotate.h"
#include "SessionInfo.h"
#include "Switch.h"
#include "Collage.h"
#include "Negative.h"
#include "Undo.h"
#include "Close.h"
#include "Save.h"
#include "SaveAs.h"
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

int chekNumberOfNames(char* images_names)
{
	int counter = 1;
	int i = 0;
	while (images_names[i] != '\0') 
	{
		if(images_names[i] == ' ')
		{
			counter++;
			i++;
		}
		i++;
	}
	return counter;
}
int letters = 0;
char image[BUFF_SIZE];
char* separateImages(char* image_name)
{
	int j = 0;
	while ((image_name[letters] != ' ') && (image_name[letters] != '\0'))
	{
		image[j] = image_name[letters];
		j++;
		letters++;
	}
	letters++;
	return image;
}

int main()
{
	const char* separated_image;
	int counter = 0;
	int ID = 0;
	unsigned count_number_of_images = 1;
	char command_name[BUFF_SIZE];
	char image_name[BUFF_SIZE];
	cin >> command_name;
	if ((!strcmp(command_name, "load")) || (!(strcmp(command_name, "add"))))
	{
		cin.ignore();
		cin.getline(image_name, BUFF_SIZE);
	}
	Files files_container;
	Transformations transformations;
	while (strcmp(command_name, "exit"))
	{

		if (!(strcmp(command_name, "load")))
		{
			ID++;
			letters = 0;
			counter = chekNumberOfNames(image_name);
			for (int i = 0; i < counter; i++)
			{
				separated_image = separateImages(image_name);
				if (i == 0)
					cout << "Session with ID: " << ID << " started\n";
				BasicCommands c;    
				if (c.load(separated_image))
				{
					File f(separated_image);
					f.setID(ID);
					files_container.addFile(f);
				}
			}
			cin >> command_name;
			if ((!strcmp(command_name, "load")) || (!(strcmp(command_name, "add"))))
			{
				cin.ignore();
				cin.getline(image_name, BUFF_SIZE);
			}
		}
		else if (!(strcmp(command_name, "close")))
		{
			Close c;
			c.execute(files_container);
		}
		else if (!(strcmp(command_name, "save")))
		{
			Save c;                                     
			c.execute(files_container);
			cin >> command_name;
			if ((!strcmp(command_name, "load")) || (!(strcmp(command_name, "add"))))
			{
				cin.ignore();
				cin.getline(image_name, BUFF_SIZE);
			}
		}
		else if (!(strcmp(command_name, "saveas")))
		{
			SaveAs c;
			int size = files_container.getSize();
			char image_path[BUFF_SIZE];
			for (int i = 0; i < size; i++)
			{
				const char* image_name = files_container[i].getImageName();
				cout << "Enter the path you would like to save the following image: " << image_name << endl <<
					"(make sure when u enter the last slash you type the name of the image with its extention)" << endl;
				cin.ignore();
				cin.getline(image_path, BUFF_SIZE);
				c.execute(files_container, image_path);
			}
			cin >> command_name;
			if ((!strcmp(command_name, "load")) || (!(strcmp(command_name, "add"))))
			{
				cin.ignore();
				cin.getline(image_name, BUFF_SIZE);
			}
		}
		else if (!(strcmp(command_name, "help")))
		{
			BasicCommands c;
			c.help();
			cin >> command_name;
			if ((!strcmp(command_name, "load")) || (!(strcmp(command_name, "add"))))
			{
				cin.ignore();
				cin.getline(image_name, BUFF_SIZE);
			}
		}
		else if (!(strcmp(command_name, "grayscale")))
		{
			Grayscale c;
			c.execute(files_container);
			Transformation transformation(files_container.getLastAddedFile().getID(),"grayscale");
			transformations.addTransformation(transformation);
			cin >> command_name;
			if ((!strcmp(command_name, "load")) || (!(strcmp(command_name, "add"))))
			{
				cin.ignore();
				cin.getline(image_name, BUFF_SIZE);
			}
		}
		else if (!(strcmp(command_name, "monochrome")))
		{
			 Monochrome c;
			 c.execute(files_container);
			 Transformation transformation(files_container.getLastAddedFile().getID(), "monochrome");
			 transformations.addTransformation(transformation);
			 cin >> command_name;
			if ((!strcmp(command_name, "load")) || (!(strcmp(command_name, "add"))))
			{
				cin.ignore();
				cin.getline(image_name, BUFF_SIZE);
			}
		}
		else if (!(strcmp(command_name, "negative")))
		{
			Negative c;
			c.execute(files_container);
			Transformation transformation(files_container.getLastAddedFile().getID(), "negative");
			transformations.addTransformation(transformation);
			cin >> command_name;
			if ((!strcmp(command_name, "load")) || (!(strcmp(command_name, "add"))))
			{
				cin.ignore();
				cin.getline(image_name, BUFF_SIZE);
			}
		}
		else if (!(strcmp(command_name, "rotate")))
		{
			char direction[BUFF_SIZE];
			cin >> direction;
			char transf[BUFF_SIZE];
			strcpy(transf, "rotate ");
			strcat(transf, direction);
			Rotate c;
			c.execute(files_container, direction);
			Transformation transformation(files_container.getLastAddedFile().getID(), transf);
			transformations.addTransformation(transformation);
			cin >> command_name;
			if ((!strcmp(command_name, "load")) || (!(strcmp(command_name, "add"))))
			{
				cin.ignore();
				cin.getline(image_name, BUFF_SIZE);
			}
		}
		else if (!(strcmp(command_name, "undo")))
		{
			Undo c;
			c.execute(transformations, files_container);
			cin >> command_name;
			if ((!strcmp(command_name, "load")) || (!(strcmp(command_name, "add"))))
			{
				cin.ignore();
				cin.getline(image_name, BUFF_SIZE);
			}
		}
		else if (!(strcmp(command_name, "add")))
		{
			letters = 0;
			separated_image = separateImages(image_name); //taking only the first image
			BasicCommands c;
			c.add(separated_image);
			File f(separated_image);
			f.setID(ID);
			files_container.addFile(f);
			cin >> command_name;
			if ((!strcmp(command_name, "load")) || (!(strcmp(command_name, "add"))))
			{
				cin.ignore();
				cin.getline(image_name, BUFF_SIZE);
			}
		}
		else if (!(strcmp(command_name, "session")))
		{
			SessionInfo c;
			c.execute(files_container, transformations, files_container.getLastAddedFile().getID());
			cin >> command_name;
			if ((!strcmp(command_name, "load")) || (!(strcmp(command_name, "add"))))
			{
				cin.ignore();
				cin.getline(image_name, BUFF_SIZE);
			}
		}
		else if (!(strcmp(command_name, "switch")))
		{
			 Switch c;
			 int switch_ID;
			 cin >> switch_ID;
			 c.execute(files_container, transformations, switch_ID);
			cin >> command_name;
			if ((!strcmp(command_name, "load")) || (!(strcmp(command_name, "add"))))
			{
				cin.ignore();
				cin.getline(image_name, BUFF_SIZE);
			}
		}
		else if (!(strcmp(command_name, "collage")))
		{
			char direction[BUFF_SIZE];
			cin >> direction;
			char image1[BUFF_SIZE];
			cin >> image1;
			char image2[BUFF_SIZE];
			cin >> image2;
			Collage c;
			c.execute(direction, image1, image2, files_container);
			char full_trans_name[BUFF_SIZE];
			strcpy(full_trans_name, "collage ");
			strcat(full_trans_name, direction);
			Transformation transformation(files_container.getLastAddedFile().getID(), full_trans_name);
			transformations.addTransformation(transformation);
			cin >> command_name;
			if ((!strcmp(command_name, "load")) || (!(strcmp(command_name, "add"))))
			{
				cin.ignore();
				cin.getline(image_name, BUFF_SIZE);
			}
		}
	}
	BasicCommands c;
	c.exit();
	return 0;
}
