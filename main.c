#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_board {
	int line_nb;
	int col_nb;
	int tile_nb;
	int tile_width;
	int tile_height;
	int **tiles;
} t_board;

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


// Test with gcc main.c -lncurses -o test && ./test

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

		for (int line = 0; line < board.line_nb; line++)
		{
			for (int col = 0; col < board.col_nb; col++)
			{
				sprintf(msg, "%d", board.tiles[line][col]);
				mvprintw(line * (board.tile_height +1) + board.tile_height / 2, col * (board.tile_width + 1) + board.tile_width / 2, msg);
			}
		}

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
