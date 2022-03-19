#include "randomizer.h"

static int _get_empty_tile_nb(t_board *board)
{
	int empty_tile_nb = 0;

	for (int line = 0; line < board->line_nb; line++)
	{
		for (int col = 0; col < board->col_nb; col++)
		{
			if (board->tiles[line][col].value == 0)
				empty_tile_nb++;
		}
	}
	return empty_tile_nb;
}

static t_tile *_get_tile_to_fill(t_board *board, int rand_nb)
{
	t_tile *tile_to_fill = NULL;
	
	for (int line = 0; line < board->line_nb; line++)
	{
		for (int col = 0; col < board->col_nb; col++)
		{
			if (board->tiles[line][col].value == 0 && rand_nb >= 0)
			{
				tile_to_fill = &board->tiles[line][col];
				rand_nb--;
			}
		}
	}
	return tile_to_fill;
}

static int _generate_random_valid_number(void)
{
	// valid number is either 2 or 4. 2 must appear more often than 4.
	int rand_value = 5 * ((float)rand())/RAND_MAX; // Generate either 0, 1, 2, 3, or 4
	if (rand_value < 4) // In theorie, this give four 2 to one 4. To adjust.
		rand_value = 2;
	return rand_value;
}

void generate_random_number_in_random_empty_tile(t_board *board)
{
    char msg[80];

	int empty_tile_nb = _get_empty_tile_nb(board);
	if (empty_tile_nb == 0)
	{
		sprintf(msg, "Error : no empty tile available"); 
		mvprintw(4, 1, msg); // Message de debug temporaire, cas spécial à gérer
		return ;
	}
	int rand_nb = empty_tile_nb * ((float)rand())/RAND_MAX;
	t_tile *tile_to_fill = _get_tile_to_fill(board, rand_nb);
	if (tile_to_fill == NULL)
	{
		sprintf(msg, "Error : tile to fill is NULL (rand_nb = %d)", rand_nb);
		mvprintw(4, 1, msg); // Message de debug temporaire, cas spécial à gérer
		return ;
	}
	tile_to_fill->value = _generate_random_valid_number();
	sprintf(msg, "Rand_nb = %d, new value = %d", rand_nb, tile_to_fill->value);
	mvprintw(4, 1, msg); // Message de debug temporaire, cas spécial à gérer
}
