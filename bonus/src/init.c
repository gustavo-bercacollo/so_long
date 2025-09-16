/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:16:14 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/13 17:16:14 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

mlx_t	*init_window(int width, int height)
{
	int		window_width;
	int		window_height;
	mlx_t	*mlx;

	window_height = height * TILE_SIZE;
	window_width = width * TILE_SIZE;
	mlx = mlx_init(window_width, window_height, "So long", true);
	if (!mlx)
		return (NULL);
	return (mlx);
}

int	init_textures(t_game *game)
{
	game->textures.grass = mlx_load_png("textures/Grass2.png");
	game->textures.wall = mlx_load_png("textures/Oak_Tree.png");
	game->textures.collectible = mlx_load_png("textures/Carrot.png");
	game->textures.exit = mlx_load_png("textures/Hole.png");
	game->textures.player = mlx_load_png("textures/Player.png");
	game->textures.farmer = mlx_load_png("textures/Farmer.png");
	if (!game->textures.grass || !game->textures.wall
		|| !game->textures.collectible || !game->textures.exit
		|| !game->textures.player || !game->textures.farmer)
	{
		free_assets(game);
		return (1);
	}
	return (0);
}

int	init_images(t_game *game)
{
	game->images.grass = mlx_texture_to_image(game->mlx, game->textures.grass);
	game->images.wall = mlx_texture_to_image(game->mlx, game->textures.wall);
	game->images.collectible = mlx_texture_to_image(game->mlx,
			game->textures.collectible);
	game->images.exit = mlx_texture_to_image(game->mlx, game->textures.exit);
	game->images.player = mlx_texture_to_image(game->mlx,
			game->textures.player);
	game->images.farmer = mlx_texture_to_image(game->mlx,
			game->textures.farmer);
	game->images.moves_img = NULL;
	if (!game->images.grass || !game->images.wall || !game->images.collectible
		|| !game->images.exit || !game->images.player || !game->images.farmer)
	{
		free_assets(game);
		return (1);
	}
	return (0);
}
