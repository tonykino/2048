/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leaderboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:04:00 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 17:04:11 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../2048.h"

void	ft_leaderboard(t_vars *vars)
{
	clear();
	printw("Coucou leaderboard %d", vars->actual_cursor_line);
	refresh();

	while(1)
	{
		
	}
}