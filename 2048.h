/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 00:29:42 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 13:07:10 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEUX_MILLE_QUARANTE_HUIT
# define DEUX_MILLE_QUARANTE_HUIT

// # include <stdio.h>, pas besoin de l'inclure, elle l'est implicitement par ncurses.h
# include <ncurses.h>
# include <stdlib.h>

# define ESC 27
# define UP 65
# define DOWN 66
# define LEFT 68
# define RIGHT 67

typedef	struct s_vars
{
	int		nb_char_lines;
	int		nb_char_cols;
	int		key;
}	t_vars;

/*
	MAIN
*/
int		main();

/*
	MENUS
*/
void	ft_start_menu(t_vars *vars);

/*
	LIB
*/
void	ft_debug(t_vars *vars);
void	ft_init_struct(t_vars *vars);

#endif