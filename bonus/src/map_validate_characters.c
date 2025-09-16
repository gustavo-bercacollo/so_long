/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_characters.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:54:22 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/14 20:57:51 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	has_one_player(t_game *game)
{
	int	player;
	int	y;
	int	x;

	player = 0;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == 'P')
				player++;
			x++;
		}
		y++;
	}
	return (player == 1);
}

int	has_one_exit(t_game *game)
{
	int	exit;
	int	y;
	int	x;

	exit = 0;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == 'E')
				exit++;
			x++;
		}
		y++;
	}
	return (exit == 1);
}

int	has_collectibles(t_game *game)
{
	int	collectibles;
	int	y;
	int	x;

	collectibles = 0;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == 'C')
				collectibles++;
			x++;
		}
		y++;
	}
	return (collectibles > 1);
}

int	has_only_valid_characters(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			if (game->map->grid[y][x] != '1' && game->map->grid[y][x] != '0'
				&& game->map->grid[y][x] != 'C' && game->map->grid[y][x] != 'E'
				&& game->map->grid[y][x] != 'F' && game->map->grid[y][x] != 'P')
				return (0);
		}
	}
	return (1);
}
