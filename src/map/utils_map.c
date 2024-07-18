/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:19:49 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/07/18 14:49:02 by lcarrizo         ###   ########.fr       */
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

	if (*str == PLAYER || *str == MAP_EXIT || *str == COLLECTIBLE)
	{
		if (*str == PLAYER)
			found_p++;
		else if (*str == MAP_EXIT)
			found_e++;
		else if (*str == COLLECTIBLE)
			found_c++;
		if (found_e > 1)
		{
			// print_message(MAP_ERROR, DOBLE_EXIT);
			return (DOBLE_EXIT);
		}
		if (found_p > 1)
		{
			// print_message(MAP_ERROR, DOBLE_PLAYER);
			return (DOBLE_PLAYER);
		}
	}
	if (end == 1)
	{
		if ((found_c == 0 || found_e != 1 || found_p != 1))
		{
			// print_message(MAP_ERROR, INVAL_N_ENTITIES);
			return (INVAL_N_ENTITIES);
		}
	}
	return (SUCCESS);
}

static int	valid_dimentions(t_game *game, char *line, char *str, int end)
{
	int	len;

	if (!line)
		return (INVAL_DIMENSIONS);
	len = ft_strlen(line) - 1;
	if (!len || (str && (len + 1 != ((int)ft_strlen(str)))))
	{
		// print_message(MAP_ERROR, INVAL_DIMENSIONS);
		return (INVAL_DIMENSIONS);
	}
	else if (end == 1 && game->map.width == game->map.height)
	{
		// print_message(MAP_ERROR, INVAL_DIMENSIONS);
		return (INVAL_DIMENSIONS);
	}
	return (SUCCESS);
}

static int	valid_wall_pos(t_game *game, char *line, int len, int end)
{
	if ((!line) || ((line[0] != WALL) || (line[game->map.width - 1] != WALL)
			|| (game->map.height == 0 && line[len - 1] != WALL)
			|| (end && line[len - 1] != WALL)))
	{
		// print_message(MAP_ERROR, INVAL_WALL);
		return (INVAL_WALL);
	}
	return (SUCCESS);
}

/* check if the char for the tile and position are valid */
int	check_map_line(t_game *game, char *line, char *str, int end)
{
	int		len;
	int		num_entities;
	int		wall_pos;
	char	*object_ok;

	if (end == 1)
		line = str;
	if (valid_dimentions(game, line, str, end) != SUCCESS)
		return (INVAL_DIMENSIONS);
	len = ft_strlen(line) - 1;
	while (len)
	{
		object_ok = ft_strchr(VALID_CHAR, line[len - 1]);
		if (!object_ok)
			return (INVAL_OBJECT);
		num_entities = valid_num_entities(object_ok, end);
		if (num_entities != SUCCESS)
			return (num_entities);
		wall_pos = valid_wall_pos(game, line, len, end);
		if (wall_pos != SUCCESS)
			return (wall_pos);
		len--;
	}
	return (SUCCESS);
}
