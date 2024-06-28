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

/* checks if chars/tiles that should be unique are duplicated */
static int	valid_num_entities(char *str, int end)
{
	static int	found_p = 0;
	static int	found_e = 0;
	static int	found_c = 0;

	if (*str == 'P' || *str == 'E' || *str == 'C')
	{
		if (*str == 'P')
			found_p++;
		else if (*str == 'E')
			found_e++;
		else if (*str == 'C')
			found_c++;
		if (found_e > 1 || found_p > 1)
			return (0);
	}
	if (end == 1 && (found_c == 0 || found_e != 1 || found_p != 1))
		return (0);
	return (1);
}

/* check if the char for the tile and position are valid */
int	valid_char_pos(t_game *game, char *line, char *str, int end)
{
	int		len;
	char	*found;

	if (str && line && ft_strlen(str) != ft_strlen(line))
	{
		free(str);
		free(line);
		return (0);
	}
	len = game->map.width;
	while (--len)
	{
		found = ft_strchr("0PCE1", line[len]);
		if ((!line || !found || !valid_num_entities(found, end))
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

/* checks that map given is a valid map. Return 1 if true, if not, return 0 */
int	check_valid_map(t_game *game)
	// TODO
{
	(void)game;
	return (1);
}
