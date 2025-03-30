# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/29 16:50:48 by menwu             #+#    #+#              #
#    Updated: 2025/03/29 20:33:52 by menwu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
MLX_FLAGS = -Lminilibx-linux -lmlx -L/usr/lib -L/usr/lib/X11 -lXext -lX11


INCLUDES = -I/usr/include -I/usr/include/X11 -I$(MLX_DIR)
SANITIZE = -fsanitize=address
RM = rm -rf
NAME = so_long

SRC_DIR = src
BONUS_DIR = bonus
RANKING = rank
GNL_DIR = get_next_line

SRC = src/0_check_elements.c src/0_ft_calloc.c src/0_ft_itoa.c src/0_map_error.c \
	src/0_map_parsing.c src/0_map_parsing_util.c src/1_check_exit.c src/1_check_game_over.c \
	src/1_init_assets.c src/1_init_play.c src/2_end_game.c src/2_enemy_sprint.c \
	src/2_key_press.c src/2_key_press_util.c src/2_so_long.c src/2_update_status.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
BONUS_SRC = bonus/0_check_elements_bonus.c bonus/0_ft_calloc_bonus.c bonus/0_ft_itoa_bonus.c \
		bonus/0_map_error_bonus.c bonus/0_map_parsing_bonus.c bonus/0_map_parsing_util_bonus.c \
		bonus/1_check_exit_bonus.c bonus/1_check_game_over_bonus.c bonus/1_init_assets_bonus.c \
		bonus/1_init_play_bonus.c bonus/2_end_game_bonus.c bonus/2_enemy_sprint_bonus.c \
		bonus/2_key_press_bonus.c bonus/2_key_press_util_bonus.c bonus/2_so_long_bonus.c \
		bonus/2_update_status_bonus.c get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

RANK_SRC = rank/0_ft_calloc.c rank/0_ft_itoa.c rank/0_map_error.c rank/0_map_parsing.c \
		rank/0_map_parsing_util.c rank/1_check_exit.c rank/1_check_game_over.c rank/1_init_assets.c \
		rank/1_init_play.c rank/2_end_game.c rank/2_enemy_sprint.c rank/2_key_press.c \
		rank/2_key_press_util.c rank/2_so_long.c rank/2_update_status.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)
RANK_OBJS = $(RANK_SRC:.c=.o)


all: configure $(NAME)  

configure:
	@cd $(MLX_DIR) && ./configure 

$(NAME): $(OBJS) Makefile so_long.h
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(SANITIZE)

bonus: configure .bonus

.bonus: $(BONUS_OBJS) Makefile so_long_bonus.h
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJS) $(MLX_FLAGS) $(SANITIZE)
	touch .bonus

rank: configure .rank

.rank: $(RANK_OBJS) Makefile so_long_rank.h
	$(CC) $(CFLAGS) -o $(NAME) $(RANK_OBJS) $(MLX_FLAGS) $(SANITIZE)
	touch .rank

%.o: %.c Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean: 
	$(RM) $(OBJS) $(BONUS_OBJS) $(RANK_OBJS)
	@cd $(MLX_DIR) && ./configure clean

fclean: clean
	$(RM) $(NAME) .bonus .rank

re: fclean all

.PHONY: all bonus clean fclean re
