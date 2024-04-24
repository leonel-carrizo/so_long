/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:17:10 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/04/24 12:56:52 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	(void)argv;
	(void)argc;
	void	*mlx;
	void	*img;

	mlx = mlx_init();
	img = mlx_new_image(mlx, 800, 600);

	mlx_loop(mlx);
	(void)img;
}
