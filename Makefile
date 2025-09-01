NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX = -lmlx -framework OpenGL -framework AppKit
LIBFT = ./libft/libft.a

SRC = src/so_long.c src/map.c src/draw_map.c src/events.c src/utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all
