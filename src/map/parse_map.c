/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:42:10 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/06/29 15:18:42 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* Initializes the positions of the entities on the map */
void	init_entities_positions(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.tiles[i][j] == PLAYER)
			{
				game->player.position.x = j;
				game->player.position.y = i;
			}
			else if (game->map.tiles[i][j] == MAP_EXIT)
			{
				game->map.exit.pos.x = j;
				game->map.exit.pos.y = i;
			}
			else if (game->map.tiles[i][j] == COLLECTIBLE)
				game->map.n_collect++;
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
			if (map->tiles[i][j] == COLLECTIBLE)
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

/* 	Analyzes the entities on the map
	(player, collectibles, exit door, start door) */
void	parse_map_entities(t_game *game)
{
	init_entities_positions(game);
	init_collectibles(&game->map);
	if (game->player.n_moves == 0)
	{
		game->map.start.pos.x = game->player.position.x;
		game->map.start.pos.y = game->player.position.y;
		game->map.start.bussy = 1;
	}
}
