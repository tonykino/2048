/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leaderboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:04:00 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 20:15:29 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../2048.h"

void	ft_leaderboard(t_vars *vars)
{
	int	i;
	char *leaderboard[] = {
		" JEAN ",
		" LOUIS ",
		" MICHEL ",
		" CLAUDETTE ",
		" HUGO ",
		" LOUISE ",
		" JEANNETTE ",
		" JEAN-CLAUDE ",
		" BERNARD ",
		" LUC "
	};
	char *scores[] = {
		"235345",
		"435",
		"346346",
		"3",
		"436",
		"45",
		"3452",
		"34657679",
		"232",
		"8087"
	};
	int	leaderboard_size = sizeof(leaderboard) / sizeof(char *);
	int leaderboard_height = leaderboard_size; // int = nb lines hard coded in the print of the menu

	char *menu[] = {
		" BACK "
	};
	int menu_size = sizeof(menu) / sizeof(char *);
	int menu_height = leaderboard_height + 5;

	int max_length = 0;

	vars->key = 0;
	vars->selected_menu_pos = 0;
	
	while (1)
	{
		i = 0;
		ft_clear(vars); // My own clear function to also clear other variables (like cursor position)

		/*
			MENU LOGIC
		*/
		if (ft_is_esc_key(vars))
		{
			vars->selected_menu_pos = -1;
			break;
		}
		else if (ft_is_enter_key(vars))
			break;

		/*
			ACTUALLY PRINT THE MENU
		*/
		//ft_debug(vars);
		ft_get_win_size(vars);
		ft_vertical_align(vars, menu_height);
		ft_print_center(vars, "2048");
		ft_break_lines(vars, 2);
		for (i = 0; i < leaderboard_size; i++)
		{
			int tmp = ft_strlen(leaderboard[i]) + ft_strlen(scores[i]);
			if (tmp > max_length)
				max_length = tmp;
		}
		printw("\n\n");
		for (i = 0; i < leaderboard_size; i++)
		{
			int x;
			for (x = 0; x < ((vars->nb_char_cols - max_length) / 2 - 3); x++)
				printw(" ");
			printw("%s", leaderboard[i]);
			for (x = -1; x < (max_length - ft_strlen(leaderboard[i]) - ft_strlen(scores[i])); x++)
				printw("-");
			printw(" ");
			printw("%s\n", scores[i]);
			ft_break_line(vars);
		}
		for (i = 0; i < menu_size; i++)
		{
			ft_break_line(vars);
			attron(A_REVERSE);
			ft_print_center(vars, menu[i]);
			attroff(A_REVERSE);
		}
		refresh();
		vars->key = getch();
	}

	if (vars->selected_menu_pos == 0) // Back
		ft_start_menu(vars);
}