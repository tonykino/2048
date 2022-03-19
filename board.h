#ifndef BOARD_H
#define BOARD_H

#include "libft.h"

typedef struct s_tile {
	int value;
	int line_idx;
	int col_idx;
	// bool is_merged;
} t_tile;

typedef struct s_board {
	int line_nb;
	int col_nb;
	int tile_nb;
	int tile_width;
	int tile_height;
	t_tile **tiles;
} t_board;

void init_board(t_board *board);
void update_board(t_board *board);
// void free_board(t_board *board);
void print_board(t_board *board);

#endif