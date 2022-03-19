/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_break_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokino <tokino@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:34:21 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 22:37:37 by tokino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

void	ft_break_lines(t_vars *vars, int nb_breaks)
{
	while (nb_breaks > 0)
	{
		ft_break_line(vars);
		nb_breaks--;
	}
}