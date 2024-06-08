/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizu@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:17:10 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/08 14:21:00 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Handles keyboard events */
int	key_press(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	if (keycode == 65307)
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
	if (keycode == 65361) // left
		(*new_x)--;
	else if (keycode == 65362) // up
		(*new_y)--;
	else if (keycode == 65363) // right
		(new_x)++;
	else if (keycode == 65364) // down
		(new_y)++;
}

/* Checks if the player's move is valid */
int is_valid_move(t_game *game, int new_x, int new_y)
{
	return (new_x >= 0 && new_x < game->map.width && new_y >= 0 &&
			new_y < game->map.height && game->map.tiles[new_y][new_x] != '1');
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: <map_file.ber>\n", 2);
		exit(EXIT_FAILURE);
	}
	init_game(&game, argv[1]);
	draw_map(&game);
	mlx_key_hook(game.win, key_press, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
