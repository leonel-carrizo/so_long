/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:46:32 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/07/15 13:46:35 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_error_message(int errnum)
{
	if (errnum == INV_N_ARG)
			ft_printf("%sError:\nUsage: ./so_long <map_file.ber>\n", C_RED);
	else if (errnum == INV_MAP_ARG)
			ft_printf("%sError:\nThe map file is invalid. \
			Check the extension or path.\n", C_RED);
	else if (errnum == FAIL_CONNEC)
		ft_printf("%sError:\nfails to set up the connection to the X server\n",
			C_RED);
	else if ( errnum == FAIL_WIN)
		ft_printf("%sError:\nFail to create a new window\n", C_RED);
}
