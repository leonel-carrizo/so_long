/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:19:49 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/25 14:50:38 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* Free the memory allocated for the map */
void	free_map(t_map *map)
{
	int	i;

	if (map->tiles)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->tiles[i]);
			i++;
		}
		free(map->tiles);
		free(map->collect);
		map = NULL;
	}
}

/* check if the char for the tile is valid */
static int	valid_char_pos(t_game *game, char *line, char *str, int end)
{
	int	len;

	if (str && line && ft_strlen(str) != ft_strlen(line))
	{
		free(str);
		free(line);
		return (0);
	}
	len = game->map.width;
	while (--len)
	{
		if ((!line || !ft_strchr("0PCE1", line[len]))
			|| ((line[0] != '1') || (line[game->map.width - 1] != '1')
				|| (game->map.height == 0 && line[len] != '1')
				|| (end && line[len] != '1')))
		{
			free(line);
			if (end == 0)
				free(str);
			return (0);
		}
	}
	return (1);
}

/*	preliminar checks. */
int	pre_checks(t_game *game, char *line, char **str, int ok[])
{
	static int	end = 0;

	if (!*str)
		*str = ft_strdup(line);
	if (!line)
	{
		line = *str;
		end = 1;
	}
	if (valid_char_pos(game, line, *str, end) == 0)
	{
		*str = NULL;
		(*ok) = 0;
		return (0);
	}
	if (line)
		ft_strncpy(*str, line, game->map.width);
	if (end)
		free(*str);
	return (1);
}

/* checks that map given is a valid map. Return 1 if true, if not, return 0 */
int	check_valid_map(t_game *game)
	// TODO
{
	(void)game;
	return (1);
}
