/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:57:53 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 06:25:13 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

void	ft_launch_game(t_game *game)
{
    char msg[40];
	clear();

	// nonl(); // Remove to permit enter
	ft_init_board(game);

	if (has_colors() == FALSE) {
		endwin();
		printf("Your terminal does not support color\n");
		exit(1); // ??????? C'est pas interdit ?
	}

	init_colors();
	generate_random_number_in_random_empty_tile(game);
	generate_random_number_in_random_empty_tile(game);

	ft_game_loop(game); // Le mettre dans une fonction séparée permet de relancer la loop sans ecraser la partie en cours
}