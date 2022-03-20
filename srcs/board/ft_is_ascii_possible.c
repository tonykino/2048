/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_ascii_possible.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 07:21:27 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 07:28:17 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

int	ft_is_ascii_possible(t_game *game)
{
	int required_width = 3 * ft_numlen(game->max_size_tile);
	int required_height = 5;

	if (game->board.tile_width 	>= required_width && game->board.tile_height >= required_height)
		return (1);
	else
		return (0);
}