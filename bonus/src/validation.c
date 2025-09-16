/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:37:57 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/14 20:58:47 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_wall(t_game *game, int loc_y, int loc_x)
{
	if (game->map->grid[loc_y][loc_x] == '1')
		return (1);
	return (0);
}

int	is_collectible(t_game *game, int loc_y, int loc_x)
{
	if (game->map->grid[loc_y][loc_x] == 'C')
		return (1);
	return (0);
}

int	is_exit(t_game *game, int loc_y, int loc_x)
{
	if (game->map->grid[loc_y][loc_x] == 'E')
		return (1);
	return (0);
}

int	is_enemy(t_game *game, int loc_y, int loc_x)
{
	if (game->map->grid[loc_y][loc_x] == 'F')
		return (1);
	return (0);
}

int	all_collectibles_is_caught(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
