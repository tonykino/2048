#include "2048.h"

void print_menu(t_game *game)
{
	ft_init_struct(&game->vars);
	clear();
	ft_get_win_size(&game->vars);
	ft_start_menu(game); // Launch the start menu
}