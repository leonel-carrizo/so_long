/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizu@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:17:10 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/19 14:35:53 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Handles keyboard events */
int	key_press(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	if (keycode == ESC)
	{
		free_game(game);
		exit(EXIT_SUCCESS);
	}
	new_x = game->map.player_pos.x;
	new_y = game->map.player_pos.y;
	update_position(keycode, &new_x, &new_y);
	if (is_valid_move(game, new_x, new_y))
	{
		game->map.tiles[game->map.player_pos.y][game->map.player_pos.x] = '0';
		game->map.player_pos.x = new_x;
		game->map.player_pos.y = new_y;
		game->map.tiles[new_y][new_x] = 'P';
	}
	draw_map(game);
	return (0);
}

/* Updates the player's position based on the key pressed */
void	update_position(int keycode, int *new_x, int *new_y)
{
	if (keycode == A || keycode == LEFT)
		(*new_x)--;
	else if (keycode == W || keycode == UP)
		(*new_y)--;
	else if (keycode == D || keycode == RIGHT)
		(*new_x)++;
	else if (keycode == S || keycode == DOWN)
		(*new_y)++;
}

/* Checks if the player's move is valid */
int	is_valid_move(t_game *game, int new_x, int new_y)
{
	game->map.exit.is_open = 0;
	if (new_x < 0 || new_x >= game->map.width || new_y < 0
		|| new_y >= game->map.height)
		return (0);
	if (game->map.tiles[new_y][new_x] == '1')
		return (0);
	if (game->map.tiles[new_y][new_x] == 'E' && !game->map.exit.is_open)
		return (0);
	return (1);
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
	test = mlx_hook(game.win, 17, 1L << 0, free_game, &game);
	if (test == 1)
		exit(0);
	mlx_loop(game.mlx);
	return (0);
}
