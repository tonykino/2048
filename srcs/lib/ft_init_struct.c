/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokino <tokino@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 01:54:55 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 12:23:24 by tokino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"
#include "file_scoring.h"

int	ft_init_struct(t_game *game)
{
	game->nb_char_lines = 0;
	game->nb_char_cols = 0;
	game->key = 0;
	game->actual_cursor_line = 0;
	game->selected_menu_pos = 0;
	game->game_size = 0;
	return (get_scores_from_file(&game->scores));
}
