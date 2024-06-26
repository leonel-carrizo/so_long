/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:09:32 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/29 15:18:23 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* Initializes the background images
 to show the motion counter on the screen */
void	init_wall(t_game *game, int x, int y)
{
	int	width;
	int	height;

	if ((y == 0 && x == 0) && (game->map.tiles[y][x] == WALL))
	{
		mlx_destroy_image(game->mlx, game->img_wall);
		game->img_wall = mlx_xpm_file_to_image(game->mlx,
				BLOCK_0_IMG, &width, &height);
	}
	else if ((y == 0 && x == 1) && (game->map.tiles[y][x] == WALL))
	{
		mlx_destroy_image(game->mlx, game->img_wall);
		game->img_wall = mlx_xpm_file_to_image(game->mlx,
				BLOCK_1_IMG, &width, &height);
	}
	else
	{
		mlx_destroy_image(game->mlx, game->img_wall);
		game->img_wall = mlx_xpm_file_to_image(game->mlx,
				WALL_5_IMG, &width, &height);
	}
}
