/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:39:58 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/15 23:02:03 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_player	handle_input_player_position(mlx_key_data_t keydata, void *param)
{
	t_game		*game;
	t_player	new_pos;

	game = (t_game *)param;
	new_pos = game->player;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_game(game);
	if ((keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		&& is_wasd(keydata))
	{
		if (keydata.key == MLX_KEY_W)
			new_pos.y--;
		else if (keydata.key == MLX_KEY_S)
			new_pos.y++;
		else if (keydata.key == MLX_KEY_A)
			new_pos.x--;
		else if (keydata.key == MLX_KEY_D)
			new_pos.x++;
	}
	return (new_pos);
}

static void	disable_collectible(t_game *game, int loc_y, int loc_x)
{
	size_t	i;

	game->map->grid[loc_y][loc_x] = '0';
	i = 0;
	while (i < game->images.collectible->count)
	{
		if (game->images.collectible->instances[i].x == loc_x * TILE_SIZE
			&& game->images.collectible->instances[i].y == loc_y * TILE_SIZE)
		{
			game->images.collectible->instances[i].enabled = false;
			break ;
		}
		i++;
	}
}

static void	update_player_interactions(t_game *game, t_player pos,
		mlx_key_data_t keydata)
{
	if (!is_exit(game, pos.y, pos.x))
	{
		game->images.player->instances[0].x = pos.x * TILE_SIZE;
		game->images.player->instances[0].y = pos.y * TILE_SIZE;
	}
	if (is_collectible(game, pos.y, pos.x))
		disable_collectible(game, pos.y, pos.x);
	if (is_exit(game, pos.y, pos.x) && all_collectibles_is_caught(game))
		close_game(game);
	if (is_enemy(game, pos.y, pos.x))
		close_game(game);
	if ((keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		&& is_wasd(keydata))
	{
		game->moves++;
		printf("Move: %d\n", game->moves);
		draw_moves(game);
	}
}

void	handle_player(mlx_key_data_t keydata, void *param)
{
	t_game		*game;
	t_player	pos;

	game = (t_game *)param;
	pos = handle_input_player_position(keydata, game);
	if (!is_wall(game, pos.y, pos.x))
	{
		game->player = pos;
		update_player_interactions(game, pos, keydata);
	}
}
