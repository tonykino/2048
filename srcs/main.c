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
#include "file_scoring.h"

// Test movement with gcc main.c board.c ft_calloc.c randomizer.c board_movement.c vector_conversions.c -lncurses -o test && ./test

int free_all(t_game *game, int error)
{
	if (game->board.tiles)
	{
		for(int y = 0; y < game->game_size; y++)
		{
			if (game->board.tiles[y])
				free(game->board.tiles[y]);
		}
		free(game->board.tiles);
	}
	if (!error)
		put_score_to_file(game->scores);
	// if (!error && put_score_to_file(game->scores) == ERROR_FD)
		// print_error_msg(ERROR_FD);
	destroy_list(&game->scores);
	return 0;
}

int free_all(t_game *game, int error)
{
	if (game->board.tiles)
	{
		for(int y = 0; y < game->game_size; y++)
		{
			if (game->board.tiles[y])
				free(game->board.tiles[y]);
		}
		free(game->board.tiles);
	}
	if (!error)
		put_score_to_file(game->scores);
	// if (!error && put_score_to_file(game->scores) == ERROR_FD)
		// print_error_msg(ERROR_FD);
	destroy_list(&game->scores);
}

int main()
{
	int ret;
	t_game game;
	ft_memset(&game, '\0', sizeof(t_game));

	if ((ret = ft_init(&game)) != SUCCESS) // Init everything
	{
		// print_err_msg(ret); // TODO THIS FUNCTION
		return (free_all(&game, 1));
	}
	ft_start_menu(&game); // Launch the start menu
    
	endwin();
	delwin(stdscr);
	free_all(&game, 0);
    return 0;
}
