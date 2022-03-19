/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokino <tokino@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 01:00:19 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 22:37:37 by tokino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

/*
	FOR DEBUG PURPOSES ONLY
	Prints all the debug information on the screen
*/

void	ft_debug(t_vars *vars)
{
	printw("\n\n%d\n\n", vars->key);
}