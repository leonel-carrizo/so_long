/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:05:04 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/29 15:20:21 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/include/libft.h"
# include "../lib/libmlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include "render.h"
# include "types.h"
# include "map.h"
# include "game.h"
# include "erros.h"

# ifndef WIN_TITLE
#  define WIN_TITLE "so_long game"
# endif

// GAME KEYWORDS
# define ESC 65307
# define W 0x77
# define UP 65362
# define A 0x61
# define LEFT 65361
# define S 0x73
# define DOWN 65364
# define D 0x64
# define RIGHT 65363

int		is_valid_map_arg(const char *path);

/* Handles keyboard events */
int		key_press(int keycode, t_game *game);

/* Checks if the player's move is valid */
int		is_valid_move(t_map map, int new_x, int new_y, int keycode);

/* Updates the player's position based on the key pressed */
void	update_player_position(t_game *game, int keycode);

#endif
