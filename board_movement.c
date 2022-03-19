#include "board_movement.h"
#include <ncurses.h> //temporaire

//POSTIT	X = COLUMNS
// 			Y = LINES

//fonction qui prends la position d'un carré et sa direction et qui va checker
//si ce carré peut merge avec l'obstacle adjacent dans sa direction
//si possible elle va merge les deux
void try_merge(t_vector position, t_vector direction, t_board *board)
{

	//premiers checks pour voir si on est pas contre un côté
	if (position.x + direction.x < 0 || position.x + direction.x >= board->col_nb)
		return;
	if (position.y + direction.y < 0 || position.y + direction.y >= board->line_nb)
		return;

	t_tile *actual_tile		= &board->tiles[position.y][position.x];
	t_tile *tile_to_check	= &board->tiles[position.y + direction.y][position.x + direction.x];
	if (!tile_to_check->is_merged && actual_tile->value == tile_to_check->value)
	{
		tile_to_check->value *= 2;
		board->score += tile_to_check->value; // augmenter le score en ajoutant la valeur de la tile créé
		tile_to_check->is_merged = true;
		actual_tile->value = 0;

		board->has_changed = true;
	}
}

/***********************************************************************/
/*																	   */
/*					BOARD AND TILE MOVEMENT							   */
/*																	   */
/***********************************************************************/
//ça m'embete de répeter du code mais ça permet de ne pas faire une boucle 
//avec des conditions de 3km incompréhensibles pour pouvoir partir de n'importe où/aller dans tout les sens

//les couple de fonctions move_***_horizontal/vertical vont iterer sur toute la board ligne par ligne ou colonne par colonne
//et en partant toujours du bord d'arrivée puis
//decaler chacun des carrés et essayer de les merge

void move_tile_vertical(t_vector position, t_vector vector_dir, t_board *board)
{
	t_tile *actual_tile = NULL;
	t_tile *next_tile = NULL;
	//tant qu'on est pas à un bord et qu'on a pas de carré à coté on décale le carré
	while (position.y >= 0 && position.y < board->line_nb
	&& position.y + vector_dir.y >= 0 && position.y +vector_dir.y < board->line_nb
	&& board->tiles[position.y + vector_dir.y][position.x].value == 0)
	{
		actual_tile = &board->tiles[position.y][position.x];
		next_tile = &board->tiles[position.y + vector_dir.y][position.x];
		
		next_tile->value = actual_tile->value;
		actual_tile->value = 0;
		position.y += vector_dir.y;

		board->has_changed = true;
	}
	try_merge(position, vector_dir, board);
}

void move_board_vertical(enum_dir direction, t_board *board)
{
	t_vector position = get_start(direction, board);
	t_vector vector_dir = enum_to_vector(direction);


	int y_start = position.y;
	//une boucle qui va tourner pour chaque ligne et pour chaque carré, qui part du côté d'arrivée
	//et qui décale chaque carré qu'elle trouve jusque à ce qu'il arrive à un obstacle
	//arrivé à une obstacle on try de merge
	while (position.x < board->col_nb) // on boucle colonne par colonne en allant de gauche à droite
	{
		position.y = y_start;
		while (position.y >= 0 && position.y < board->line_nb) //et là on monte ou descend dans chacune des colonnes 
		{
			if (board->tiles[position.y][position.x].value != 0)
				move_tile_vertical(position, vector_dir, board);
			position.y -= vector_dir.y; // on part du bord opposé donc on doit aller dans la direction inverse
		}
		position.x++;
	}
}

void move_tile_horizontal(t_vector position, t_vector vector_dir, t_board *board)
{
	t_tile *actual_tile = NULL;
	t_tile *next_tile = NULL;
	//tant qu'on est pas à un bord et qu'on a pas de carré à coté on décale le carré
	while (position.x >= 0 && position.x < board->col_nb
	&& position.x + vector_dir.x >= 0 && position.x + vector_dir.x < board->col_nb
	&& board->tiles[position.y][position.x + vector_dir.x].value == 0)
	{
		actual_tile = &board->tiles[position.y][position.x];
		next_tile = &board->tiles[position.y][position.x + vector_dir.x];
		
		next_tile->value = actual_tile->value;
		actual_tile->value = 0;
		position.x += vector_dir.x;

		board->has_changed = true;
	}
	try_merge(position, vector_dir, board);
}

void move_board_horizontal(enum_dir direction, t_board *board)
{
	t_vector position = get_start(direction, board);
	t_vector vector_dir = enum_to_vector(direction);

	int x_start = position.x;
	//une boucle qui va tourner pour chaque ligne et pour chaque carré, qui part du côté d'arrivée
	//et qui décale chaque carré qu'elle trouve jusque à ce qu'il arrive à un obstacle
	//arrivé à une obstacle on try de merge
	while (position.y < board->line_nb) // on boucle ligne par ligne en allant de haut en bas
	{
		position.x = x_start;
		while (position.x >= 0 && position.x < board->col_nb) //et là on va à guache ou à droite dans chacune des ligne 
		{
			if (board->tiles[position.y][position.x].value != 0)
				move_tile_horizontal(position, vector_dir, board);
			position.x -= vector_dir.x; // on part du bord opposé donc on doit aller dans la direction inverse
		}
		position.y++;
	}
}

//fonction à appeler pour initer un move dans une direction
void board_move(enum_dir direction, t_board *board)
{
	board->has_changed = false;
	if (direction == UP || direction == DOWN)
		move_board_vertical(direction, board);
	else if (direction == LEFT || direction == RIGHT)
		move_board_horizontal(direction, board);
	
	//clear the is_merge status
	for(int y = 0; y < board->line_nb; y++)
	{
		for(int x = 0; x < board->col_nb; x++)
			board->tiles[y][x].is_merged = false;
	}
}
