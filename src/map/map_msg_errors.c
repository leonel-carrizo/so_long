/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:46:08 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/07/15 13:46:12 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_error_message(int errnum)
{
	if (errnum == FAIL_MAP_ALLOC)
			ft_printf("%sError:\nFailure to allocate memory for the map.\n", C_RED);
	else if (errnum ==  FAIL_OPEN_FILE)
			ft_printf("%sError:\nFailure when trying to open the map file. \
			Check the extension or path file.\n", C_RED);
	else if (errnum == INVAL_DIMENTIONS)
		ft_printf("%sError:\nMap contains invalid proportion. \
			It must be rectangular.\n", C_RED);
	else if (errnum == INVAL_N_ENTITIES)
		ft_printf("%sError:\nThe map contains an invalid number of entities.\n", C_RED);
	else if ( errnum == INVAL_WALL)
		ft_printf("%sError:\nThe map is not surrounded by walls or blocks.\n", C_RED);
}