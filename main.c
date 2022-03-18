#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_board {
	int lines;
	int cols;
	int *tiles;
} t_board;

void init_board(t_board *board)
{
	board->cols = 4;
	board->lines = 4;
	board->tiles = NULL;
}

void print_board(t_board *board)
{
	int tile_width = (COLS - board->cols - 1) / board->cols;
	int tile_height = (LINES - board->lines - 1) / board->lines;
	for (int col = 0; col < board->cols * (tile_width + 1) + 1; col++)
	{
		for (int line = 0; line < board->lines * (tile_height + 1) + 1; line++)
		{
			if (line % (tile_height + 1) == 0 && col % (tile_width + 1) == 0)
				mvprintw(line, col, "+");
			else if (line % (tile_height + 1) == 0)
				mvprintw(line, col, "-");
			else if (col % (tile_width + 1) == 0)
				mvprintw(line, col, "|");
		}
	}
}


// Test with gcc main.c -lncurses -o test && ./test

int main()
{
	t_board board;
    WINDOW *window;
    char msg[100];
	
    initscr();
	init_board(&board);
    while(1) {
        clear();
		print_board(&board);

		// sprintf(msg, "Tile_height = %d\n", tile_height);
        // mvprintw(LINES/2 - 1, (COLS / 2) - (taille / 2), msg);
		// sprintf(msg, "Tile_width = %d\n", tile_width);
        // mvprintw(LINES/2, (COLS / 2) - (taille / 2), msg);		
		// sprintf(msg, "COLS = %d, LINES = %d\n", COLS, LINES);
        // mvprintw(LINES/2 + 1, (COLS / 2) - (taille / 2), msg);

        refresh();
        if(getch() != 410)
            break;
    }
    
    endwin();
    
    free(window);
    
    return 0;
}