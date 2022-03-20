#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"
#include "struct.h"
#include "board.h"
#include "randomizer.h"
#include "board_movement.h"
#include "check_board_status.h"
#include "2048.h"

void print_tile_background(t_game *game, t_tile *tile)
{
	for (int line = 0; line < game->board.tile_height; line++)
	{
		move(	tile->line_idx * (game->board.tile_height + 1) + 1 + line, \
				tile->col_idx * (game->board.tile_width + 1) + 1);
		hline(' ', game->board.tile_width);
	}
}

void print_tile_value(t_game *game, t_tile *tile)
{
	if (tile->value != 0)
	{
		if (ft_is_ascii_possible(game))
			ft_print_tile_ascii(game, tile);
		else
		{
			mvprintw(	tile->line_idx * (game->board.tile_height +1) + game->board.tile_height / 2, \
					tile->col_idx * (game->board.tile_width + 1) + game->board.tile_width / 2, \
					ft_itoa(tile->value));
		}
	}
}

void print_tile_content(t_game *game, t_tile *tile)
{
	attron(COLOR_PAIR(tile->value));
	attron(A_BOLD);
	print_tile_background(game, tile);
	print_tile_value(game, tile);
	attroff(A_BOLD);
	attroff(COLOR_PAIR(tile->value));
}

void print_tiles_content(t_game *game)
{
	for (int line = 0; line < game->board.line_nb; line++)
	{
		for (int col = 0; col < game->board.col_nb; col++)
		{
			print_tile_content(game, &game->board.tiles[line][col]);
		}
	}
}
// #define COLOR_BLACK	0
// #define COLOR_RED	1
// #define COLOR_GREEN	2
// #define COLOR_YELLOW	3
// #define COLOR_BLUE	4
// #define COLOR_MAGENTA	5
// #define COLOR_CYAN	6
// #define COLOR_WHITE	7
void init_colors()
{
	start_color();
	init_pair(BORDER_PAIR, COLOR_CYAN, COLOR_CYAN);
	init_pair(VALUE2_PAIR, COLOR_YELLOW, COLOR_WHITE);
	init_pair(VALUE4_PAIR, COLOR_GREEN, COLOR_WHITE);
	init_pair(VALUE8_PAIR, COLOR_BLUE, COLOR_WHITE);
	init_pair(VALUE16_PAIR, COLOR_GREEN, COLOR_YELLOW);
	init_pair(VALUE32_PAIR, COLOR_BLUE, COLOR_YELLOW);
	init_pair(VALUE64_PAIR, COLOR_RED, COLOR_YELLOW);
	init_pair(VALUE128_PAIR, COLOR_BLUE, COLOR_RED);
	init_pair(VALUE256_PAIR, COLOR_MAGENTA, COLOR_RED);
	init_pair(VALUE512_PAIR, COLOR_CYAN, COLOR_RED);
}

// Test movement with gcc main.c board.c ft_calloc.c randomizer.c board_movement.c vector_conversions.c -lncurses -o test && ./test

void handle_arrow(int direction, t_board *board)
{
	board_move(direction, board);
	if (board->has_changed)
	{
		generate_random_number_in_random_empty_tile(board);
		check_board_status(board);
	}
	// TODO : Check victory or defeat ?
}

int main()
{
	t_game game;

	ft_init(&game); // Init everything
	ft_start_menu(&game); // Launch the start menu
    
	endwin();
    return 0;
}
