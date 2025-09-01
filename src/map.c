#include "so_long.h"

static char *read_file(char *file)
{
    int fd;
    char *line;
    char *tmp;
    char *map_str;

    fd = open(file, O_RDONLY)
    if (fd < 0)
        error_exit("ERRO: NÂO FOI POSSOVEL ABRIR O MAPA");
    map_str = ft_strdup("");
    while (line)
    {
        tmp = ft_strjoin(map_str, line);
        free(map_str);
        free(line);
        map_str = tmp;
        get_next_line(fd);
    }
    close(fd);
    return(map_str);
}

void    read_map(t_game *game, char *file)
{
    char    *map_str;
    int i;

    map_str = read_file(file);
    game->map = ft_split(map_str, '\n')
    free(map_str);
    if (!game->map || !game->map[0])
        error_exit("ERRO: MAPA INVÁLIDO")
    i = 0;
    while (game->map[i])
        i++;
    game->height = i
    game->width = ft_strlen(game->map[0]);
}
