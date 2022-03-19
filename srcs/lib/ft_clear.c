/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:47:38 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 15:48:09 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../2048.h"

void	ft_clear(t_vars *vars)
{
	clear();
	vars->actual_cursor_line = 0;
}