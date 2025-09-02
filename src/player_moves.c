#include "so_long.h"

void	move_up(t_game *game)
{
	game->y--;
	game->player_dir = DIR_UP;
}

void	move_down(t_game *game)
{
	game->y++;
	game->player_dir = DIR_DOWN;
}

void	move_left(t_game *game)
{
	game->x--;
	game->player_dir = DIR_LEFT;
}

void	move_right(t_game *game)
{
	game->x++;
	game->player_dir = DIR_RIGHT;
}
