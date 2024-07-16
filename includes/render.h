/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:31:58 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/29 15:20:13 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "types.h"

# define FLOOR_1_IMG "assets/images/floor/floor1.xpm"
# define WALL_5_IMG "assets/images/walls/wall5.xpm"
# define BLOCK_0_IMG "assets/images/walls/block0.xpm"
# define BLOCK_1_IMG "assets/images/walls/block1.xpm"
# define COIN_1_IMG "assets/images/collectibles/coin_1.xpm"
# define PLAYER_FRONT_1_IMG "assets/images/players/player_front1.xpm"
# define START_DOOR_IMG "assets/images/doors/start_door.xpm"
# define DOOR_OPENED_IMG "assets/images/doors/door_opened.xpm"
# define DOOR_CLOSED_IMG "assets/images/doors/door_closed.xpm"
# define PLAYER_DOOR_EXIT_IMG "assets/images/players/player_door_exit.xpm"
# define PLAYER_DOOR_START_IMG "assets/images/players/player_door_start.xpm"

# define MOVES_COLOR 0x00FFD500

void	draw_tile(t_game *game, void *img, int x, int y);
void	draw_map(t_game *game, int old_x, int old_y);
void	update_player_image(t_game *game, int x, int y);
void	draw_exit_door(t_game *game);
void	render_error_message(int errnum);

#endif
