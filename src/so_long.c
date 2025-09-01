#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("MAPA INVALIDO");
	game.mlx = mlx_init();
	read_map(&game, argv[1]);
	game.x = 1;
	game.y = 1;
	game.win = mlx_new_window(game.mlx, game.width * TILE,
			game.height * TILE, "so_long");
	draw_map(&game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}