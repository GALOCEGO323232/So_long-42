#include "so_long.h"

static void	switch_frame(t_game *game)
{
	if (game->player_frame == 0)
		game->player_frame = 1;
	else
		game->player_frame = 0;
}

int	handle_input(int key, t_game *game)
{
	if (key == 119)//W
		move_up(game);
	else if (key == 115)//S
		move_down(game);
	else if (key == 97)//A
		move_left(game);
	else if (key == 100)//D
		move_right(game);
    else if (key == 65307)//ESC
        close_game(game);
	if (key == 119|| key == 115 || key == 97 || key == 100)
		switch_frame(game);
	return (0);
}
