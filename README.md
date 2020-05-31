# Документация за проект Растерна графика
github: https://github.com/dragosa4a/Raster-graphics

## Увод 
Програма ,която редактира растерни изображения. Прилагат се различни команди, с които изображенията биват променяни. Програмата обработва и съхранява данните във файлове.

## Имплементация
Проектът е реализиран чрез съвкупност от класове, които имплементират различните командти. Съществува и клас, който представя самото растерно изображение, както и такъв който представя трансформацията, която ще се извърши.

Класът, който описва едно растерно изображение е File.

Обектите от тип File съдръжат следните член - данни:
  
* char file_format[MAX_SIZE_FILE_FORMAT] - формат
* unsigned width - ширина
* unsigned height - височина
* unsigned max_value_for_color - максимална стойност за цвят
* int** matrix - матрица
* int ID - индетификационен номер
* char image_name[MAX_IMAGE_NAME_SIZE] - име    

Всички растерни изображение се съдържат в обект от тип Files.

Класът който описва една трансформация е Transformation.

Обектите от тип Transformation съдържат следните член-данни:

* int ID - индетификационен номер
* char transformation_name[BUFF_SIZE] - име 

Всички трансформации се съдържат в обект от тип Transformations.

Класът, който описва някои от основните команди(help, exit и load), както и командата подобна на load - add е BasicCommands.

Всяка една от тези команди се описва чрез:

* char name[MAX_COMMAND_LENGHT] - име 

Останалите команди се описват със съответните класове:

Команда - Клас
* close - Close 
* collage - Collage
* grayscale - Grayscale
* monochrome - Monochrome
* negative - Negative
* rotate - Rotate
* save - Save
* saveas - SaveAs
* session info - SessionInfo
* undo - Undo
