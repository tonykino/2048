/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokino <tokino@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:57:53 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 11:44:25 by tokino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"
#include "board.h"
#include "randomizer.h" 

// #define COLOR_BLACK	0
// #define COLOR_RED	1
// #define COLOR_GREEN	2
// #define COLOR_YELLOW	3
// #define COLOR_BLUE	4
// #define COLOR_MAGENTA	5
// #define COLOR_CYAN	6
// #define COLOR_WHITE	7
void init_colors()
{
	start_color();
	init_pair(BORDER_PAIR, COLOR_CYAN, COLOR_CYAN);
	init_pair(VALUE2_PAIR, COLOR_YELLOW, COLOR_WHITE);
	init_pair(VALUE4_PAIR, COLOR_GREEN, COLOR_WHITE);
	init_pair(VALUE8_PAIR, COLOR_BLUE, COLOR_WHITE);
	init_pair(VALUE16_PAIR, COLOR_GREEN, COLOR_YELLOW);
	init_pair(VALUE32_PAIR, COLOR_BLUE, COLOR_YELLOW);
	init_pair(VALUE64_PAIR, COLOR_RED, COLOR_YELLOW);
	init_pair(VALUE128_PAIR, COLOR_BLUE, COLOR_RED);
	init_pair(VALUE256_PAIR, COLOR_MAGENTA, COLOR_RED);
	init_pair(VALUE512_PAIR, COLOR_CYAN, COLOR_RED);
}


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