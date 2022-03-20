/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaure <afaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:17:18 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/20 18:57:44 by afaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"
#include "time.h"
#include "colors.h"

// #define COLOR_BLACK	0
// #define COLOR_RED	1
// #define COLOR_GREEN	2
// #define COLOR_YELLOW	3
// #define COLOR_BLUE	4
// #define COLOR_MAGENTA	5
// #define COLOR_CYAN	6
// #define COLOR_WHITE	7

int nrgb(int color)
{
	return (1000 * color / 255);
}
void init_colors()
{
	start_color();
	init_color(COLOR_BLACK, nrgb(250), nrgb(248), nrgb(239));
	init_color(COLOR_BORDER, nrgb(187), nrgb(173), nrgb(160));
	init_color(COLOR_WHITE, nrgb(119), nrgb(110), nrgb(100));

	init_color(GLOBAL_BG, nrgb(250), nrgb(248), nrgb(239));
	init_color(GLOBAL_FG, nrgb(119), nrgb(110), nrgb(100));
	init_color(TILE_BG, nrgb(205), nrgb(193), nrgb(180));
	init_color(TILE_FG, nrgb(249), nrgb(246), nrgb(242));
	init_color(TILE_2, nrgb(238), nrgb(228), nrgb(218));
	init_color(TILE_4, nrgb(238), nrgb(225), nrgb(201));
	init_color(TILE_8, nrgb(243), nrgb(178), nrgb(122));
	init_color(TILE_16, nrgb(246), nrgb(150), nrgb(100));
	init_color(TILE_32, nrgb(247), nrgb(124), nrgb(95));
	init_color(TILE_64, nrgb(247), nrgb(95), nrgb(59));
	init_color(TILE_128, nrgb(237), nrgb(208), nrgb(115));

	init_pair(BORDER_PAIR, COLOR_BORDER, COLOR_BORDER);
	init_pair(VALUE0_PAIR, TILE_BG, TILE_BG);
	init_pair(VALUE2_PAIR, GLOBAL_FG, TILE_2);
	init_pair(VALUE4_PAIR, GLOBAL_FG, TILE_4);
	init_pair(VALUE8_PAIR, TILE_FG, TILE_8);
	init_pair(VALUE16_PAIR, TILE_FG, TILE_16);
	init_pair(VALUE32_PAIR, TILE_FG, TILE_32);
	init_pair(VALUE64_PAIR, TILE_FG, TILE_64);
	init_pair(VALUE128_PAIR, TILE_FG, TILE_128);
	init_pair(VALUE256_PAIR, TILE_FG, TILE_256);
	init_pair(VALUE512_PAIR, TILE_FG, TILE_512);
}

int ft_init(t_game *game)
{
	srand(time(NULL));
	initscr(); // Initialize curses library
	noecho();  // Do not display caracters from keyboard input
	init_colors();
	curs_set(0);		  // Make the cursor invisible
	cbreak();			  // Description of cbreak, noecho and nonl : https://manpages.debian.org/bullseye/ncurses-doc/nonl.3ncurses.en.html
	keypad(stdscr, TRUE); // enable arrow keys // necessary ?? A priori oui sinon les fleches envoient 3 signaux
	signal(SIGINT, signal_handler);
	signal_global = 1;
	return (ft_init_struct(game)); // Init our main struct
}
