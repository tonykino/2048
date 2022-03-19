#include <ncurses.h>
#include "board.h"

static void _init_tile(t_tile *tile, int line, int col)
{
	tile->line_idx = line;
	tile->col_idx = col;
	tile->value = 0;
}

void init_board(t_board *board)
{
	board->col_nb = 4;
	board->line_nb = 4;
	board->tile_nb = board->col_nb * board->line_nb;
	board->tiles = ft_calloc(board->line_nb, sizeof(t_tile *)); // Todo : Protéger les mallocs
	for (int i = 0; i < board->line_nb; i++)
	{
		board->tiles[i] = ft_calloc(board->col_nb, sizeof(t_tile)); // Todo : Protéger les mallocs
	}
	board->tile_width = (COLS - board->col_nb - 1) / board->col_nb;
	board->tile_height = (LINES - board->line_nb - 1) / board->line_nb;

	for (int line = 0; line < board->line_nb; line++)
	{
		for (int col = 0; col < board->col_nb; col++)
		{
			_init_tile(&board->tiles[line][col], line, col);
		}
	}
}

void update_board(t_board *board)
{
	board->tile_width = (COLS - board->col_nb - 1) / board->col_nb;
	board->tile_height = (LINES - board->line_nb - 1) / board->line_nb;
	// board->has_changed = false; // TODO BUG => has_changed need to be set to false to avoid creating new tile if user click on any key 
}

// void free_board(t_board *board)
// {
// 	if (!board)
// 		return ;
// 	if (board->tiles)
// 	{
// 		free(board->tiles);
// 		board->tiles = NULL;
// 	}
// 	board = NULL;
// }

void print_board(t_board *board)
{
	for (int line = 0; line < board->line_nb * (board->tile_height + 1) + 1; line++)
	{
		for (int col = 0; col < board->col_nb * (board->tile_width + 1) + 1; col++)
		{
			if (line % (board->tile_height + 1) == 0 || col % (board->tile_width + 1) == 0)
			{
				attron(COLOR_PAIR(BORDER_PAIR));
				mvaddch(line, col, ' ');
				attroff(COLOR_PAIR(BORDER_PAIR));
			}	
		}
	}
}