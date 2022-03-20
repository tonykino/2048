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



// Test movement with gcc main.c board.c ft_calloc.c randomizer.c board_movement.c vector_conversions.c -lncurses -o test && ./test



int main()
{
	t_game game;

	ft_init(&game); // Init everything
	ft_start_menu(&game); // Launch the start menu
    
	endwin();
    return 0;
}
