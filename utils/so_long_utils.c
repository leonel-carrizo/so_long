/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:17:33 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/22 17:36:45 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// static int	valid_wall_pos(t_game *game, char *line, int len, int end)
// {
// 	int	height;

// 	height = game->map.height;
// 	if ((!line) || ((line[0] != WALL) || (line[game->map.width - 1] != WALL)
// 			|| (end == 1 && line[len - 1] != WALL)
// 			|| (end == height && line[len - 1] != WALL)))
// 	{
// 		return (INVAL_WALL);
// 	}
// 	return (SUCCESS);
// }

/*	Check that the map has valid entities,
that they are in the allowed position
and that units that must be unique are not repeated. */
// static int	pre_checks(t_game *game, char **line, int ok[])
// {
// 	int			check_line;
// 	static int	end = 0;
// 	static char	*temp = NULL;

// 	if (game->map.width < 6)
// 		(*ok) = INVAL_N_ENTITIES;
// 	if (!temp && *line)
// 		temp = ft_strdup(*line);
// 	if (!*line && temp)
// 		end = 1;
// 	if (*line || end == 1)
// 		check_line = check_map_line(game, *line);
// 	if (check_line != SUCCESS)
// 	{
// 		(*ok) = check_line;
// 		free(temp);
// 		temp = NULL;
// 		return ((*ok));
// 	}
// 	if (*line)
// 		ft_strlcpy(temp, *line, game->map.width + 2);
// 	if (end)
// 		free(temp);
// 	return (SUCCESS);
// }
