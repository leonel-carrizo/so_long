/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:40:05 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/07/18 11:54:04 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "so_long.h"

# ifndef FILE_EXTENSION
#  define FILE_EXTENSION ".ber"
# endif


int		exit_game(t_game *game, int errnum);
int		check_valid_path(t_game *game);
int		init_game(t_game *game, char *map_path);
int		print_error_msg(int errtype, int errnum);
void	init_images(t_game *game);
void	init_structs(t_game *game);
void	update_map(t_game *game, int x, int y);
void	game_error_message(int errnum);

#endif
