/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:53:03 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/29 15:20:40 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "so_long.h"

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_collectible
{
	int			collected;
	t_position	position;
}	t_collect;

typedef struct s_start
{
	int			bussy;
	t_position	pos;
}	t_start;

typedef struct s_exit
{
	int			is_open;
	t_position	pos;
}	t_exit;

typedef struct s_map
{
	int			width;
	int			height;
	int			n_collect;
	char		**tiles;
	t_start		start;
	t_exit		exit;
	t_collect	*collect;
}	t_map;

typedef struct s_player
{
	int			n_moves;
	int			won;
	t_position	position;
}	t_player;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	void			*img_wall;
	void			*img_floor;
	void			*img_player;
	void			*img_collect;
	void			*img_start;
	void			*img_exit;
	int				num_collec;
	t_player		player;
	t_map			map;
}	t_game;

#endif
