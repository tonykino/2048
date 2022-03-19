/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 01:00:19 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 13:45:44 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../2048.h"

/*
	FOR DEBUG PURPOSES ONLY
	Prints all the debug information on the screen
*/

void	ft_debug(t_vars *vars)
{
	printw("BONJOUR \n\n%d\n\n", vars->key);
}