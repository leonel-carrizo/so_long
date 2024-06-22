/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizu@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:17:10 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/22 14:05:18 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Checks if the player's move is valid */
int	is_valid_move(t_map map, int new_x, int new_y, int keycode)
{
	if (keycode == A || keycode == W || keycode == D || keycode == S
		|| keycode == LEFT || keycode == RIGHT
		|| keycode == UP || keycode == DOWN)
	{
		if (keycode == A || keycode == LEFT)
			new_x--;
		else if (keycode == W || keycode == UP)
			new_y--;
		else if (keycode == D || keycode == RIGHT)
			new_x++;
		else if (keycode == S || keycode == DOWN)
			new_y++;
		if (new_x < 0 ||  new_y < 0 || new_x >= map.width || new_y >= map.height)
			return (0);
		if (map.tiles[new_y][new_x] == '1')
			return (0);
		if (map.tiles[new_y][new_x] == 'E' && !map.exit.is_open)
			return (0);
		return (1);
	}
	return (0);
}

/* Updates the player's position based on the key pressed */
void	update_player_position(t_game *game, int keycode)
{
	if (keycode == A || keycode == LEFT)
		game->player.position.x--;
	else if (keycode == W || keycode == UP)
		game->player.position.y--;
	else if (keycode == D || keycode == RIGHT)
		game->player.position.x++;
	else if (keycode == S || keycode == DOWN)
		game->player.position.y++;
	game->player.n_moves++;
	ft_printf(" Nro. %d\n", game->player.n_moves);
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
	if (is_valid_move(game->map, new_x, new_y, keycode))
	{
		update_player_position(game, keycode);
		update_map(game, new_x , new_y);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	int	test = 0;

	if (!is_ber_extention(argv[1]) || argc != 2)
	{
		ft_putstr_fd("Usage: <map_file.ber>\n", 2);
		exit(EXIT_FAILURE);
	}
	// TODO: check valid map
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
