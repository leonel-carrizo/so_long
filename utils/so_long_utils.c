/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:17:33 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/22 14:08:06 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	int	len;
	int	len_e;
	const char *ext;

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
