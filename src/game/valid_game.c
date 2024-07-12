/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:13:23 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/07/11 04:01:50 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* Create an array with all its values ​​set to 0.
It is a mirror of the possible positions to mark each position
that has been visited with 1 and prevent the algorithm from entering
an infinite loop or repeating the checks. */
static int	**create_matrix(t_map map)
{
	int	i;
	int	j;
	int	**temp;

	i = 0;
	temp = malloc((map.height - 1) * sizeof(int *));
	while (i < (map.height - 1))
	{
		temp[i] = malloc((map.width - 1) * sizeof(int));
		if (!temp[i])
		{
			j = 0;
			while (j < i)
			{
				free(temp[j]);
				j++;
			}
			free(temp);
			return (0);
		}
		ft_memset(temp[i], 0, (map.width - 1) * sizeof(int));
		i++;
	}
	return (temp);
}

/* Validates if a square in the current position
 is within the navigable limits of the map */
static int	is_valid_position(t_map map, int row, int col)
{
	if ((row >= 1 && row < map.height - 1 && col >= 1 && col < map.width - 1)
		&& map.tiles[row][col] != WALL)
	{
		return (1);
	}
	return (0);
}

/* 	Defines the movements that the algorithm will move.
	Up, down, left and right respectively.
 */
static int	moves(int i, int j)
{
	int	movement[4][2];

	movement[0][0] = -1;
	movement[1][0] = 1;
	movement[3][0] = 0;
	movement[2][0] = 0;
	movement[0][1] = 0;
	movement[1][1] = 0;
	movement[2][1] = -1;
	movement[3][1] = 1;
	return (movement[i][j]);
}

/*	Explore the map for all the collectibles and the exit door
	by going through each valid position within the limits of the map
	and when it is not a block or wall. (DFS Algorithm)
	Returns 1 if at the end manages to collect all the collectibles
	and reach the exit door */
static int	dfs_explore(t_map map, int row, int col, int **visited)
{
	int			i;
	int			new_row;
	int			new_col;
	static int	found_exit = 0;
	static int	collectible = 0;

	visited[row][col] = 1;
	if (is_valid_position(map, row, col) && map.tiles[row][col] == MAP_EXIT)
		found_exit = 1;
	else if (map.tiles[row][col] == COLLECTIBLE)
		collectible++;
	if (collectible == map.n_collect && found_exit == 1)
		return (1);
	i = -1;
	while (++i < 4)
	{
		new_row = row + moves(i, 0);
		new_col = col + moves(i, 1);
		if ((is_valid_position(map, new_row, new_col))
			&& !visited[new_row][new_col])
			if (dfs_explore(map, new_row, new_col, visited))
				return (1);
	}
	return (0);
}

/* Check if there is a valid path to collect all the collectibles
 and reach the exit */
int	check_valid_path(t_game *game)
{
	int	player_row;
	int	player_col;
	int	**visited;
	int	found;
	int	i;

	player_row = game->player.position.y;
	player_col = game->player.position.x;
	found = 0;
	visited = create_matrix(game->map);
	if (!visited)
		return (0);
	found = dfs_explore(game->map, player_row, player_col, visited);
	i = 0;
	while (i < (game->map.height - 1))
	{
		free(visited[i]);
		i++;
	}
	free(visited);
	return (found);
}
