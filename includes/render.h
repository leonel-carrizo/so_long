/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:31:58 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/06 12:18:10 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "game.h"

void	draw_tile(t_game *game, void *img, int x, int y);
void	draw_map(t_game *game);
void	draw_current_tile(t_game *game, int x, int y);

#endif
