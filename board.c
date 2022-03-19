#include <ncurses.h>
#include "board.h"

void init_board(t_board *board)
{
	board->col_nb = 4;
	board->line_nb = 4;
	board->tile_nb = board->col_nb * board->line_nb;
	board->tiles = calloc(board->line_nb, sizeof(int *));
	for (int i = 0; i < board->line_nb; i++)
	{
		board->tiles[i] = calloc(board->col_nb, sizeof(int));
	}
	board->tile_width = (COLS - board->col_nb - 1) / board->col_nb;
	board->tile_height = (LINES - board->line_nb - 1) / board->line_nb;
	for (int i = 0; i < board->line_nb; i++)
	{
		for (int j = 0; j < board->col_nb; j++)
		{
			board->tiles[i][j] = i * board->col_nb + j;
		}
	}
}

void update_board(t_board *board)
{
	board->tile_width = (COLS - board->col_nb - 1) / board->col_nb;
	board->tile_height = (LINES - board->line_nb - 1) / board->line_nb;
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
			if (line % (board->tile_height + 1) == 0 && col % (board->tile_width + 1) == 0)
				mvprintw(line, col, "+");
			else if (line % (board->tile_height + 1) == 0)
				mvprintw(line, col, "-");
			else if (col % (board->tile_width + 1) == 0)
				mvprintw(line, col, "|");
		}
	}
}