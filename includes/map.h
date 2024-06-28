/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:30:42 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/25 10:19:46 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "so_long.h"

# ifndef TILE_SIZE
#  define TILE_SIZE 32
# endif

int		check_valid_map(t_game *game);
int		pre_checks(t_game *game, char *line, char **str, int ok[]);
int		count_map_dimensions(t_game *game, char *file_path);
void	load_map(t_game *game, char *file_path);
void	allocate_map(t_map *map, int width, int height);
void	fill_map(t_game *game, char *file_path);
void	parse_map_entities(t_game *game);
void	init_entities_positions(t_game *game);
void	init_collectibles(t_map *map);
void	free_map(t_map *map);

#endif
