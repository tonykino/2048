/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 01:00:19 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 02:40:54 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../2048.h"

/*
	FOR DEBUG PURPOSES ONLY
	Prints all the debug information on the screen
*/

void	ft_debug(t_vars *vars)
{
	
	//vars->nb_char_lines = 0;
	printw("\n\n%d\n\n", vars->key);
}