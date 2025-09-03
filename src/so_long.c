#include "so_long.h"

static void	init_game(t_game *game, char *map_file)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Erro ao iniciar MLX");
	game->win = mlx_new_window(game->mlx, 1000, 1000, "so_long");
	if (!game->win)
		error_exit("Erro ao criar janela");
	game->x = 0;
	game->y = 0;
	game->player_dir = DIR_DOWN;
	game->player_frame = 0;
	game->moves = 0;
	game->c = 0;
	game->collected = 0;
	game->e = 0;
	game->p = 0;
	read_map(game, map_file);
	file_to_image(game);
	draw_map(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Uso: ./so_long <mapa.ber>");
	init_game(&game, argv[1]);
	mlx_key_hook(game.win, handle_input, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}


