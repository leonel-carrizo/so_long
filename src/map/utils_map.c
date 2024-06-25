/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:19:49 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/25 14:50:38 by lcarrizo         ###   ########.fr       */
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
int	pre_checks(t_game *game, char *line, int fd)
{
	int	len;
	int 	i;
	int	char_ok;
	static char	*temp ;

	len = game->map.width;
	char_ok = 1;
	i = 1;
	while (line && line[--len])
	{
		if ((line[len] == '0' || line[len] == 'C' || line[len] == 'P'|| line[len] == 'E')
			&& (game->map.height == 1 || len == 0 || line[len] == '\n'))
			char_ok = 0;
		if (line[len] != '1' && line[len] != '0' && line[len] != 'C'
			&& line[len] != 'P' && line[len] != 'E' && line[len] != '\n')
			char_ok = 0;
		i++;
	}
	if (((line && game->map.width - len != i) || char_ok == 0) || (char_ok && !line))
	{
		if (!line && temp)
			pre_checks(game, temp, fd);
		free(line);
		close(fd);
		line = get_next_line(fd);
		ft_putstr_fd("Error:\nInvalid Map.\n",
			STDERR_FILENO);
		exit_game(game);
	}
	if (!temp)
		temp = (char *)malloc(sizeof(char) * (game->map.width + 2));
	if (line)
		ft_strcpy(temp,line);
	else
	{
		free(temp);
		return (0);
	}
	return (1);
}

/* checks that map given is a valid map. Return 1 if true, if not, return 0 */
int	check_valid_map(t_game *game)
	// TODO
{
	(void)game;
	return (1);
}
