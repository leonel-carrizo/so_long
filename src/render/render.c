/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:45:07 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/21 13:01:27 by lcarrizo         ###    ###london.com    */
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
	mlx_string_put(game->mlx, game->win, 5, 20, 0x00FFD500, "Moves:");
	mlx_string_put(game->mlx, game->win, 42, 21, 0x00FFD500, moves);
	free(moves);
}

/* Draws the current tile based on its type */
void	draw_current_tile(t_game *game, int x, int y)
{
	if (game->map.tiles[y][x] == '1')
	{
		init_wall(game, x, y);
		draw_tile(game, game->img_wall, x, y);
	}
	else if (game->map.tiles[y][x] == 'P')
		draw_tile(game, game->img_player, x, y);
	else if (game->map.tiles[y][x] == 'C')
		draw_tile(game, game->img_collect, x, y);
	else if (game->map.tiles[y][x] == 'E')
		draw_tile(game, game->img_exit, x, y);
	else
		draw_tile(game, game->img_floor, x, y);
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
