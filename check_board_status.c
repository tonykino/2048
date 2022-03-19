#include "check_board_status.h"

int check_win(t_board *board, long win_val)
{
	for(int y = 0; y < board->line_nb; y++)
	{
		for(int x = 0; x < board->col_nb; x++)
		{
			if (board->tiles[y][x].value == win_val)
				return (1);
		}
	}
	return (0);
}

//fonction qui va checker le carré en dessous et à droite 
//de chaque carré pour voir si il y a au moins deux carrés égaux
int check_lost(t_board *board)
{
	for(int y = 0; y < board->line_nb; y++)
	{
		for(int x = 0; x < board->col_nb; x++)
		{
			if (y < board->line_nb - 1 && board->tiles[y][x].value == board->tiles[y + 1][x].value)
				return (0);
			if (x < board->col_nb -1 && board->tiles[y][x].value == board->tiles[y][x + 1].value)
				return (0);
		}
	}
	return (1);
}

void check_board_status(t_board *board)
{
	enum e_const
	{
		WIN_VALUE = 2048
	};
	long win_val;

	if (WIN_VALUE != 0 && (WIN_VALUE & (WIN_VALUE - 1)) == 0)
		win_val = WIN_VALUE;
	else
		win_val = DEFAULT_WIN;

	if (board->game_status != KEEP_PLAYING && check_win(board, win_val))
		board->game_status = WIN;
	else if (check_loose(board))
		board->game_status = LOST;
}
