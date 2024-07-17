/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:48:07 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/07/15 14:48:42 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROS_H
# define ERROS_H

// MESAGE COLORS
# define C_DEFAULT "\033[0;39m"
# define C_BLACK "\033[0;30m"
# define C_RED "\033[0;31m"
# define C_GREEN "\033[0;32m"
# define C_YELLOW "\033[0;33m"
# define C_BLUE "\033[0;34m"
# define C_PURPLE "\033[0;35m"
# define C_CYAN "\033[0;36m"
# define C_WHITE "\033[0;37m"

# define B_C_BLACK "\033[1;30m"
# define B_C_RED "\033[1;31m"
# define B_C_GREEN "\033[1;32m"
# define B_C_YELLOW "\033[1;33m"
# define B_C_BLUE "\033[1;34m"
# define B_C_PURPLE "\033[1;35m"
# define B_C_CYAN "\033[1;36m"
# define B_C_WHITE "\033[1;37m"

// TYPE STATUS
# define GAME_OVER 100
# define GAME_ERROR -200
# define MAP_ERROR -300
# define RENDER_ERROR -400
# define MLX_ERROR -500
# define SYS_ERROR -600

// SUCCESS
# define SUCCESS 101
# define USER_WIN 102
# define USER_LOST 103
# define USER_CLOSES 104

// INIT GAME ERRORS
# define INV_N_ARG -201
# define INV_MAP_ARG -202

// MAP ERRORS
# define INVAL_DIMENTIONS -303
# define FAIL_MAP_ALLOC -302
# define INVAL_N_ENTITIES -304
# define INVAL_WALL -305
# define INVAL_OBJECT -306
# define INAVAL_GAME -307
# define DOBLE_PLAYER -308
# define DOBLE_EXIT -309
# define NO_COLLECTABLE -310

// MLX ERROS
# define FAIL_CONNEC -501
# define FAIL_WIN -502

// SYSTEM ERROS
# define FAIL_OPEN_FILE -601
# define FAIL_MEM_ALLOC -602

#endif
