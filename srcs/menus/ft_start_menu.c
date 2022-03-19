/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:06:09 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 17:05:26 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../2048.h"

void	ft_print_center(t_vars *vars, char *str)
{
	int	len;
	int	x;

	len = ft_strlen(str);
	x = (vars->nb_char_cols - len) / 2;
	mvprintw(vars->actual_cursor_line, x, "%s", str);
}

void	ft_start_menu(t_vars *vars)
{
	int	i;
	char *menu[] = {
		" PLAY ",
		" LEADERBOARD ",
		" EXIT "
	};
	int	menu_size = sizeof(menu) / sizeof(char *);
	int menu_height = 7 + menu_size; // 7 = nb lines hard coded in the print of the menu
	int	selected_menu_pos = 0;
	
	while (1)
	{
		i = 0;
		ft_clear(vars); // My own clear function to also clear other variables (like cursor position)

		/*
			MENU LOGIC
		*/
		if (ft_is_esc_key(vars))
			break;
		else if (ft_is_up_key(vars))
			selected_menu_pos = ft_select_menu(-1, selected_menu_pos, menu_size);
		else if (ft_is_down_key(vars))
			selected_menu_pos = ft_select_menu(1, selected_menu_pos, menu_size);
		else if (ft_is_enter_key(vars))
		{
			if (selected_menu_pos == 0) // Play
				ft_launch_game(vars);
			else if (selected_menu_pos == 1) // Leaderboard
				ft_leaderboard(vars);
			else if (selected_menu_pos == 2) // Exit
				break;
		}

		/*
			ACTUALLY PRINT THE MENU
		*/
		//ft_debug(vars);
		ft_get_win_size(vars);
		ft_vertical_align(vars, menu_height);
		ft_break_lines(vars, 4);
		ft_print_center(vars, "2048");
		ft_break_lines(vars, 2);
		for (i = 0; i < menu_size; i++)
		{
			if (selected_menu_pos == i)
				attron(A_REVERSE);
			ft_print_center(vars, menu[i]);
			if (selected_menu_pos == i)
				attroff(A_REVERSE);
			ft_break_line(vars);
		}
		refresh();
		vars->key = getch();
	}
}