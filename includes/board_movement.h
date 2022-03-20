#ifndef BOARD_MOVEMENT_H
#define BOARD_MOVEMENT_H

typedef enum e_dir // un enum pour qui permet de stocker une direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
}			enum_dir;

// une struct vector qui peut permettre de stocker des positions
//mais qui sera aussi utiliséé pour stocker les incréments qui seront utilisé pour le mouvement
typedef struct s_vector 
{
	int x; // X =COLUMN
	int y; // Y = LINES
}				t_vector;

#include "libft.h"
#include "board.h"
#include <stdbool.h>
#include "vector_conversions.h"



//fonction qui prends la position d'un carré et sa direction et qui va checker
//si ce carré peut merge avec l'obstacle adjacent dans sa direction
//si possible elle va merge les deux
void try_merge(t_vector position, t_vector direction, t_board *board);
/***********************************************************************/
/*																	   */
/*					BOARD AND TILE MOVEMENT							   */
/*																	   */
/***********************************************************************/

void move_tile_vertical(t_vector position, t_vector vector_dir, t_board *board);
void move_board_vertical(int direction, t_board *board);
void move_tile_horizontal(t_vector position, t_vector vector_dir, t_board *board);
void move_board_horizontal(int direction, t_board *board);

//fonction à appeler pour initer un move dans une direction
void board_move(int direction, t_board *board);
#endif