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
	int			fd;
	int			ok;
	char		*line;
	static int	i = -1;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (FAIL_OPEN_FILE);
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_strcpy(game->map.tiles[++i], line);
		ok = check_map_line(game, line);
		if (ok != SUCCESS)
		{
			free(line);
			close(fd);
			get_next_line(fd);
			return (ok);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (SUCCESS);
}

/* Count map dimensions from file */
static int	count_map_dimensions(t_game *game, char *file_path)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (FAIL_OPEN_FILE);
	line = get_next_line(fd);
	game->map.width = ft_strlen(line) - 1;
	while (line != NULL)
	{
		game->map.height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (game->map.width < 5)
		return (INVAL_N_ENTITIES);
	return (SUCCESS);
}

/* Load the map from the specified file */
int	load_map(t_game *game, char *file_path)
{
	int	dimensions;
	int	alloc_map;
	int	init_map;
	int	valid_player_path;

	dimensions = count_map_dimensions(game, file_path);
	if (dimensions != SUCCESS)
		return (dimensions);
	alloc_map = allocate_map(&game->map, game->map.width, game->map.height);
	if (alloc_map < 1)
		return (alloc_map);
	init_map = fill_map(game, file_path);
	if (init_map != SUCCESS)
		return (init_map);
	parse_map_entities(game);
	valid_player_path = check_valid_path(game);
	if (valid_player_path != SUCCESS)
		return (valid_player_path);
	return (SUCCESS);
}
