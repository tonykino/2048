/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:06:09 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 19:41:56 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../2048.h"

void	ft_start_menu(t_vars *vars)
{
	int	i;
	char *menu[] = {
		" PLAY ",
		" TOP SCORES ",
		" EXIT "
	};
	int	menu_size = sizeof(menu) / sizeof(char *);
	int menu_height = 3 + menu_size; // int = nb lines hard coded in the print of the menu

	vars->key = 0;
	vars->selected_menu_pos = 0;

	int	menu_width = 13;
	
	while (1)
	{
		i = 0;
		ft_clear(vars); // My own clear function to also clear other variables (like cursor position)
		ft_get_win_size(vars);

		if (vars->nb_char_cols < menu_width || vars->nb_char_lines < menu_height)
		{
			ft_vertical_align(vars, 1);
			ft_print_center(vars, "TOO SMALL");
		}
		else
		{
			/*
				MENU LOGIC
			*/
			if (ft_is_esc_key(vars))
			{
				vars->selected_menu_pos = -1; // Otherwise it would be 0 and just relaunch the menu
				break;
			}
			else if (ft_is_up_key(vars))
				vars->selected_menu_pos = ft_select_menu(-1, vars->selected_menu_pos, menu_size);
			else if (ft_is_down_key(vars))
				vars->selected_menu_pos = ft_select_menu(1, vars->selected_menu_pos, menu_size);
			else if (ft_is_enter_key(vars))
				break;

			/*
				ACTUALLY PRINT THE MENU
			*/
			//ft_debug(vars);
			ft_vertical_align(vars, menu_height);
			ft_print_center(vars, "2048");
			ft_break_lines(vars, 2);
			for (i = 0; i < menu_size; i++)
			{
				if (i == 2)
					ft_break_line(vars);
				if (vars->selected_menu_pos == i)
					attron(A_REVERSE);
				ft_print_center(vars, menu[i]);
				if (vars->selected_menu_pos == i)
					attroff(A_REVERSE);
				ft_break_line(vars);
			}
		}
		
		refresh();
		vars->key = getch();
	}

	if (vars->selected_menu_pos == 0) // Play
		ft_size_menu(vars);
	else if (vars->selected_menu_pos == 1) // Leaderboard
		ft_leaderboard(vars);
}