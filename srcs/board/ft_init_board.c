/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 05:01:17 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 05:37:16 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"
#include "board.h"

static void _init_tile(t_tile *tile, int line, int col)
{
	tile->line_idx = line;
	tile->col_idx = col;
	tile->value = 0;
}

void	ft_init_board(t_game *game)
{
	game->board.tile_nb = game->board.col_nb * game->board.line_nb;
	game->board.tiles = ft_calloc(game->board.line_nb, sizeof(t_tile *)); // Todo : Protéger les mallocs
	for (int i = 0; i < game->board.line_nb; i++)
	{
		game->board.tiles[i] = ft_calloc(game->board.col_nb, sizeof(t_tile)); // Todo : Protéger les mallocs
	}
	game->board.tile_width = (COLS - game->board.col_nb - 1) / game->board.col_nb;
	game->board.tile_height = (LINES - game->board.line_nb - 1) / game->board.line_nb;

	for (int line = 0; line < game->board.line_nb; line++)
	{
		for (int col = 0; col < game->board.col_nb; col++)
		{
			_init_tile(&game->board.tiles[line][col], line, col);
		}
	}
}