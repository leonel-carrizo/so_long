/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:40:05 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/06 12:13:13 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "map.h"

typedef struct s_player
{
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
	void			*img_exit;
	int				num_collec;
	t_map			map;
}	t_game;

void	init_images(t_game *game);
void	init_game(t_game *game, char *map_path);
void	free_game(t_game *game);

#endif