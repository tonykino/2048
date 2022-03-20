/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 05:44:28 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 06:43:54 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

void	ft_win_menu(t_game *game)
{
	int	i;
	char *menu[] = {
		" CONTINUE ",
		" SAVE ",
		" EXIT "
	};
	int	menu_size = sizeof(menu) / sizeof(char *);
	int menu_height = 4 + menu_size; // int = nb lines hard coded in the print of the menu
	int	menu_width = 10; // Used to center the menu

	game->key = 0;
	game->selected_menu_pos = 0;
	
	while (1)
	{
		i = 0;
		ft_clear(game); // My own clear function to also clear other variables (like cursor position)
		ft_get_win_size(game);

		/*
			MENU LOGIC
		*/
		if (ft_is_esc_key(game))
		{
			game->selected_menu_pos = -1; // Otherwise it would be 0 and just relaunch the menu
			break;
		}
		else if (ft_is_up_key(game))
			game->selected_menu_pos = ft_select_menu(-1, game->selected_menu_pos, menu_size);
		else if (ft_is_down_key(game))
			game->selected_menu_pos = ft_select_menu(1, game->selected_menu_pos, menu_size);
		else if (ft_is_enter_key(game))
			break;

		if (game->nb_char_cols < menu_width || game->nb_char_lines < menu_height)
			ft_too_small(game); // If window is to small to display
		else
		{
			// Actually print the menu
			ft_vertical_align(game, menu_height);
			ft_print_center(game, "YOUR SCORE :");
			ft_break_line(game);
			ft_print_center(game, ft_itoa(game->board.score));
			ft_break_lines(game, 2);
			for (i = 0; i < menu_size; i++)
			{
				if (i == 2)
					ft_break_line(game);
				if (game->selected_menu_pos == i)
					attron(A_REVERSE);
				ft_print_center(game, menu[i]);
				if (game->selected_menu_pos == i)
					attroff(A_REVERSE);
				ft_break_line(game);
			}
		}
		
		refresh();
		game->key = getch();
	}

	if (game->selected_menu_pos == 0) // Continue
	{
		game->board.game_status = KEEP_PLAYING;
		ft_game_loop(game);
	}
	else if (game->selected_menu_pos == 1) // Save
	{
		clear();
		printw("SAVE");
		refresh();
		while (1)
		{}
	}
}