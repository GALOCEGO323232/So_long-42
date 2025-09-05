#include "../inc/so_long.h"

int     close_game(t_game *game)
{
    int i;

    i = 0;
    while(i < game->height)
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
    game->map = NULL;
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return(0);
}
