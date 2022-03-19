#include "2048.h"

void print_menu()
{
	t_vars	vars;

	ft_init_struct(&vars);
	clear();
	ft_get_win_size(&vars);
	ft_start_menu(&vars); // Launch the start menu
}