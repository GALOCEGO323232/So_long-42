#include "../inc/so_long.h"

static void	switch_frame(t_game *game)
{
	if (game->player_frame == 0)
		game->player_frame = 1;
	else
		game->player_frame = 0;
}

int	handle_input(int key, t_game *game)
{
	int	moved = 0;

	if (key == 119) // W
		moved = move_up(game);
	else if (key == 115) // S
		moved = move_down(game);
	else if (key == 97) // A
		moved = move_left(game);
	else if (key == 100) // D
		moved = move_right(game);
	else if (key == 65307 || key == 120) // ESC
		close_game(game);

	if (moved)
		switch_frame(game);

	return (0);
}



