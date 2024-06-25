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

/*	preliminar checks, if map is not square, game exit.
	By closing the file and calling get_netx_line(),
	it ensures free of memory allocated in its buffer.
*/
void	pre_checks(t_game *game, char *line, int fd)
{
	int	len;
	int	char_ok;

	len = -1;
	char_ok = 1;
	while (line[++len])
	{
		if (line[len] != '1' && line[len] != '0' && line[len] != 'C'
			&& line[len] != 'P' && line[len] != 'E' && line[len] != '\n')
			char_ok = 0;
	}
	// TODO: if char is ok, check if it is in the correct place in the map.
	if (game->map.height == 1 && char_ok == 1)
		char_ok = 0;
	if (game->map.width != len - 1 || char_ok == 0)
	{
		free(line);
		close(fd);
		line = get_next_line(fd);
		ft_putstr_fd("Error:\nInvalid Map.\n",
			STDERR_FILENO);
		exit_game(game);
	}
}

/* checks that map given is a valid map. Return 1 if true, if not, return 0 */
int	check_valid_map(t_game *game)
	// TODO
{
	(void)game;
	return (1);
}
