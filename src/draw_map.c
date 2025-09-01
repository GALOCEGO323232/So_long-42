#include "so_long.h"

void    draw_map(t_game *game)
{
    int y;
    int x;
    void *img;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->map[y][x] == '1')
                img = game->img.wall;
            else if (y == game->y && x == game->x)
                img = game->img.player_down1;
            else
                img = game->img.empty;
            mlx_put_image_to_window(game->mlx, game->win, img, x * TILE, y * TILE);
            x++;    
        }
        y++;
    }
}
