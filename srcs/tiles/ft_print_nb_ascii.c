#include "2048.h"

void	ft_print_nb_ascii(int nb, int x, int y)
{
	if (nb == 0)
	{
		mvprintw(y + 0, x, "000");
		mvprintw(y + 1, x, "0 0");
		mvprintw(y + 2, x, "0 0");
		mvprintw(y + 3, x, "0 0");
		mvprintw(y + 4, x, "000");
	}
	else if (nb == 1)
	{
		mvprintw(y + 0, x, " 0 ");
		mvprintw(y + 1, x, "00 ");
		mvprintw(y + 2, x, " 0 ");
		mvprintw(y + 3, x, " 0 ");
		mvprintw(y + 4, x, "000");
	}
	else if (nb == 2)
	{
		mvprintw(y + 0, x, "000");
		mvprintw(y + 1, x, "  0");
		mvprintw(y + 2, x, "000");
		mvprintw(y + 3, x, "0  ");
		mvprintw(y + 4, x, "000");
	}
	else if (nb == 3)
	{
		mvprintw(y + 0, x, "000");
		mvprintw(y + 1, x, "  0");
		mvprintw(y + 2, x, "000");
		mvprintw(y + 3, x, "  0");
		mvprintw(y + 4, x, "000");
	}
	else if (nb == 4)
	{
		mvprintw(y + 0, x, "0 0");
		mvprintw(y + 1, x, "0 0");
		mvprintw(y + 2, x, "000");
		mvprintw(y + 3, x, "  0");
		mvprintw(y + 4, x, "  0");
	}
	else if (nb == 5)
	{
		mvprintw(y + 0, x, "000");
		mvprintw(y + 1, x, "0  ");
		mvprintw(y + 2, x, "000");
		mvprintw(y + 3, x, "  0");
		mvprintw(y + 4, x, "000");
	}
	else if (nb == 6)
	{
		mvprintw(y + 0, x, "000");
		mvprintw(y + 1, x, "0  ");
		mvprintw(y + 2, x, "000");
		mvprintw(y + 3, x, "0 0");
		mvprintw(y + 4, x, "000");
	}
	else if (nb == 7)
	{
		mvprintw(y + 0, x, "000");
		mvprintw(y + 1, x, "  0");
		mvprintw(y + 2, x, "  0");
		mvprintw(y + 3, x, "  0");
		mvprintw(y + 4, x, "  0");
	}
	else if (nb == 8)
	{
		mvprintw(y + 0, x, "000");
		mvprintw(y + 1, x, "0 0");
		mvprintw(y + 2, x, "000");
		mvprintw(y + 3, x, "0 0");
		mvprintw(y + 4, x, "000");
	}
	else if (nb == 9)
	{
		mvprintw(y + 0, x, "000");
		mvprintw(y + 1, x, "0 0");
		mvprintw(y + 2, x, "000");
		mvprintw(y + 3, x, "  0");
		mvprintw(y + 4, x, "000");
	}
}