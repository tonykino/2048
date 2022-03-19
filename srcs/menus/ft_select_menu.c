/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:32:24 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 16:37:38 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../2048.h"

int		ft_select_menu(int move, int current_pos, int menu_size)
{
	current_pos = current_pos + move;
	menu_size--; // Because the menu size is +1 of the array size

	if (current_pos > menu_size)
		current_pos = 0;
	else if (current_pos < 0)
		current_pos = menu_size;

	return (current_pos);
}