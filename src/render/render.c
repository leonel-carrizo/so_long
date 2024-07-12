/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:45:07 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/29 15:18:16 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* Draws an image at the specified position */
void	draw_tile(t_game *game, void *img, int x, int y)
{
	char	*moves;

	moves = ft_itoa(game->player.n_moves);
	mlx_put_image_to_window(
		game->mlx, game->win, img, x * TILE_SIZE, y * TILE_SIZE);
	mlx_string_put(game->mlx, game->win, 5, 20, MOVES_COLOR, "Moves:");
	mlx_string_put(game->mlx, game->win, 42, 21, MOVES_COLOR, moves);
	free(moves);
}

/* Draws the current tile based on its type */
void	draw_current_tile(t_game *game, int x, int y)
{
	if (game->map.tiles[y][x] == WALL)
	{
		init_wall(game, x, y);
		draw_tile(game, game->img_wall, x, y);
	}
	else if (game->map.tiles[y][x] == PLAYER)
	{
		init_player_start(game, x, y);
		draw_tile(game, game->img_player, x, y);
	}
	else if (game->map.tiles[y][x] == COLLECTIBLE)
		draw_tile(game, game->img_collect, x, y);
	else if (game->map.tiles[y][x] == MAP_EXIT)
		draw_tile(game, game->img_exit, x, y);
	else if (game->map.tiles[y][x] == EMPTY_SPACE)
	{
		if (game->map.start.bussy == 0)
			draw_tile(game, game->img_start,
				game->map.start.pos.x,
				game->map.start.pos.y);
		draw_tile(game, game->img_floor, x, y);
	}
}

/* Draw the entire map */
void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			draw_current_tile(game, x, y);
			x++;
		}
		y++;
	}
}
