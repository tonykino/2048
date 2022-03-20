/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:57:53 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 01:14:56 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

void	ft_launch_game(t_vars *vars)
{
	clear();
	if (vars->game_size == 4)
		printw("4 X 4 Game");
	else if (vars->game_size == 5)
		printw("5 X 5 Game");
	refresh();

	while(1)
	{
		//test	
	}
}