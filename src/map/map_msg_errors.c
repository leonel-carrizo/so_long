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
		ft_printf("%sError:\n%s%s", BC_RED, C_YELLOW, MSG_FAIL_ALLOC);
	else if (errnum == FAIL_OPEN_FILE)
		ft_printf("%sError:\n%s%s", BC_RED, C_YELLOW, MSG_FAIL_OPEN);
	else if (errnum == INVAL_DIMENSIONS)
		ft_printf("%sError:\n%s%s", BC_RED, C_YELLOW, MSG_INV_DIM);
	else if (errnum == INVAL_N_ENTITIES)
		ft_printf("%sError:\n%s%s", BC_RED, C_YELLOW, MSG_INV_N_ENTITIES);
	else if (errnum == INVAL_WALL)
		ft_printf("%sError:\n%s%s", BC_RED, C_YELLOW, MSG_INV_WALL);
	else if (errnum == INVAL_OBJECT)
		ft_printf("%sError:\n%s%s", BC_RED, C_YELLOW, MSG_INV_OBJ);
	else if (errnum == DOBLE_EXIT)
		ft_printf("%sError:\n%s%s", BC_RED, C_YELLOW, MSG_DOB_EXIT);
	else if (errnum == DOBLE_PLAYER)
		ft_printf("%sError:\n%s%s", BC_RED, C_YELLOW, MSG_DOB_PLAYER);
}
