/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leaderboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokino <tokino@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:04:00 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 02:41:18 by tokino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"
#include "file_scoring.h"

void	ft_leaderboard(t_game *game)
{
	int	i;
	t_vars *vars = &game->vars;

	t_score *scores = NULL;
	int res = get_scores_from_file(&scores);

	char *menu[] = {
		" BACK "
	};
	int menu_size = sizeof(menu) / sizeof(char *);

	size_t max_length = 0;

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
		ft_print_center(vars, "2048");
		ft_break_lines(vars, 2);
		t_score *tmpscores = scores;
		while (tmpscores)
		{
			int tmp = ft_strlen(tmpscores->pseudo) + ft_strlen(ft_itoa(tmpscores->score));
			if (tmp > max_length)
				max_length = tmp;
			tmpscores = tmpscores->next;
		}

		printw("\n\n");
		while(scores)
		{
			for (int x = 0; x < ((vars->nb_char_cols - max_length) / 2 - 3); x++)
				printw(" ");
			printw("%s ", scores->pseudo);
			for (int x = -1; x < ((int)max_length - (int)ft_strlen(scores->pseudo) - (int)ft_strlen(ft_itoa(scores->score))); x++)
				printw("-");
			printw(" ");
			printw("%d\n", scores->score);
			ft_break_line(vars);
			scores = scores->next;
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
		ft_start_menu(game);
}