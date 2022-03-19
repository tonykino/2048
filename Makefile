# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 00:10:11 by nlafarge          #+#    #+#              #
#    Updated: 2022/03/19 01:56:01 by nlafarge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 2048
CC = gcc
RM = rm -rf
CFLAGS = -lncurses -Wall -Wextra -Werror

LIB = 	srcs/lib/ft_debug.c \
		srcs/lib/ft_init_struct.c

SRCS = srcs/main.c \
		${LIB}

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