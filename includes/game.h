/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:40:05 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/29 15:20:01 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "so_long.h"

int		exit_game(t_game *game);
int		check_valid_path(t_game *game);
void	init_images(t_game *game);
void	init_game(t_game *game, char *map_path);
void	init_structs(t_game *game);
void	update_map(t_game *game, int x, int y);
void	update_tiles(t_game *game);

#endif
