/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:19:49 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/29 15:18:49 by lcarrizo         ###    ###london.com    */
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
			return (print_message(MAP_ERROR, DOBLE_EXIT));
		if (found_p > 1)
			return (print_message(MAP_ERROR, DOBLE_PLAYER));
	}
	if (end == 1)
	{
		if ((found_c == 0 || found_e != 1 || found_p != 1))
			return (print_message(MAP_ERROR, INVAL_N_ENTITIES));
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
		print_message(MAP_ERROR, INVAL_DIMENSIONS);
		return (INVAL_DIMENSIONS);
	}
	else if (end == 1 && game->map.width <= game->map.height)
	{
		print_message(MAP_ERROR, INVAL_DIMENSIONS);
		return (INVAL_DIMENSIONS);
	}
	return (len);
}

static int	valid_wall_pos(t_game *game, char *line, int len, int end)
{
	if ((!line) || ((line[0] != WALL) || (line[game->map.width - 1] != WALL)
			|| (game->map.height == 0 && line[len - 1] != WALL)
			|| (end && line[len - 1] != WALL)))
	{
		print_message(MAP_ERROR, INVAL_WALL);
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
	char	*found;

	if (end == 1)
		line = str;
	len = valid_dimentions(game, line, str, end);
	if (len <= 0)
		return (INVAL_DIMENSIONS);
	while (len)
	{
		found = ft_strchr(VALID_CHAR, line[len - 1]);
		if (!found)
			return (print_message(MAP_ERROR, INVAL_OBJECT));
		num_entities = valid_num_entities(found, end);
		if (num_entities < 1)
			return (num_entities);
		wall_pos = valid_wall_pos(game, line, len, end);
		if (wall_pos < 1)
			return (wall_pos);
		len--;
	}
	return (SUCCESS);
}
