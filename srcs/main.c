#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "time.h"
#include "randomizer.h"
#include "board_movement.h"
#include "2048.h"

void print_tile_background(t_board *board, t_tile *tile)
{
	for (int line = 0; line < board->tile_height; line++)
	{
		move(	tile->line_idx * (board->tile_height + 1) + 1 + line, \
				tile->col_idx * (board->tile_width + 1) + 1);
		hline(' ', board->tile_width);
	}
}

void print_tile_content(t_board *board, t_tile *tile)
{
	attron(COLOR_PAIR(tile->value));
	attron(A_BOLD);
	print_tile_background(board, tile);
	if (tile->value != 0)
		mvprintw(	tile->line_idx * (board->tile_height +1) + board->tile_height / 2, \
					tile->col_idx * (board->tile_width + 1) + board->tile_width / 2, \
					ft_itoa(tile->value));
	attroff(A_BOLD);
	attroff(COLOR_PAIR(tile->value));
}

void print_tiles_content(t_board *board)
{
	for (int line = 0; line < board->line_nb; line++)
	{
		for (int col = 0; col < board->col_nb; col++)
		{
			print_tile_content(board, &board->tiles[line][col]);
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
	t_board board;
	t_vars	vars;
    WINDOW *game_window;
    char msg[40];
	
	ft_init_struct(&vars);
	srand(time(NULL));
	// These functions are necessary to get character-at-a-time input
    initscr(); // Initialize curses library
	cbreak();  // Description of cbreak, noecho and nonl : https://manpages.debian.org/bullseye/ncurses-doc/nonl.3ncurses.en.html
	noecho();
	nonl();
	curs_set(0); // Make the cursor invisible
	// game_window = newwin(LINES, COLS, 0, 0);
	keypad(stdscr, TRUE); // enable arrow keys // necessary ?? A priori oui sinon les fleches envoient 3 signaux
	
	clear();
	ft_get_win_size(&vars);
	ft_start_menu(&vars); // Launch the start menu
	clear();
	
	
	init_board(&board);

	if (has_colors() == FALSE) {
    	endwin();
    	printf("Your terminal does not support color\n");
    	exit(1);
    }

	init_colors();
	generate_random_number_in_random_empty_tile(&board);
	generate_random_number_in_random_empty_tile(&board);

	int c = 0; // à retenir qu'il est pas init
    while(1) {
        clear();
		update_board(&board);

		
		switch (c)
		{
		case 410: // resize window
			break;
		case KEY_UP:
		case KEY_DOWN:
		case KEY_LEFT:
		case KEY_RIGHT:
			handle_arrow(c, &board);
			break;
		default:
			// mvprintw(10, 1, "Character pressed is = %d Hopefully it can be printed as '%c'", c, c);
			break;
		}

		print_tiles_content(&board);

		print_board(&board);

		sprintf(msg, "Game status = %d", board.game_status);
        mvprintw(1, 1, msg); // Message de debug temporaire	
		// sprintf(msg, "Tile_width = %d", board.tile_width);
        // mvprintw(1, 1, msg); // Message de debug temporaire	
		// sprintf(msg, "Tile_heigth = %d", board.tile_height);
        // mvprintw(2, 1, msg); // Message de debug temporaire	
		// sprintf(msg, "COLS = %d, LINES = %d", COLS, LINES);
        // mvprintw(3, 1, msg); // Message de debug temporaire
		sprintf(msg, "board has changed ? %d", board.has_changed);
        mvprintw(4, 1, msg); // Message de debug temporaire

		refresh();
		c = getch();
    }
    endwin();
    
    free(game_window);
	// free_board(&board);
    
    return 0;
}
