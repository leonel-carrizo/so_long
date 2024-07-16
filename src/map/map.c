/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:44:18 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/29 15:18:35 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* Allocates memory for the map with the specified dimensions */
int	allocate_map(t_map *map, int width, int height)
{
	int	i;

	map->tiles = (char **)malloc(height * sizeof(char *));
	if (!map->tiles)
		return (FAIL_MAP_ALLOC);
	i = 0;
	while (i < height)
	{
		map->tiles[i] = (char *)ft_calloc(width, ((width + 2) * sizeof(char)));
		if (!map->tiles[i])
		{
			while (i > 0)
			{
				free(map->tiles[i]);
				i--;
				return (FAIL_MAP_ALLOC);
			}
		}
		i++;
	}
	return (SUCCESS);
}

/* Fill the map with the data from the file */
int	fill_map(t_game *game, char *file_path)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (FAIL_OPEN_FILE);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_strcpy(game->map.tiles[i], line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (SUCCESS);
}

/*	Check that the map has valid entities,
that they are in the allowed position
and that units that must be unique are not repeated. */
static int	pre_checks(t_game *game, char **line, int ok[])
{
	int			check_line;
	static int	end = 0;
	static char	*temp = NULL;

	if (game->map.width < 6)
		(*ok) = INVAL_N_ENTITIES;
	if (!temp && *line)
		temp = ft_strdup(*line);
	if (!*line && temp)
	{
		*line = temp;
		end = 1;
	}
	check_line = check_map_line(game, *line, temp, end);
	if (check_line < 1)
	{
		(*ok) = check_line;
		temp = NULL;
		free(temp);
		return ((*ok));
	}
	if (*line)
		ft_strlcpy(temp, *line, game->map.width + 2);
	if (end)
		free(temp);
	return ((*ok));
}

/* Count map dimensions from file */
static int	count_map_dimensions(t_game *game, char *file_path)
{
	int			fd;
	static int	ok = SUCCESS;
	static char	*line = NULL;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (FAIL_OPEN_FILE);
	line = get_next_line(fd);
	game->map.width = ft_strlen(line) - 1;
	while (line != NULL)
	{
		if (ok)
			pre_checks(game, &line, &ok);
		game->map.height++;
		free(line);
		line = get_next_line(fd);
		if (!line)
		{
			pre_checks(game, &line, &ok);
			line = NULL;
		}
	}
	if (ok < 1)
		return (ok);
	return (1);
}

/* Load the map from the specified file */
int	load_map(t_game *game, char *file_path)
{
	int	dimensions;
	int	alloc_map;
	int init_map;
	int	valid_map;

	dimensions = count_map_dimensions(game, file_path);
	if (dimensions < 1)
	{
		print_message(MAP_ERROR, dimensions);
		return (dimensions);
	}
	alloc_map = allocate_map(&game->map, game->map.width, game->map.height);
	if (alloc_map < 1)
	{
		print_message(MAP_ERROR, alloc_map);
		return (alloc_map);
	}
	init_map = fill_map(game, file_path);
	if (init_map < 1)
	{
		print_message(MAP_ERROR, init_map);
		return (init_map);
	}
	parse_map_entities(game);
	valid_map = check_valid_path(game);
	if (valid_map < 1)
	{
		print_message(MAP_ERROR, valid_map);
		return (valid_map);
	}
	return (SUCCESS);
}
