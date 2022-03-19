/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:06:09 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 13:45:10 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../2048.h"

void	ft_start_menu(t_vars *vars)
{
	while (1)
	{
		clear();
		ft_debug(vars);
		refresh();
		vars->key = getch();
	}
}