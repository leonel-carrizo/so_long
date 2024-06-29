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
void	allocate_map(t_map *map, int width, int height)
{
	int	i;

	map->tiles = (char **)malloc(height * sizeof(char *));
	if (!map->tiles)
		return ;
	i = 0;
	while (i < height)
	{
		map->tiles[i] = (char *)ft_calloc(width, ((width + 2) * sizeof(char)));
		if (!map->tiles[i])
			return ;
		i++;
	}
}

/* Fill the map with the data from the file */
void	fill_map(t_game *game, char *file_path)
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
		ft_strcpy(game->map.tiles[i], line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
}

/*	Check that the map has valid entities,
that they are in the allowed position
and that units that must be unique are not repeated. */
static int	pre_checks(t_game *game, char *line, char **str, int ok[])
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

/* Count map dimensions from file */
int	count_map_dimensions(t_game *game, char *file_path)
{
	int			fd;
	char		*line;
	static int	ok = 1;
	static char	*temp = NULL;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	game->map.width = ft_strlen(line) - 1;
	while (pre_checks(game, line, &temp, &ok) && ok && line != NULL)
	{
		game->map.height++;
		free(line);
		line = NULL;
		if (!ok)
			close(fd);
		line = get_next_line(fd);
	}
	close(fd);
	get_next_line(fd);
	if (ok == 0)
		return (0);
	return (1);
}

/* Load the map from the specified file */
void	load_map(t_game *game, char *file_path)
{
	int	valid_map;

	if (!count_map_dimensions(game, file_path))
	{
		ft_putstr_fd("Error:\nMap content is not valid.\n", 2);
		exit_game(game);
	}
	allocate_map(&game->map, game->map.width, game->map.height);
	fill_map(game, file_path);
	parse_map_entities(game);
	valid_map = check_valid_map(game);
	if (!valid_map)
	{
		ft_printf("Error:\nThe map is not valid, try different a file.\n");
		exit_game(game);
	}
}
