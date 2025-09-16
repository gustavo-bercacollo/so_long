/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 20:56:55 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/14 20:56:55 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define TILE_SIZE 32

# include "MLX42/MLX42.h"
# include "ft_non_standard/get_next_line.h"
# include "ft_non_standard/ft_non_standard.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* Struct Definitions */
typedef struct s_player
{
	int	y;
	int	x;
}	t_player;

typedef struct s_enemy
{
	int	x;
	int	y;
}	t_enemy;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_textures
{
	mlx_texture_t	*grass;
	mlx_texture_t	*wall;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
	mlx_texture_t	*farmer;
}	t_textures;

typedef struct s_images
{
	mlx_image_t	*grass;
	mlx_image_t	*wall;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
	mlx_image_t	*player;
	mlx_image_t	*farmer;
	mlx_image_t	*moves_img;
}	t_images;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		*map;
	t_textures	textures;
	t_images	images;
	t_player	player;
	t_enemy		enemy;
	int			moves;
}	t_game;

/* Window and MLX Initialization Functions */
mlx_t		*init_window(int width, int height);
int			init_textures(t_game *game);
int			init_images(t_game *game);
void		draw_moves(t_game *game);
void		update_enemy(void *param);

/* Map Handling and Rendering Functions */
t_map		*read_map(const char *filename);
void		render_map(t_game *game);
void		render_player(t_game *game);
void		render_grass(t_game *game);

/* Player Input and Game Logic Functions */
t_player	handle_input_player_position(mlx_key_data_t keydata, void *param);
void		handle_player(mlx_key_data_t keydata, void *param);
int			is_wall(t_game *game, int loc_y, int loc_x);
int			is_collectible(t_game *game, int loc_y, int loc_x);
int			is_exit(t_game *game, int loc_y, int loc_x);
int			is_enemy(t_game *game, int loc_y, int loc_x);
int			all_collectibles_is_caught(t_game *game);
int			is_wasd(mlx_key_data_t keydata); // Grouped with input handling

/* Map Validation Functions */
int			is_rectangular(t_game *game);
int			is_surrounded_by_walls(t_game *game);
int			has_one_player(t_game *game);
int			has_one_exit(t_game *game);
int			has_collectibles(t_game *game);
int			validate_characteres(t_game *game);
int			validate_map_and_characteres(t_game *game);
void		flood_fill(char **map, int y, int x, t_game *game);
int			is_validate_path(t_game *game);
int			validate_map(t_game *game);
int			has_only_valid_characters(t_game *game);

/* Memory Management and Cleanup Functions */
void		free_map(t_map *map);
void		free_assets(t_game *game);
void		free_copy(char **copy, int height);
char		**copy_map(t_game *game);
void		close_game(t_game *game);

/* Terminal Validations */
int			check_ber_extension(const char *filename);
t_map		*validate_and_read_map(int argc, char **argv);

#endif
