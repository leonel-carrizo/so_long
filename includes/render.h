/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:31:58 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/18 11:35:53 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "types.h"

void	draw_tile(t_game *game, void *img, int x, int y);
void	draw_map(t_game *game);
void	draw_current_tile(t_game *game, int x, int y);
void	update_door_state(t_game *game);

#endif
