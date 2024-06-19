/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:42:10 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/19 11:24:01 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* Initializes game structs with predefined values */
void	init_structs(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.tiles = NULL;
	game->map.player_pos.x = -1;
	game->map.player_pos.y = -1;
	game->map.exit.is_open = 0;
	game->map.collect = NULL;
	game->map.n_collect = 0;
	game->img_wall = NULL;
	game->img_player = NULL;
	game->img_collect = NULL;
	game->img_exit = NULL;
	game->img_floor = NULL;
}

/* Initialize game images */
void	init_images(t_game *game)
{
	int	width;
	int	height;

	game->img_wall = mlx_xpm_file_to_image(
			game->mlx, "assets/images/wall1.xpm", &width, &height);
	game->img_floor = mlx_xpm_file_to_image(
			game->mlx, "assets/images/floor1.xpm", &width, &height);
	game->img_player = mlx_xpm_file_to_image(
			game->mlx, "assets/images/player_front.xpm", &width, &height);
	game->img_collect = mlx_xpm_file_to_image(
			game->mlx, "assets/images/coin_1.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(
			game->mlx, "assets/images/door_closed.xpm", &width, &height);
}

/* Release the resources assigned to the game */
void	free_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		free(game->map.tiles[i]);
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
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

/* Initialize the game and load the map */
void	init_game(t_game *game, char *map_path)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_game(game);
		exit(EXIT_FAILURE);
	}
	load_map(&game->map, map_path);
	init_images(game);
	game->win = mlx_new_window(
			game->mlx, game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, "so_long game");
	if (!game->win)
	{
		free_game(game);
		exit(EXIT_FAILURE);
	}
}
