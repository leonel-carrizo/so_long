/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizu@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:17:10 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/21 23:15:10 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Checks if the player's move is valid */
int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 ||  new_y < 0 || new_x >= game->map.width
		|| new_y >= game->map.height)
		return (0);
	if (game->map.tiles[new_y][new_x] == '1')
		return (0);
	if (game->map.tiles[new_y][new_x] == 'E' && !game->map.exit.is_open)
		return (0);
	return (1);
}

/* Updates the player's position based on the key pressed */
void	update_player_position(t_game *game, int keycode, int *x, int *y)
{
	if (is_valid_move(game, (*x), (*y)))
	{
		if (keycode == A || keycode == LEFT)
			(*x)--;
		else if (keycode == W || keycode == UP)
			(*y)--;
		else if (keycode == D || keycode == RIGHT)
			(*x)++;
		else if (keycode == S || keycode == DOWN)
			(*y)++;
		ft_printf("x: %d, y: %d\n", (*x), (*y));
		// game->player.position.x = (*x);
		// game->player.position.y = (*y);
		//print_moves(game, x, y);
	}
}

/* Handles keyboard events */
int	key_press(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	if (keycode == ESC)
		exit_game(game);
	new_x = game->player.position.x;
	new_y = game->player.position.y;
	if (keycode == A || keycode == W || keycode == D || keycode == S
		|| keycode == LEFT || keycode == RIGHT
		|| keycode == UP || keycode == DOWN)
	{
		update_player_position(game, keycode, &new_x, &new_y);
		update_map(game, new_x , new_y);
		update_tiles(game);
		draw_map(game);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	int	test = 0;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: <map_file.ber>\n", 2);
		exit(EXIT_FAILURE);
	}
	init_structs(&game);
	init_game(&game, argv[1]);
	draw_map(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	test = mlx_hook(game.win, 17, 1L << 0, exit_game, &game);
	if (test == 1)
		exit(0);
	mlx_loop(game.mlx);
	return (0);
}
