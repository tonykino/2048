/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 00:29:42 by nlafarge          #+#    #+#             */
/*   Updated: 2022/03/19 18:15:16 by nlafarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEUX_MILLE_QUARANTE_HUIT
# define DEUX_MILLE_QUARANTE_HUIT

// # include <stdio.h>, pas besoin de l'inclure, elle l'est implicitement par ncurses.h
# include <ncurses.h>
# include <stdlib.h>

# define ESC 27
# define UP 259
# define DOWN 258
# define LEFT 260
# define RIGHT 261
# define ENTER 10

typedef	struct s_vars
{
	int		nb_char_lines;
	int		nb_char_cols;
	int		actual_cursor_line;
	int		key;
	int		selected_menu_pos;
}	t_vars;

/*
	MAIN
*/
int		main();

/*
	MENUS
*/
void	ft_start_menu(t_vars *vars);
void	ft_size_menu(t_vars *vars);
int		ft_select_menu(int move, int current_pos, int menu_size);

/*
	CORE
*/
int		ft_is_left_key(t_vars *vars);
int		ft_is_right_key(t_vars *vars);
int		ft_is_up_key(t_vars *vars);
int		ft_is_down_key(t_vars *vars);
int		ft_is_enter_key(t_vars *vars);
int		ft_is_esc_key(t_vars *vars);

/*
	GAME
*/
void	ft_launch_game(t_vars *vars);

/*
	LEADERBOARD
*/
void	ft_leaderboard(t_vars *vars);

/*
	LIB
*/
void	ft_debug(t_vars *vars);
void	ft_init_struct(t_vars *vars);
void	ft_get_win_size(t_vars *vars);
int		ft_strlen(char *str);
void	ft_break_line(t_vars *vars);
void	ft_break_lines(t_vars *vars, int nb_breaks);
void	ft_clear(t_vars *vars);
void	ft_vertical_align(t_vars *vars, int element_height);
void	ft_print_center(t_vars *vars, char *str);

#endif