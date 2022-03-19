#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"

void print_tile_content(t_board *board)
{
	char msg[30];
	for (int line = 0; line < board->line_nb; line++)
	{
		for (int col = 0; col < board->col_nb; col++)
		{
			sprintf(msg, "%d", board->tiles[line][col]);
			mvprintw(line * (board->tile_height +1) + board->tile_height / 2, col * (board->tile_width + 1) + board->tile_width / 2, msg);
		}
	}
}


// Test with gcc main.c board.c -lncurses -o test && ./test

int main()
{
	t_board board;
    WINDOW *game_window;
    char msg[30];
	
	// These functions are necessary to get character-at-a-time input
    initscr(); // Initialize curses library
	cbreak();  // Description of cbreak, noecho and nonl : https://manpages.debian.org/bullseye/ncurses-doc/nonl.3ncurses.en.html
	noecho();
	nonl();
	// game_window = newwin(LINES, COLS, 0, 0);
	// keypad(game_window, TRUE); // enable arrow keys // necessary ??
	init_board(&board);
	int c;
    while(1) {
        clear();
		update_board(&board);
		print_board(&board);
		print_tile_content(&board);

		sprintf(msg, "Tile_width = %d", board.tile_width);
        mvprintw(1, 1, msg);			
		sprintf(msg, "Tile_heigth = %d", board.tile_height);
        mvprintw(2, 1, msg);		
		sprintf(msg, "COLS = %d, LINES = %d", COLS, LINES);
        mvprintw(3, 1, msg);

		switch (c)
		{
		case 410: // resize window
			break;
		case 65:
       		mvprintw(5, 1, "ARROW_UP pressed");	
			break;
		case 66:
			mvprintw(6, 1, "ARROW_DOWN pressed");	
			break;
		case 68:
			mvprintw(7, 1, "ARROW_LEFT pressed");	
			break;
		case 67:
			mvprintw(8, 1, "ARROW_RIGHT pressed");	
			break;
		default:
			mvprintw(24, 0, "Character pressed is = %d Hopefully it can be printed as '%c'", c, c);
			break;
		}
        refresh();
		c = getch();
    }
    
    endwin();
    
    free(game_window);
	// free_board(&board);
    
    return 0;
}
