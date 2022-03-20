/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokino <tokino@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 06:18:12 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 11:40:25 by tokino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"
#include "board.h"
#include "board_movement.h"
#include "randomizer.h"
#include "check_board_status.h"

void handle_arrow(int direction, t_game *game)
{
	board_move(direction, game);
	if (game->board.has_changed)
	{
		generate_random_number_in_random_empty_tile(game);
		check_board_status(game);
	}
	// TODO : Check victory or defeat ?
}

void print_tile_background(t_game *game, t_tile *tile)
{
	for (int line = 0; line < game->board.tile_height; line++)
	{
		move(	tile->line_idx * (game->board.tile_height + 1) + 1 + line, \
				tile->col_idx * (game->board.tile_width + 1) + 1);
		hline(' ', game->board.tile_width);
	}
}

void print_tile_value(t_game *game, t_tile *tile)
{
	if (tile->value != 0)
	{
		if (ft_is_ascii_possible(game))
			ft_print_tile_ascii(game, tile);
		else
		{
			mvprintw(	tile->line_idx * (game->board.tile_height +1) + game->board.tile_height / 2, \
					tile->col_idx * (game->board.tile_width + 1) + game->board.tile_width / 2, \
					ft_itoa(tile->value));
		}
	}
}

void print_tile_content(t_game *game, t_tile *tile)
{
	attron(COLOR_PAIR(tile->value));
	attron(A_BOLD);
	print_tile_background(game, tile);
	print_tile_value(game, tile);
	attroff(A_BOLD);
	attroff(COLOR_PAIR(tile->value));
}

void print_tiles_content(t_game *game)
{
	for (int line = 0; line < game->board.line_nb; line++)
	{
		for (int col = 0; col < game->board.col_nb; col++)
		{
			print_tile_content(game, &game->board.tiles[line][col]);
		}
	}
}

void	ft_game_loop(t_game *game)
{
	game->key = 0; // à retenir qu'il est pas init
	while(1) {
		clear();
		update_board(game);

		if (game->key == ESC)
			break;

		switch (game->key)
		{
		case 410: // resize window
			break;
		case KEY_UP:
		case KEY_DOWN:
		case KEY_LEFT:
		case KEY_RIGHT:
			handle_arrow(game->key, game);
			break;
		default:
			// mvprintw(10, 1, "Character pressed is = %d Hopefully it can be printed as '%c'", c, c);
			break;
		}

		if (game->board.game_status == WIN || game->board.game_status == LOST)
			break;

		ft_get_max_size_tile(game);

		print_board(game);
		print_tiles_content(game);

		// sprintf(msg, "Game status = %d", board.game_status);
		// mvprintw(1, 1, msg); // Message de debug temporaire	
		// sprintf(msg, "Tile_width = %d", board.tile_width);
		// mvprintw(1, 1, msg); // Message de debug temporaire	
		// sprintf(msg, "Tile_heigth = %d", board.tile_height);
		// mvprintw(2, 1, msg); // Message de debug temporaire	
		// sprintf(msg, "COLS = %d, LINES = %d", COLS, LINES);
		// mvprintw(3, 1, msg); // Message de debug temporaire
		// sprintf(msg, "board has changed ? %d", board.has_changed);
		// mvprintw(4, 1, msg); // Message de debug temporaire

		refresh();
		game->key = getch();
	}

	if (game->board.game_status == WIN)
		ft_win_menu(game);
	else if (game->board.game_status == KEEP_PLAYING)
		ft_win_menu(game);
	else if (game->board.game_status == LOST)
		ft_lost_menu(game);
}