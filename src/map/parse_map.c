/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:42:10 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/17 15:05:00 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
	i = -1;
	while (++i < map->height)
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
