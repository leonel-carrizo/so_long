/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:47:49 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/22 17:44:20 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
	game->map.exit.is_open = 0;
	game->map.collect = NULL;
	game->map.n_collect = 0;
	game->img_wall = NULL;
	game->img_player = NULL;
	game->img_collect = NULL;
	game->img_exit = NULL;
	game->img_floor = NULL;
}

/*  checks if map file extention is correct .ber extention */
int	is_ber_extention(const char *path)
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
			return (0);
	}
	return (1);
}

/* checks that map given is a valid map, if not, free memory and close game */
int	check_valid_map(t_game *game)
	/* TODO */
{
	(void)game;
	return (1);
}

/* Release the resources assigned to the game */
int	exit_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		free(game->map.tiles[i]);
		i++;
	}
	free(game->map.tiles);
	free(game->map.collect);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}
