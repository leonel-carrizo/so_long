/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:48:07 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/07/18 11:43:02 by lcarrizo         ###   ########.fr       */
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

# define BC_BLACK "\033[1;30m"
# define BC_RED "\033[1;31m"
# define BC_GREEN "\033[1;32m"
# define BC_YELLOW "\033[1;33m"
# define BC_BLUE "\033[1;34m"
# define BC_PURPLE "\033[1;35m"
# define BC_CYAN "\033[1;36m"
# define BC_WHITE "\033[1;37m"

// TYPE STATUROR
# define FAIL 0
# define SUCCESS 1
# define GAME_OVER 0
# define USER_WIN 0
# define USER_CLOSES 0
# define USER_LOST 0
# define GAME_ERROR 2
# define MAP_ERROR 3
# define MLX_ERROR 4
# define SYS_ERROR 5

// INIT GAME ERRORS
# define INV_N_ARG 100
# define INV_MAP_FILE 101

// MAP ERRORS
# define INVAL_DIMENSIONS 120
# define FAIL_MAP_ALLOC 121
# define INVAL_N_ENTITIES 122
# define INVAL_WALL 123
# define INVAL_OBJECT 124
# define INAVAL_GAME 125
# define DOBLE_PLAYER 126
# define DOBLE_EXIT 127
# define NO_COLLECTABLE 128

// MLX ERROS
# define FAIL_CONNEC 130
# define FAIL_WIN 131

// SYSTEM ERROS
# define FAIL_MEM_ALLOC 141
# define FAIL_OPEN_FILE 142

// ERROR MESSAGES
# define MSG_YOU_WIN "🥳 Congratulations YOU WIN! 🥳\n"
# define MSG_YOU_LOST "💀 You lost, try again! 💀\n"
# define USER_EXIT "You have abandoned the game.\n"
# define MSG_INV_PATH "The player cannot access the exit or all collectibles.\n"
# define MSG_FAIL_WIN "Fail to create a new window.\n"
# define MSG_FAIL_CONNEC "Fail to set up the connection to the X server.\n"
# define MSG_INV_MAP_FILE "The map file is invalid. Check the path or file.\n"
# define MSG_INV_ARG "Usage: ./so_long <map_file.ber>\n"
# define MSG_FAIL_ALLOC "Failure to allocate memory for the map.\n"
# define MSG_FAIL_OPEN "Failure opening the map file. Check permissions.\n"
# define MSG_INV_DIM "The map must be rectangular.\n"
# define MSG_INV_N_ENTITIES "The map contains an invalid number of entities. \
	\nThe map must contain 1 player, 1 exit and 1 collectible.\n"
# define MSG_INV_WALL "The map is not surrounded by walls or blocks.\n"
# define MSG_INV_OBJ "The map contains an invalid object.\n"
# define MSG_DOB_EXIT "The map must not contain more than one EXIT.\n"
# define MSG_DOB_PLAYER "The map must not contain more than one PLAYER.\n"

#endif
