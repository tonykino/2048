
#include "vector_conversions.h"


//POSTIT	X = COLUMNS
// 			Y = LINES

//fonction qui prends un enum en entrée et donne un vector contenant les incréments à appliquer à des coordonnés
//pour parcourir le tableau
t_vector enum_to_vector(enum_dir direction)
{
	t_vector ret;
	switch(direction)
	{
		case UP:
		{
			ret.x = 0;
			ret.y = -1; //decrementer Y fait aller vers le haut dans un tableau
			break;
		}
		case DOWN:
		{
			ret.x = 0;
			ret.y = 1; // incrementer Y fait aller vers le bas dansun tableau
			break;
		}
		case LEFT:
		{
			ret.x = -1; // decrementer x fait aller vers la gauche dans un tableau
			ret.y = 0;
			break;
		}
		case RIGHT:
		{
			ret.x = 1; // incrémenter x fait aller vers la droite dans un tableau
			ret.y = 0;
			break;
		}
	}
	return ret;
}

//fonction qui donne les coordonnées de départ du check en fonction de la direction
t_vector get_start(enum_dir direction, t_board * board)
{
	t_vector ret;
	switch (direction)
	{
		case UP:
		{
			ret.x = 0;
			ret.y = 0;
			break;
		}
		case DOWN:
		{
			ret.x = 0;
			ret.y = board->line_nb - 1;
			break;
		}
		case LEFT:
		{
			ret.x = 0;
			ret.y = 0;
			break;
		}
		case RIGHT:
		{
			ret.x = board->col_nb - 1;
			ret.y = 0;
			break;
		}
	}
	return ret;
}
