/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokino <tokino@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 01:54:55 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 22:37:37 by tokino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

void	ft_init_struct(t_vars *vars)
{
	vars->nb_char_lines = 0;
	vars->nb_char_cols = 0;
	vars->key = 0;
	vars->actual_cursor_line = 0;
	vars->selected_menu_pos = 0;
	vars->game_size = 0;
}