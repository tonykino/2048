/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 01:54:55 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 15:59:45 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../2048.h"

void	ft_init_struct(t_vars *vars)
{
	vars->nb_char_lines = 0;
	vars->nb_char_cols = 0;
	vars->key = 0;
	vars->actual_cursor_line = 0;
}