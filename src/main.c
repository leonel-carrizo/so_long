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
	int		start;
	t_game	game;

	if (argc != 2)
		return (exit_game(&game, GAME_ERROR, INV_N_ARG));
	if (!is_valid_map_arg(argv[1]))
		return (exit_game(&game, GAME_ERROR, INV_MAP_ARG));
	init_structs(&game);
	start = init_game(&game, argv[1]);
	if (start < 1)
		return (exit_game(&game, 0, start));
	draw_map(&game, 0, 0);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 1L << 0, exit_game, &game);
	mlx_loop(game.mlx);
}
