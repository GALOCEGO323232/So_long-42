#include "../inc/so_long.h"

void	init_game(t_game *game, char *map_file)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Erro ao iniciar MLX");
	read_map(game, map_file);
	game->c = 0;
	game->collected = 0;
	game->e = 0;
	game->p = 0;
	init_player_pos(game);
	game->win = mlx_new_window(game->mlx, game->width * TILE,
			game->height * TILE, "so_long");
	if (!game->win)
		error_exit("Erro ao criar janela");
	game->player_dir = DIR_DOWN;
	game->player_frame = 0;
	game->moves = 0;
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
