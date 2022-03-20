/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 06:18:12 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 07:13:08 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

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