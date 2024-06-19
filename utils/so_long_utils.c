/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:17:33 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/19 11:52:28 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*·Initializes·game·structs·with·predefined·values·*/
void    init_structs(t_game *game)
{
        game->mlx = NULL;
        game->win = NULL;
        game->map.width = 0;
        game->map.height = 0;
        game->map.tiles = NULL;
        game->map.player_pos.x = -1;
        game->map.player_pos.y = -1;
        game->map.exit.is_open = 0;
        game->map.collect = NULL;
        game->map.n_collect = 0;
        game->img_wall = NULL;
        game->img_player = NULL;
        game->img_collect = NULL;
        game->img_exit = NULL;
        game->img_floor = NULL;
}
