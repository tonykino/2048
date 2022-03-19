/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_center.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:02:35 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 18:02:47 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../2048.h"

void	ft_print_center(t_vars *vars, char *str)
{
	int	len;
	int	x;

	len = ft_strlen(str);
	x = (vars->nb_char_cols - len) / 2;
	mvprintw(vars->actual_cursor_line, x, "%s", str);
}