/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizu@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:17:10 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/29 15:18:00 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (!is_ber_extention(argv[1]) || argc != 2)
	{
		ft_putstr_fd("Usage: <map_file.ber>\n", 2);
		exit(EXIT_FAILURE);
	}
	init_structs(&game);
	init_game(&game, argv[1]);
	draw_map(&game, 0, 0);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 1L << 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
