/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:44:18 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/22 17:39:13 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* Allocates memory for the map with the specified dimensions */
void	allocate_map(t_map *map, int width, int height)
{
	int	i;

	map->tiles = (char **)malloc(height * sizeof(char *));
	i = 0;
	while (i < height)
	{
		map->tiles[i] = (char *)malloc((width + 2) * sizeof(char));
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
			map->width = ft_strlen(line) - 1;
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

/* Load the map from the specified file */
void	load_map(t_game *game, char *file_path)
{
	int	valid_map;

	count_map_dimensions(&game->map, file_path);
	allocate_map(&game->map, game->map.width, game->map.height);
	fill_map(&game->map, file_path);
	parse_map_entities(game);
	valid_map = check_valid_map(game);
	if (!valid_map)
	{
		ft_printf("Error:\nThe map is not valid, try different a file.\n");
		free_map(&game->map);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(1);
	}
}
