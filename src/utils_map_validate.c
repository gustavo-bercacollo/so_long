/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 21:55:44 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/14 20:51:05 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

void	free_copy(char **copy, int height)
{
	int	i;

	i = 0;
	if (!copy)
		return ;
	while (i < height)
		free(copy[i++]);
	free(copy);
}

char	**copy_map(t_game *game)
{
	char	**copy;
	int		y;

	copy = malloc(sizeof(char *) * game->map->height);
	if (!copy)
		return (NULL);
	y = -1;
	while (++y < game->map->height)
	{
		copy[y] = strdup(game->map->grid[y]);
		if (!copy)
		{
			while (--y >= 0)
				free(copy[y]);
			free(copy);
			return (NULL);
		}
	}
	return (copy);
}

void	flood_fill(char **map, int y, int x, t_game *game)
{
	if (y < 0 || y >= game->map->height || x < 0 || x >= game->map->width)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'O'
		|| map[y][x] == 'U')
		return ;
	map[y][x] = 'U';
	flood_fill(map, y - 1, x, game);
	flood_fill(map, y + 1, x, game);
	flood_fill(map, y, x - 1, game);
	flood_fill(map, y, x + 1, game);
}

int	is_wasd(mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_A
		|| keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_D)
		return (1);
	return (0);
}
