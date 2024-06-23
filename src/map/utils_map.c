/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:19:49 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/23 14:19:51 by lcarrizo         ###    ###london.com    */
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

/*	preliminar checks, if while filling map wrong tile is found, game exit.
	By closing the file and calling get_netx_line(),
	it ensures free of memory allocated in its buffer.
*/
void	check_map_char(t_game *game, char *line, int fd)
{
	int	i;

	i = ft_strlen((const char *)line) - 1;
	while (i >= 0)
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'C'
			&& line[i] != 'P' && line[i] != 'E' && line[i] != '\n')
		{
			free(line);
			close(fd);
			line = get_next_line(fd);
			ft_putstr_fd("Error:\nInvalid char found in the map given.\n",
				STDERR_FILENO);
			exit_game(game);
		}
		i--;
	}
}

/*	preliminar checks, if map is not square, game exit.
	By closing the file and calling get_netx_line(),
	it ensures free of memory allocated in its buffer.
*/
void	is_map_square(t_game *game, char *line, int fd)
{
	int	nlen;

	nlen = ft_strlen((const char *)line) - 1;
	if (game->map.width != nlen)
	{
		free(line);
		close(fd);
		line = get_next_line(fd);
		ft_putstr_fd("Error:\nMap with invalid proportions.\n",
			STDERR_FILENO);
		exit_game(game);
	}
}

/* checks that map given is a valid map. Return 1 if true, if not, return 0 */
int	check_valid_map(t_game *game)
	/* TODO */
{
	(void)game;
	return (1);
}
