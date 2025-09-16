/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 22:09:50 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/14 20:57:33 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	free_image_and_set_null(t_game *game)
{
	if (game->images.grass)
		mlx_delete_image(game->mlx, game->images.grass);
	if (game->images.wall)
		mlx_delete_image(game->mlx, game->images.wall);
	if (game->images.collectible)
		mlx_delete_image(game->mlx, game->images.collectible);
	if (game->images.exit)
		mlx_delete_image(game->mlx, game->images.exit);
	if (game->images.player)
		mlx_delete_image(game->mlx, game->images.player);
	if (game->images.farmer)
		mlx_delete_image(game->mlx, game->images.farmer);
	game->images.grass = NULL;
	game->images.wall = NULL;
	game->images.collectible = NULL;
	game->images.exit = NULL;
	game->images.player = NULL;
	game->images.farmer = NULL;
}

static void	free_texture_and_set_null(t_game *game)
{
	if (game->textures.grass)
		mlx_delete_texture(game->textures.grass);
	if (game->textures.wall)
		mlx_delete_texture(game->textures.wall);
	if (game->textures.collectible)
		mlx_delete_texture(game->textures.collectible);
	if (game->textures.exit)
		mlx_delete_texture(game->textures.exit);
	if (game->textures.player)
		mlx_delete_texture(game->textures.player);
	if (game->textures.farmer)
		mlx_delete_texture(game->textures.farmer);
	game->textures.grass = NULL;
	game->textures.wall = NULL;
	game->textures.collectible = NULL;
	game->textures.exit = NULL;
	game->textures.player = NULL;
	game->textures.farmer = NULL;
}

void	free_assets(t_game *game)
{
	free_image_and_set_null(game);
	free_texture_and_set_null(game);
}

void	close_game(t_game *game)
{
	mlx_close_window(game->mlx);
	free_assets(game);
	mlx_terminate(game->mlx);
	free_map(game->map);
	free(game);
	exit(0);
}
