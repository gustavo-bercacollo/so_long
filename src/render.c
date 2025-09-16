/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:31:50 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/14 20:50:59 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

void	render_grass(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
			mlx_image_to_window(game->mlx, game->images.grass, x * TILE_SIZE, y
				* TILE_SIZE);
	}
}

static void	render_element(t_game *game, char c, int x, int y)
{
	if (c == '1')
		mlx_image_to_window(game->mlx, game->images.wall, x * TILE_SIZE, y
			* TILE_SIZE);
	else if (c == 'C')
		mlx_image_to_window(game->mlx, game->images.collectible, x * TILE_SIZE,
			y * TILE_SIZE);
	else if (c == 'E')
		mlx_image_to_window(game->mlx, game->images.exit, x * TILE_SIZE, y
			* TILE_SIZE);
}

static void	render_basic_elements(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
			render_element(game, game->map->grid[y][x], x, y);
	}
}

void	render_player(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = -1;
	while (++y < game->map->height)
	{
		game->textures.player = NULL;
		x = -1;
		while (++x < game->map->width)
		{
			c = game->map->grid[y][x];
			if (c == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				mlx_image_to_window(game->mlx, game->images.player, x
					* TILE_SIZE, y * TILE_SIZE);
			}
		}
	}
}

void	render_map(t_game *game)
{
	render_grass(game);
	render_player(game);
	render_basic_elements(game);
}
