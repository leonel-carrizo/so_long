/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:05:04 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/10 14:21:16 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/include/libft.h"
# include "../lib/libmlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "render.h"

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1080
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 920
# endif

/* Handles keyboard events */
int		key_press(int keycode, t_game *game);

/* Checks if the player's move is valid */
int		is_valid_move(t_game *game, int new_x, int new_y);

/* Updates the player's position based on the key pressed */
void	update_position(int keycode, int *new_x, int *new_y);

#endif
