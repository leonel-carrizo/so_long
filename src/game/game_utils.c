/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:47:49 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/07/18 10:00:26 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*  checks if map file extention is correct .ber extention */
int	is_valid_map_arg(const char *path)
{
	int			len;
	int			len_e;
	const char	*ext;

	len = ft_strlen(path);
	len_e = 4;
	ext = ".ber";
	while (--len_e)
	{
		if (path[--len] != ext[len_e])
			return (INV_MAP_ARG);
	}
	return (SUCCESS);
}

/*·Initializes·game·structs·with·predefined·values·*/
void	init_structs(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.tiles = NULL;
	game->player.n_moves = 0;
	game->player.position.x = -1;
	game->player.position.y = -1;
	game->player.won = 0;
	game->map.exit.is_open = 0;
	game->map.collect = NULL;
	game->map.n_collect = 0;
	game->img_wall = NULL;
	game->img_player = NULL;
	game->img_collect = NULL;
	game->img_exit = NULL;
	game->img_floor = NULL;
	game->img_start = NULL;
}

/* Display custom error message in shell  */
int	print_message(int status, int errnum)
{
	if (status == 0)
		return (errnum);
	if (status == GAME_OVER)
	{
		if (errnum == USER_WIN)
			ft_printf("%sGAME OVER:\n%s%s\n", BC_GREEN, C_GREEN, MSG_YOU_WIN);
		else if (errnum == USER_LOST)
			ft_printf("%sGAME OVER:\n%s%s\n", BC_GREEN, C_RED, MSG_YOU_LOST);
		else if (errnum == USER_CLOSES)
			ft_printf("%sGAME OVER:\n%s%s\n", BC_GREEN, C_YELLOW, USER_EXIT);
		return (0);
	}
	else if (status == GAME_ERROR)
		game_error_message(errnum);
	else if (status == MAP_ERROR)
		map_error_message(errnum);
	else if (status == RENDER_ERROR)
		render_error_message(errnum);
	return (errnum);
}

/* Release the resources assigned to the game */
int	exit_game(t_game *game, int errnum)
{
	free_map(&game->map);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_collect)
		mlx_destroy_image(game->mlx, game->img_collect);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_start)
		mlx_destroy_image(game->mlx, game->img_start);
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	if (!errnum)
		exit(EXIT_SUCCESS);
	exit(errnum);
}
