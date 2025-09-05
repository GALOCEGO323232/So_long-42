NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -Lmlx -lmlx -lXext -lX11 -lm -lz
SRCS = src/so_long.c src/movements.c src/read_map.c src/draw_map.c src/sprites.c src/player_moves.c src/handle.c src/events.c src/utils.c src/file_to_image.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I./ -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "Compilando libft..."
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
