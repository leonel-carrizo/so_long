/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:42:10 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/01 14:44:09 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* Initialize game images */
void   init_images(t_game *game)
{
	int width;
	int height;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/images/wall1.xpm", &width, &height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "assets/images/floor1.xpm", &width, &height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "assets/images/player_front.xpm", &width, &height);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, "assets/images/coin1.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "assets/images/door_closed.xpm", &width, &height);
}

/* Initialize the game and load the map */
void	init_game(t_game *game, char *map_path)
{
	game->mlx = mlx_init();
	load_map(&game->map, map_path);
	game->win = mlx_new_window(game->mlx, game->map.width * TILE_SIZE, game->map.height * TILE_SIZE, "so_long");
	init_images(game);
}

/* Release the resources assigned to the game */
void	free_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		free(game->map.tiles);
		i++;
	}
	free(game->map.tiles);
	free(game->map.collect);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_window(game->mlx, game->win);
}