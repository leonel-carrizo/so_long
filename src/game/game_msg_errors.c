/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:45:37 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/07/15 14:22:16 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	game_error_message(int errnum)
{
	if (errnum == INV_N_ARG)
		ft_printf("%sError:\n%s%s", BC_RED, C_YELLOW, MSG_INV_ARG);
	else if (errnum == INV_MAP_ARG)
		ft_printf("%sError:\n%s%s", BC_RED, C_YELLOW, MSG_INV_MAP_FILE);
	else if (errnum == FAIL_CONNEC)
		ft_printf("%sError:\n%s%s", BC_RED, C_YELLOW, MSG_FAIL_CONNEC);
	else if (errnum == FAIL_WIN)
		ft_printf("%sError:\n%s%s", BC_RED, C_YELLOW, MSG_FAIL_WIN);
	else if (errnum == INAVAL_GAME)
		ft_printf("%sError:\n%s%s", BC_RED, C_YELLOW, MSG_INV_PATH);
}
