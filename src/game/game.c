/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:42:10 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/29 15:18:58 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* update changes in the map after events */
void	update_map(t_game *game, int x, int y)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->player.position.x;
	pos_y = game->player.position.y;
	if (game->map.tiles[pos_y][pos_x] == COLLECTIBLE)
		game->map.n_collect--;
	game->map.tiles[y][x] = EMPTY_SPACE;
	game->map.tiles[pos_y][pos_x] = PLAYER;
	if (game->map.n_collect == 0)
		game->map.exit.is_open = 1;
	if (game->player.position.x == game->map.exit.pos.x
		&& game->player.position.y == game->map.exit.pos.y)
		game->player.won = 1;
}

/* 	initializes the default images that will be drawn on the map
	the first time it is displayed on the screen */
void	init_images(t_game *game)
{
	int	width;
	int	height;

	game->img_wall = mlx_xpm_file_to_image(
			game->mlx, WALL_5_IMG, &width, &height);
	game->img_floor = mlx_xpm_file_to_image(
			game->mlx, FLOOR_1_IMG, &width, &height);
	game->img_player = mlx_xpm_file_to_image(
			game->mlx, PLAYER_DOOR_START_IMG, &width, &height);
	game->img_collect = mlx_xpm_file_to_image(
			game->mlx, COIN_1_IMG, &width, &height);
	game->img_exit = mlx_xpm_file_to_image(
			game->mlx, DOOR_CLOSED_IMG, &width, &height);
	game->img_start = mlx_xpm_file_to_image(
			game->mlx, START_DOOR_IMG, &width, &height);
}

/* Initialize the game and load the map */
int	init_game(t_game *game, char *map_path)
{
	int map_loaded;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		print_message(MLX_ERROR, FAIL_CONNEC);
		return (FAIL_CONNEC);
	}
	map_loaded = load_map(game, map_path);
	if (map_loaded < 1)
		return (map_loaded);
	init_images(game);
	game->win = mlx_new_window(game->mlx, game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, WIN_TITLE);
	if (!game->win)
	{
		print_message(MLX_ERROR, FAIL_WIN);
		return (FAIL_WIN);
	}
	return (SUCCESS);
}
