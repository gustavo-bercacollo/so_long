/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:46:22 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/15 23:16:50 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	chase_player(t_game *game, int dx, int dy)
{
	if (abs(dx) > abs(dy))
	{
		if (dx > 0 && !is_wall(game, game->enemy.y, game->enemy.x + 1))
			game->enemy.x++;
		else if (dx < 0 && !is_wall(game, game->enemy.y, game->enemy.x - 1))
			game->enemy.x--;
	}
	else
	{
		if (dy > 0 && !is_wall(game, game->enemy.y + 1, game->enemy.x))
			game->enemy.y++;
		else if (dy < 0 && !is_wall(game, game->enemy.y - 1, game->enemy.x))
			game->enemy.y--;
	}
}

void	update_enemy(void *param)
{
	static int	ticks = 0;
	t_game		*game;
	int			dx;
	int			dy;

	game = (t_game *)param;
	ticks++;
	if (ticks % 15 != 0)
		return ;
	dx = game->player.x - game->enemy.x;
	dy = game->player.y - game->enemy.y;
	chase_player(game, dx, dy);
	game->images.farmer->instances[0].x = game->enemy.x * TILE_SIZE;
	game->images.farmer->instances[0].y = game->enemy.y * TILE_SIZE;
	if (game->enemy.x == game->player.x && game->enemy.y == game->player.y)
		close_game(game);
}
