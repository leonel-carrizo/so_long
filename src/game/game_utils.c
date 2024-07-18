/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:47:49 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/07/18 11:57:42 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*  checks if map file extention is correct .ber extention */
int	is_valid_map_arg(const char *path)
{
	int			len;
	int			len_e;
	int			fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("Opening file");
		close(fd);
		return (INV_MAP_FILE);
	}
	close(fd);
	len = ft_strlen(path);
	len_e = ft_strlen(FILE_EXTENSION);
	while (--len_e)
	{
		if (path[--len] != FILE_EXTENSION[len_e])
			return (INV_MAP_FILE);
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
int	print_error_msg(int errtype, int errnum)
{
	if (errtype == GAME_ERROR)
		game_error_message(errnum);
	else if (errtype == MAP_ERROR)
		map_error_message(errnum);
	return (errtype);
}

/* Release the resources assigned to the game */
int	exit_game(t_game *game, int status)
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
	if (status != SUCCESS)
		exit(status);
	exit(EXIT_SUCCESS);
}
