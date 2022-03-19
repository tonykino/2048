/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 00:28:50 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 02:41:16 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../2048.h"

int	main()
{
	t_vars	vars;
	int		esc = 0;
	int		i;

	ft_init_struct(&vars);
	initscr();
	while (1) {
		//clear(); // Clear the screen

		/* Init la screen + Récupérer les variables */
		vars.nb_char_lines = LINES;
		vars.nb_char_cols = COLS;
		/* Fin d'init de la screen */

		// switch (vars.key)
		// {
		// 	case UP:
		// 		//printw("UP");
		// 		break;
		// 	case DOWN:
		// 		//printw("DOWN");
		// 		break;
		// 	case LEFT:
		// 		//printw("LEFT");
		// 		break;
		// 	case RIGHT:
		// 		//printw("RIGHT");
		// 		break;
		// 	case ESC:
		// 		//printw("ESC");
		// 		esc = 1;
		// 		break;
		// }

		esc = 0;
		if (esc == 1)
			break;

		ft_debug(&vars); // Print debug info
		refresh(); // Refresh the screen

		for (i = 0; i < 10; i++) // Mets en pause le script et attends l'appui sur une touche
			vars.key = getch();
	}

	endwin();

	return 0;
}