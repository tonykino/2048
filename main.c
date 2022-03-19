#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "time.h"
#include "randomizer.h"

void print_tile_content(t_board *board, t_tile *tile)
{
	char msg[5];

	sprintf(msg, "%d", tile->value); // TODO : Remplacer sprintf par une fonction custom
	mvprintw(tile->line_idx * (board->tile_height +1) + board->tile_height / 2, tile->col_idx * (board->tile_width + 1) + board->tile_width / 2, msg);
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


// Test with gcc main.c board.c ft_calloc.c randomizer.c -lncurses -o test && ./test

int main()
{
	t_board board;
    WINDOW *game_window;
    char msg[40];
	
	srand(time(NULL));
	// These functions are necessary to get character-at-a-time input
    initscr(); // Initialize curses library
	cbreak();  // Description of cbreak, noecho and nonl : https://manpages.debian.org/bullseye/ncurses-doc/nonl.3ncurses.en.html
	noecho();
	nonl();
	game_window = newwin(LINES, COLS, 0, 0);
	keypad(game_window, TRUE); // enable arrow keys // necessary ?? A priori oui sinon les fleches envoient 3 signaux
	init_board(&board);

	int c;
    while(1) {
        clear();
		update_board(&board);
		print_board(&board);

		sprintf(msg, "Tile_width = %d", board.tile_width);
        mvprintw(1, 1, msg); // Message de debug temporaire		
		sprintf(msg, "Tile_heigth = %d", board.tile_height);
        mvprintw(2, 1, msg); // Message de debug temporaire	
		sprintf(msg, "COLS = %d, LINES = %d", COLS, LINES);
        mvprintw(3, 1, msg); // Message de debug temporaire

		switch (c)
		{
		case 410: // resize window
			break;
		case KEY_UP:
       		mvprintw(5, 1, "ARROW_UP pressed");
				// TODO : manage up key
			generate_random_number_in_random_empty_tile(&board);
			break;
		case KEY_DOWN:
			mvprintw(5, 1, "ARROW_DOWN pressed");
				// TODO : manage down key	
			generate_random_number_in_random_empty_tile(&board);
			break;
		case KEY_LEFT:
			mvprintw(5, 1, "ARROW_LEFT pressed");	
				// TODO : manage left key
			generate_random_number_in_random_empty_tile(&board);
			break;
		case KEY_RIGHT:
			mvprintw(5, 1, "ARROW_RIGHT pressed");
				// TODO : manage right key
			generate_random_number_in_random_empty_tile(&board);
			break;
		default:
			mvprintw(10, 1, "Character pressed is = %d Hopefully it can be printed as '%c'", c, c);
			break;
		}

		print_tiles_content(&board);
        
		wrefresh(game_window);
		refresh();
		c = wgetch(game_window);
    }
    delwin(game_window);
    endwin();
    
    free(game_window);
	// free_board(&board);
    
    return 0;
}
