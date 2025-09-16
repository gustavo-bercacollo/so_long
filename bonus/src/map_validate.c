/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:30:53 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/14 20:57:54 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	validate_map(t_game *game)
{
	if (!game->map)
	{
		printf("Erro no mapa!\n");
		return (0);
	}
	if (!is_rectangular(game))
	{
		printf("Error\nMap is not rectangular\n");
		return (0);
	}
	if (!is_surrounded_by_walls(game))
	{
		printf("Error\nMap is not surrounded by walls\n");
		return (0);
	}
	if (!is_validate_path(game))
	{
		printf("Error\nIs impossible win this game\n");
		return (0);
	}
	return (1);
}

int	validate_characteres(t_game *game)
{
	if (!has_one_player(game))
	{
		printf("Error\nMap must have exactly one player\n");
		return (0);
	}
	if (!has_one_exit(game))
	{
		printf("Error\nMap must have exactly one exit\n");
		return (0);
	}
	if (!has_collectibles(game))
	{
		printf("Error\nMap must have at least one collectible\n");
		return (0);
	}
	if (!has_only_valid_characters(game))
	{
		printf("Error\nInvalid character in map\n");
		return (0);
	}
	return (1);
}

int	validate_map_and_characteres(t_game *game)
{
	if (!validate_map(game))
		return (0);
	if (!validate_characteres(game))
		return (0);
	return (1);
}
