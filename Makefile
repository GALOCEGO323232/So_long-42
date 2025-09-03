NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLX = -lmlx -framework OpenGL -framework AppKit

SRCS = so_long.c map.c draw_map.c sprites.c move.c handle.c events.c utils.c file_to_image.c
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
