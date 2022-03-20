# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlafarge <nlafarge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 00:10:11 by nlafarge          #+#    #+#              #
#    Updated: 2022/03/20 09:00:31 by nlafarge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = 2048
# CC = gcc
# RM = rm -rf
# CFLAGS = -lncurses -Wall -Wextra -Werror

# MENUS =	srcs/menus/ft_start_menu.c \
# 		srcs/menus/ft_select_menu.c \
# 		srcs/menus/ft_size_menu.c

# GAME = srcs/game/ft_launch_game.c

# CORE = srcs/core/ft_keypress.c

# LEADERBOARD = srcs/leaderboard/ft_leaderboard.c

# LIB = 	srcs/lib/ft_debug.c \
# 		srcs/lib/ft_init_struct.c \
# 		srcs/lib/ft_get_win_size.c \
# 		srcs/lib/ft_strlen.c \
# 		srcs/lib/ft_break_line.c \
# 		srcs/lib/ft_break_lines.c \
# 		srcs/lib/ft_clear.c \
# 		srcs/lib/ft_vertical_align.c \
# 		srcs/lib/ft_print_center.c

# SRCS = srcs/main.c \
# 		${LIB} \
# 		${MENUS} \
# 		${CORE} \
# 		${GAME} \
# 		${LEADERBOARD}

# OBJS = ${SRCS:.c=.o}

# .c.o:
# 	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# all:
# 	make ${NAME}

# ${NAME}: ${OBJS} 2048.h
# 		${CC} -o ${NAME} ${OBJS} ${CFLAGS}

# clean:
# 	${RM} ${OBJS}

# fclean:		clean
# 			${RM} ${NAME}

# re:		fclean all

# .PHONY: clean all fclean re


NAME    = 2048

SRC     = $(addprefix srcs/, \
				main.c \
				$(addprefix board/,			ft_is_ascii_possible.c ft_get_max_size_tile.c ft_init_board.c board.c board_movement.c check_board_status.c randomizer.c vector_conversions.c) \
				$(addprefix core/,			ft_keypress.c) \
				$(addprefix game/,  		ft_game_loop.c ft_launch_game.c) \
				$(addprefix leaderboard/, 	file_scoring.c  ft_leaderboard.c) \
				$(addprefix lib/, 			ft_print_title.c ft_too_small.c ft_init.c ft_break_line.c  ft_break_lines.c  ft_clear.c  ft_debug.c  ft_get_win_size.c  ft_init_struct.c  ft_print_center.c ft_vertical_align.c) \
				$(addprefix libft/, 		ft_numlen.c ft_atoi.c  ft_calloc.c  ft_isalnum.c  ft_isalpha.c  ft_isdigit.c  ft_isspace.c  ft_itoa.c  ft_putnbr_fd.c  ft_strdup.c  ft_strlcpy.c  ft_strlen.c  get_next_line.c  get_next_line_utils.c) \
				$(addprefix menus/, 		ft_lost_menu.c ft_win_menu.c	ft_select_menu.c  ft_size_menu.c  ft_start_menu.c) \
				$(addprefix tiles/,			ft_print_nb_ascii.c ft_print_tile_ascii.c))

# OBJDIR := obj
# OBJ     := $(addprefix $(OBJDIR)/, $(notdir $(SRC:.c=.o)))

# DEPDIR := $(OBJDIR)/.deps
# DEPFILES = $(addprefix $(DEPDIR)/, $(notdir $(SRC:.c=.d)))
# DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

CC       = cc
CFLAGS = $(CC) $(DEPFLAGS) -Iincludes #-Wall -Wextra -Werror

%.o : %.c

# $(OBJDIR)/%.o : %.c | $(OBJDIR) $(DEPDIR)
# 	$(CFLAGS) -c $< -o $@

all : $(NAME)


$(DEPFILES):

include $(DEPFILES)

$(NAME) : 
	$(CFLAGS) $(SRC) -o $(NAME) -lncurses


re : fclean all

clean :
	-rm -rf $(OBJDIR)

fclean : clean
	-rm -f $(NAME)

$(OBJDIR):
	@mkdir $(OBJDIR)

$(DEPDIR): | $(OBJDIR)
	@mkdir $(DEPDIR)


.PHONY: all re clean fclean