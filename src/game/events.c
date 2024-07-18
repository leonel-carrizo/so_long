/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 00:10:23 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/07/17 22:04:27 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
	ft_printf("No. movements: %d\n", game->player.n_moves);
}

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
		if (new_x < 0 || new_y < 0 || new_x >= map.width || new_y >= map.height)
			return (0);
		if (map.tiles[new_y][new_x] == '1')
			return (0);
		return (1);
	}
	return (0);
}

/* Handles keyboard events */
int	key_press(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;
	int	valid;

	if (keycode == ESC)
	{
		ft_printf("%sGAME OVER:\n%s%s\n", BC_GREEN, C_YELLOW, USER_EXIT);
		exit_game(game, GAME_OVER);
	}
	new_x = game->player.position.x;
	new_y = game->player.position.y;
	valid = is_valid_move(game->map, new_x, new_y, keycode);
	if (valid > 0)
	{
		update_player_position(game, keycode);
		update_map(game, new_x, new_y);
		draw_map(game, new_x, new_y);
	}
	if (game->player.won)
	{
		ft_printf("%sGAME OVER:\n%s%s\n", BC_GREEN, C_GREEN, MSG_YOU_WIN);
		exit_game(game, SUCCESS);
	}
	return (0);
}
