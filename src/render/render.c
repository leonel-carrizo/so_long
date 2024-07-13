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

/* Updates the door status if all collectibles have been collected */
void	draw_exit_door(t_game *game)
{
	int	width;
	int	height;

	if (game->player.position.x == game->map.exit.pos.x
		&& game->player.position.y == game->map.exit.pos.y)
		return ;
	if (game->map.n_collect == 0)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image(game->mlx,
				DOOR_OPENED_IMG, &width, &height);
	}
	draw_tile(game, game->img_exit, game->map.exit.pos.x, game->map.exit.pos.y);
}

/* Draw the space for the movement counter */
static void	draw_space_counter(t_game *game)
{
	int	width;
	int	height;

	mlx_destroy_image(game->mlx, game->img_wall);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			BLOCK_0_IMG, &width, &height);
	draw_tile(game, game->img_wall, 0, 0);
	mlx_destroy_image(game->mlx, game->img_wall);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			BLOCK_1_IMG, &width, &height);
	draw_tile(game, game->img_wall, 1, 0);
}

/* Draws the current tile based on its type */
static void	draw_init_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			if (game->map.tiles[y][x] == WALL)
				draw_tile(game, game->img_wall, x, y);
			else if (game->map.tiles[y][x] == PLAYER)
				draw_tile(game, game->img_player, x, y);
			else if (game->map.tiles[y][x] == COLLECTIBLE)
				draw_tile(game, game->img_collect, x, y);
			else if (game->map.tiles[y][x] == MAP_EXIT)
				draw_tile(game, game->img_exit, x, y);
			else if (game->map.tiles[y][x] == EMPTY_SPACE)
				draw_tile(game, game->img_floor, x, y);
		}
	}
}

/* Draw the entire map */
void	draw_map(t_game *game, int old_x, int old_y)
{
	int			p_x;
	int			p_y;
	static int	starting = 1;

	p_x = game->player.position.x;
	p_y = game->player.position.y;
	if (starting == 1)
		draw_init_map(game);
	draw_space_counter(game);
	if (!starting)
	{
		update_player_image(game, p_x, p_y);
		draw_tile(game, game->img_floor, old_x, old_y);
		draw_exit_door(game);
	}
	if (game->map.start.bussy == 0)
		draw_tile(game, game->img_start, game->map.start.pos.x,
			game->map.start.pos.y);
	starting = 0;
}
