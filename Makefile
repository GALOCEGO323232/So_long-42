# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/07 16:04:52 by kgagliar          #+#    #+#              #
#    Updated: 2025/09/07 16:04:52 by kgagliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -Lmlx -lmlx -lXext -lX11 -lm -lz
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I./ -I$(LIBFT_DIR)

SRC_DIR = src
BONUS_DIR = bonus/src

SRCS = $(SRC_DIR)/so_long.c \
       $(SRC_DIR)/movements.c \
       $(SRC_DIR)/read_map.c \
       $(SRC_DIR)/draw_map.c \
       $(SRC_DIR)/sprites.c \
       $(SRC_DIR)/player_moves.c \
       $(SRC_DIR)/keyhook.c \
       $(SRC_DIR)/ft_free.c \
       $(SRC_DIR)/utils.c \
       $(SRC_DIR)/file_to_image.c \
       $(SRC_DIR)/valid_path.c \
       $(SRC_DIR)/valid_map.c

BONUS_SRCS = $(BONUS_DIR)/so_long_bonus.c \
             $(BONUS_DIR)/close_game_bonus.c \
             $(BONUS_DIR)/draw_map_bonus.c \
             $(BONUS_DIR)/enemies_bonus.c \
             $(BONUS_DIR)/file_to_image_bonus.c \
             $(BONUS_DIR)/free_game_bonus.c \
             $(BONUS_DIR)/keyhook_bonus.c \
             $(BONUS_DIR)/move_enemy_bonus.c \
             $(BONUS_DIR)/movements_bonus.c \
             $(BONUS_DIR)/player_moves_bonus.c \
             $(BONUS_DIR)/read_map_bonus.c \
             $(BONUS_DIR)/sprites_bonus.c \
             $(BONUS_DIR)/utils_bonus.c \
             $(BONUS_DIR)/valid_map_bonus.c \
             $(BONUS_DIR)/valid_path_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(BONUS_NAME)

$(LIBFT):
	@echo "Compiling libft..."
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(INCLUDES) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MLX) $(INCLUDES) -o $(BONUS_NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all
