/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:44:18 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/15 17:52:57 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* Load the map from the specified file */
void	load_map(t_map *map, char *file_path)
{
	count_map_dimensions(map, file_path);
	allocate_map(map, map->width, map->height);
	fill_map(map, file_path);
	parse_map_entities(map);
}

/* Count map dimensions from file */
void	count_map_dimensions(t_map *map, char *file_path)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map file");
		exit(EXIT_FAILURE);
	}
	map->width = 0;
	map->height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (map->width == 0)
			map->width = ft_strlen(line);
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

/* Allocates memory for the map with the specified dimensions */
void	allocate_map(t_map *map, int width, int height)
{
	int	i;

	map->tiles = (char **)malloc(height * sizeof(char *));
	i = 0;
	while (i < height)
	{
		map->tiles[i] = (char *)malloc((width + 1) * sizeof(char));
		i++;
	}
}

/* Fill the map with the data from the file */
void	fill_map(t_map *map, char *file_path)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map file");
		exit(EXIT_FAILURE);
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_strcpy(map->tiles[i], line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
}
