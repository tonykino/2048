/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 00:28:50 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 13:46:29 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../2048.h"

int	main()
{
	t_vars	vars;

	ft_init_struct(&vars);
	initscr();
	clear(); // Clear the screen upfront to be shure we start with a blanck slate
	noecho(); // So that getch() does not print on the screen by default
	cbreak(); // So that the program does not wait for a newline or a carriage return and makes keyboard input directly accessible
	keypad(stdscr, TRUE); // Enables the keypad on the passed window, therefore handelling the multiple signals of the arrow keys

	/* Get the auto generated variables and make them accessible in the struct */
	vars.nb_char_lines = LINES;
	vars.nb_char_cols = COLS;

	ft_start_menu(&vars); // Launch the start menu

	endwin(); // Close the main window

	return 0;
}