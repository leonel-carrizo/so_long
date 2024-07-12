/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:08:48 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/07/12 18:09:25 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* 	Checks if the player is on the start door,	changes the sprite image and
	changes the state from start to busy */
void	init_player_start(t_game *game, int x, int y)
{
	int	width;
	int	height;

	if (x == game->map.start.pos.x
		&& y == game->map.start.pos.y)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				PLAYER_DOOR_START_IMG, &width, &height);
		game->map.start.bussy = 1;
	}
	else
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				PLAYER_FRONT_1_IMG, &width, &height);
		game->map.start.bussy = 0;
	}
}
