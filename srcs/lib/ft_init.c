/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaure <afaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:17:18 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 13:05:18 by afaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"
#include "time.h"

int	ft_init(t_game *game)
{
	srand(time(NULL));
	initscr(); // Initialize curses library
	noecho(); // Do not display caracters from keyboard input
	curs_set(0); // Make the cursor invisible
	cbreak();  // Description of cbreak, noecho and nonl : https://manpages.debian.org/bullseye/ncurses-doc/nonl.3ncurses.en.html
	keypad(stdscr, TRUE); // enable arrow keys // necessary ?? A priori oui sinon les fleches envoient 3 signaux
	return (ft_init_struct(game)); // Init our main struct
}
