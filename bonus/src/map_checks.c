/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:32:09 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/14 20:57:46 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_rectangular(t_game *game)
{
	int	i;

	if (!game->map || !game->map->grid[0])
		return (0);
	i = 1;
	while (game->map->grid[i])
	{
		if (strlen(game->map->grid[i]) != (size_t)game->map->width)
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded_by_walls(t_game *game)
{
	int	y;
	int	x;

	x = 0;
	while (x < game->map->width)
	{
		if (game->map->grid[0][x] != '1' || game->map->grid[game->map->height
			- 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < game->map->height)
	{
		if (game->map->grid[y][0] != '1' || game->map->grid[y][game->map->width
			- 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

static void	set_player_position(t_game *game)
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
			}
		}
	}
}

int	is_validate_path(t_game *game)
{
	char		**copy;
	int			y;
	int			x;

	copy = copy_map(game);
	set_player_position(game);
	flood_fill(copy, game->player.y, game->player.x, game);
	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			if (copy[y][x] == 'C' || copy[y][x] == 'E')
			{
				free_copy(copy, game->map->height);
				return (0);
			}
		}
	}
	free_copy(copy, game->map->height);
	return (1);
}
