/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:30:42 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/06 13:34:01 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "game.h"

# ifndef TILE_SIZE
#  define TILE_SIZE 32
# endif

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_collectible
{
	t_position	position;
	int	collected;
}	t_collect;

typedef struct s_exit
{
	t_position	pos;
	int	is_open;
}	t_exit;

typedef struct s_map
{
	int	width;
	int	height;
	int	n_collect;
	char	**tiles;
	t_position	player_pos;
	t_exit	exit;
	t_collect	*collect;
}	t_map;


void	load_map(t_map *map, char *file_path);
void	allocate_map(t_map *map, int width, int height);
void	count_map_dimensions(t_map *map, char *file_path);
void	fill_map(t_map *map, char *file_path);
void	parse_map_entities(t_map *map);
void	init_entities_positions(t_map *map);
void	init_collectibles(t_map *map);
void	free_map(t_map *map);

#endif
