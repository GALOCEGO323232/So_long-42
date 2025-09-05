#include "../inc/so_long.h"

static char *read_file(char *file)
{
    int fd;
    char *line;
    char *tmp;
    char *map_str;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        error_exit("ERRO: NAO FOI POSSIVEL ABRIR O MAPA");

    map_str = ft_strdup(""); // string inicial vazia
    if (!map_str)
        error_exit("ERRO: FALHA AO ALOCAR MEMORIA");

    while ((line = get_next_line(fd)) != NULL)
    {
        tmp = ft_strjoin(map_str, line);
        if (!tmp)
            error_exit("ERRO: FALHA AO CONCATENAR LINHAS");
        free(map_str);
        free(line);
        map_str = tmp;
    }

    close(fd);
    return map_str;
}

void    read_map(t_game *game, char *file)
{
    char    *map_str;
    int i;

    map_str = read_file(file);
    game->map = ft_split(map_str, '\n');
    free(map_str);
    if (!game->map || !game->map[0])
        error_exit("ERRO: MAPA INVALIDO");
    i = 0;
    while (game->map[i])
        i++;
    game->height = i;
    game->width = ft_strlen(game->map[0]);
}

void	init_player_pos(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->y = y;
				game->x = x;
				game->p++;
			}
			else if (game->map[y][x] == 'C')
				game->c++;
			else if (game->map[y][x] == 'E')
				game->e++;
			x++;
		}
		y++;
	}
	if (game->p != 1 || game->e == 0 || game->c == 0)
		error_exit("Mapa inválido: player, saída ou coletáveis incorretos");
}
