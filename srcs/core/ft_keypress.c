/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokino <tokino@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:25:20 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 22:37:37 by tokino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

int	ft_is_left_key(t_vars *vars)
{
	if (vars->key == LEFT)
		return (1);
	else
		return (0);
}

int	ft_is_right_key(t_vars *vars)
{
	if (vars->key == RIGHT)
		return (1);
	else
		return (0);
}

int	ft_is_up_key(t_vars *vars)
{
	if (vars->key == UP)
		return (1);
	else
		return (0);
}

int	ft_is_down_key(t_vars *vars)
{
	if (vars->key == DOWN)
		return (1);
	else
		return (0);
}

int	ft_is_enter_key(t_vars *vars)
{
	if (vars->key == ENTER)
		return (1);
	else
		return (0);
}

int	ft_is_esc_key(t_vars *vars)
{
	if (vars->key == ESC)
		return (1);
	else
		return (0);
}