/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:40:05 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/03 22:56:33 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "map.h"
# include "render.h"
# include "so_long.h"

typedef struct s_game
{
	void			*mlx;
	void			*win;
	void			*img_floor1;
	int				num_collec;
	t_collec		*collectible;
	t_player		player;
	t_map			map;
	t_exit			exit;
}	t_game;

typedef struct s_collectible
{
	int	x;
	int	y;
	int	collected;
}	t_collect

#endif
