#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define TILE 60 // tamanho de cada bloco do mapa
# define IMG_PXL 60
# define DIR_UP     0
# define DIR_DOWN   1
# define DIR_LEFT   2
# define DIR_RIGHT  3

// --- Struct das imagens/sprites ---
typedef struct s_img
{
	void	*empty;          // chão vazio
	void	*collectible;    // coletável
	void	*wall;           // parede
	void	*exit;           // saída
	void	*player_left1;   // player esquerda quadro 1
	void	*player_right1;  // player direita quadro 1
	void	*player_up1;     // player cima quadro 1
	void	*player_down1;   // player baixo quadro 1
	void	*player_left2;   // player esquerda quadro 2 (animação)
	void	*player_right2;  // player direita quadro 2 (animação)
	void	*player_up2;     // player cima quadro 2 (animação)
	void	*player_down2;   // player baixo quadro 2 (animação)
	void	*enemy;          // inimigo
} t_img;

// --- Struct principal do jogo ---
typedef struct s_game
{
	// MLX e janela
	void	*mlx;    // ponteiro da conexão MLX
	void	*win;    // ponteiro da janela

	// Mapa
	char	**map;   // matriz 2D do mapa
	int		width;   // largura do mapa (colunas)
	int		height;  // altura do mapa (linhas)

	// Player / posições
	int		x;       // coluna do player
	int		y;       // linha do player
	int		player_dir; //posiçao do jogador no mapa
	int		player_frame;

	// Contadores
	int		moves;              // número de movimentos do player
	int		c;                  // total de coletáveis no mapa
	int		collected;          // coletáveis já coletados
	int		e;                  // total de saídas no mapa
	int		p;                  // total de players no mapa
	t_img	img; // sprites do jogo
} t_game;

void	read_map(t_game *game, char *file); // lê o mapa do arquivo
void	draw_map(t_game *game);            // desenha o mapa e o player
int		close_game(t_game *game);          // fecha o jogo
void	error_exit(char *msg);             // imprime mensagem de erro e sai
int handle_input(int key, t_game *game);
void    *dir_player(t_game *game);
void	move_up(t_game *game);//Movimentos do player
void	move_down(t_game *game);//Movimentos do player
void	move_left(t_game *game);//Movimentos do player
void	move_right(t_game *game); //Movimentos do player
void	file_to_image(t_game *map); //Para carregar as imagens de plyaer e outras

#endif