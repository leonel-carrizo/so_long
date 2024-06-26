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

/* Updates the door status if all collectibles have been collected */
void	update_door_state(t_game *game)
{
	int	width;
	int	height;

	if (game->map.n_collect == 0)
	{
		game->map.exit.is_open = 1;
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image(
				game->mlx,
				DOOR_OPENED_IMG,
				&width, &height);
	}
}

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
	update_tiles(game);
	draw_map(game);
}

/* update image to be rendered */
void	update_tiles(t_game *game)
{
	int	width;
	int	height;

	update_door_state(game);
	if (game->player.position.x == game->map.exit.pos.x
		&& game->player.position.y == game->map.exit.pos.y)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image(
				game->mlx, PLAYER_DOOR_EXIT_IMG,
				&width, &height);
		draw_map(game);
		exit_game(game);
	}
}

/* Initialize game images */
void	init_images(t_game *game)
{
	int	width;
	int	height;

	game->img_wall = mlx_xpm_file_to_image(
			game->mlx, WALL_5_IMG, &width, &height);
	game->img_floor = mlx_xpm_file_to_image(
			game->mlx, FLOOR_1_IMG, &width, &height);
	game->img_player = mlx_xpm_file_to_image(
			game->mlx, PLAYER_FRONT_1_IMG, &width, &height);
	game->img_collect = mlx_xpm_file_to_image(
			game->mlx, COIN_1_IMG, &width, &height);
	game->img_exit = mlx_xpm_file_to_image(
			game->mlx, DOOR_CLOSED_IMG, &width, &height);
}

/* Initialize the game and load the map */
void	init_game(t_game *game, char *map_path)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game);
	load_map(game, map_path);
	init_images(game);
	game->win = mlx_new_window(
			game->mlx, game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, WIN_TITLE);
	if (!game->win)
		exit_game(game);
}
