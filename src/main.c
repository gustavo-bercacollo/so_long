/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:50:24 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/13 20:50:24 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

static int	init_validate_map_and_characteres(t_game *game, t_map *map)
{
	if (!validate_map_and_characteres(game))
	{
		free_map(map);
		free(game);
		return (1);
	}
	return (0);
}

static int	init_textures_and_imagens(t_game *game)
{
	if (init_textures(game) || init_images(game))
	{
		printf("Error to starting the assets!\n");
		mlx_terminate(game->mlx);
		free_map(game->map);
		free(game);
		return (1);
	}
	return (0);
}

static int	init_mlx(t_game *game)
{
	game->mlx = init_window(game->map->width, game->map->height);
	if (!game->mlx)
	{
		free_map(game->map);
		free(game);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_map	*map;

	map = validate_and_read_map(argc, argv);
	if (!map)
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (free_map(map), 1);
	game->map = map;
	game->moves = 0;
	if (init_validate_map_and_characteres(game, map) || init_mlx(game)
		|| init_textures_and_imagens(game))
		return (1);
	render_map(game);
	mlx_key_hook(game->mlx, handle_player, game);
	mlx_loop(game->mlx);
	close_game(game);
	return (0);
}
