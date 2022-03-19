# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 00:10:11 by nlafarge          #+#    #+#              #
#    Updated: 2022/03/19 17:07:28 by nlafarge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 2048
CC = gcc
RM = rm -rf
CFLAGS = -lncurses -Wall -Wextra -Werror

MENUS =	srcs/menus/ft_start_menu.c \
		srcs/menus/ft_select_menu.c

GAME = srcs/game/ft_launch_game.c

CORE = srcs/core/ft_keypress.c

LEADERBOARD = srcs/leaderboard/ft_leaderboard.c

LIB = 	srcs/lib/ft_debug.c \
		srcs/lib/ft_init_struct.c \
		srcs/lib/ft_get_win_size.c \
		srcs/lib/ft_strlen.c \
		srcs/lib/ft_break_line.c \
		srcs/lib/ft_break_lines.c \
		srcs/lib/ft_clear.c \
		srcs/lib/ft_vertical_align.c

SRCS = srcs/main.c \
		${LIB} \
		${MENUS} \
		${CORE} \
		${GAME} \
		${LEADERBOARD}

OBJS = ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:
	make ${NAME}

${NAME}: ${OBJS} 2048.h
		${CC} -o ${NAME} ${OBJS} ${CFLAGS}

clean:
	${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

.PHONY: clean all fclean re