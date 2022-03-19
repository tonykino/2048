#ifndef BOARD_H
#define BOARD_H

#include "libft.h"
#include <stdbool.h>

#define BORDER_PAIR		1
#define VALUE2_PAIR		2
#define VALUE4_PAIR		4
#define VALUE8_PAIR		8
#define VALUE16_PAIR	16
#define VALUE32_PAIR	32
#define VALUE64_PAIR	64
#define VALUE128_PAIR	128
#define VALUE256_PAIR	256
#define VALUE512_PAIR	512
#define VALUE1024_PAIR	1024
#define VALUE2048_PAIR	2048

typedef struct s_tile {
	int value;
	int line_idx;
	int col_idx;
	bool is_merged;
} t_tile;

typedef struct s_board {
	int line_nb;
	int col_nb;
	int tile_nb;
	int tile_width;
	int tile_height;
	bool has_changed;
	int	score;
	t_tile **tiles;
} t_board;

void init_board(t_board *board);
void update_board(t_board *board);
// void free_board(t_board *board);
void print_board(t_board *board);

#endif
