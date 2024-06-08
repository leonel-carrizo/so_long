/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:44:18 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/08 13:24:39 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* Load the map from the specified file */
void    load_map(t_map *map, char *file_path)
{
	count_map_dimensions(map, file_path);
	allocate_map(map, map->width, map->height);
	fill_map(map, file_path);
	parse_map_entities(map);
}

/* Count map dimensions from file */
void	count_map_dimensions(t_map *map, char *file_path)
{
	int	fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map file");
		exit(EXIT_FAILURE);
	}
	map->width = 0;
	map->height = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (map->width == 0)
			map->width = ft_strlen(line) - 1;
		map->height++;
		free(line);
	}
	close(fd);
}

/* Allocates memory for the map with the specified dimensions */
void	allocate_map(t_map *map, int width, int height)
{
	int	i;

	map->tiles = (char **)malloc(height * sizeof(char*));
	i = 0;
	while(i < height)
	{
		map->tiles[i] = (char *)malloc((width + 1) * sizeof(char));
		i++;
	}
}

/* Fill the map with the data from the file */
void	fill_map(t_map *map, char *file_path)
{
	int	fd;
	int	i;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map file");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_strcpy(map->tiles[i], line);
		free(line);
		i++;
	}
	close(fd);
}

/* Analyzes the entities on the map (player, collectibles, exit door) */
void	parse_map_entities(t_map *map)
{
	init_entities_positions(map);
	init_collectibles(map);
}

/* Initializes the positions of the entities on the map */
void	init_entities_positions(t_map *map)
{
	int	i;
	int	j;

	map->n_collect = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->tiles[i][j] == 'P')
			{
				map->player_pos.x = j;
				map->player_pos.y = i;
			}
			else if (map->tiles[i][j] == 'E')
			{
				map->exit.pos.x = j;
				map->exit.pos.y = i;
			}
			else if (map->tiles[i][j] == 'C')
				map->n_collect++;
			j++;
		}
		i++;
	}
}

/* Initialize the list of collectibles on the map */
void	init_collectibles(t_map *map)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	idx = 0;
	map->collect = (t_collect *)malloc(map->n_collect * sizeof(t_collect));
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->tiles[i][j] == 'C')
			{
				map->collect[idx].position.x = j;
				map->collect[idx].position.y = i;
				map->collect[idx].collected = 0;
				idx++;
			}
			j++;
		}
		i++;
	}
}

/* Free the memory allocated for the map */
void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->tiles[i]);
		i++;
	}
	free(map->tiles);
	free(map->collect);
}
