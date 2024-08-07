/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizu@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:17:10 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/07/18 14:38:32 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	int		start;
	int		check_file;
	t_game	game;

	if (argc != 2)
		return (print_error_msg(GAME_ERROR, INV_N_ARG));
	check_file = is_valid_map_arg(argv[1]);
	if (check_file != SUCCESS)
		return (print_error_msg(GAME_ERROR, check_file));
	init_structs(&game);
	start = init_game(&game, argv[1]);
	if (start != SUCCESS)
		exit_game(&game, start);
	draw_map(&game, 0, 0);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 1L << 0, exit_game, &game);
	mlx_loop(game.mlx);
}
