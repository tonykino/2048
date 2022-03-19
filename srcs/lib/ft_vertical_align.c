/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical_align.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:43:05 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 16:44:48 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../2048.h"

void	ft_vertical_align(t_vars *vars, int element_height)
{
	int top_margin = (vars->nb_char_lines - element_height) / 2;
	ft_break_lines(vars, top_margin);
}