#include <ncurses.h>
#include "board.h"

void update_board(t_game *game)
{
	game->board.tile_width = (COLS - game->board.col_nb - 1) / game->board.col_nb;
	game->board.tile_height = (LINES - game->board.line_nb - 1) / game->board.line_nb;
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

void print_board(t_game *game)
{
	for (int line = 0; line < game->board.line_nb * (game->board.tile_height + 1) + 1; line++)
	{
		for (int col = 0; col < game->board.col_nb * (game->board.tile_width + 1) + 1; col++)
		{
			if (line % (game->board.tile_height + 1) == 0 || col % (game->board.tile_width + 1) == 0)
			{
				attron(COLOR_PAIR(BORDER_PAIR));
				mvaddch(line, col, ' ');
				attroff(COLOR_PAIR(BORDER_PAIR));
			}
		}
	}
}