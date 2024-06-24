# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 17:53:32 by lcarrizo          #+#    #+#              #
#    Updated: 2024/06/24 12:02:33 by lcarrizo         ###    ###london.com     #
#                                                                              #
# **************************************************************************** #

############################    SRCS/DIRECTORES   #############################
NAME			= so_long
LIBFT			= lib/libft/libft.a
LIBFT_DIR		= lib/libft/
MLX_URL			= https://github.com/42Paris/minilibx-linux/archive/refs/heads/master.zip
MLX_ZIP			= libmlx.zip
MLX			= $(MLX_DIR)
MLX_DIR			= lib/libmlx/
INCLUDE			= includes/
UTILS_DIR		= utils/
SRC_DIR			= src/
OBJ_DIR			= .obj/

SRCS_UTILS		= $(wildcard $(UTILS_DIR)*.c)
OBJ_UTILS		= $(addprefix $(OBJ_DIR)utils/, $(notdir $(SRCS_UTILS:.c=.o)))

SRCS			= $(shell find $(SRC_DIR) -name "*.c")
OBJ			= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

#############################    COMMANDS   ##################################
CC			= cc
RM 			= rm -rf
CFLAGS			= -Wall -Werror -Wextra -I$(INCLUDE)
MLXFLAGS		= -L$(MLX_DIR) -I$(MLX_DIR) -lXext -lX11 -lmlx

################################    RULES    ###################################
.SILENT:

$(NAME):		$(MLX) $(OBJ) $(LIBFT) $(OBJ_UTILS)
			$(CC) $(CFLAGS) $(OBJ) $(OBJ_UTILS) $(LIBFT) $(MLXFLAGS) -o $(NAME) -g
			@echo "so_long executable created!"

all:			$(NAME)

$(MLX):			$(MLX_ZIP)
			@if [ ! -e $(MLX_DIR) ]; then \
				unzip -q $(MLX_ZIP); \
				mv minilibx-linux-master $(MLX_DIR); \
				make -s -C $(MLX_DIR); \
			fi

$(MLX_ZIP):
			@if [ ! -e $(MLX_ZIP) ]; then \
				echo "Downloading Minilibx..."; \
				wget -q -O $(MLX_ZIP) $(MLX_URL); \
			else echo "Minilibx Downloaded."; fi

$(LIBFT):
				@make -s -C $(LIBFT_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)utils/%.o:		$(UTILS_DIR)%.c
				@mkdir -p $(OBJ_DIR)/utils
				$(CC) $(CFLAGS) -c $< -o $@

# create executables which can be debugged with gdb.
debug:				$(LIBFT) $(LIBMLX)
				$(CC) $(CFLAGS) $(SRCS) $(wildcard $(UTILS_DIR)/*.c) $(LIBFT) $(MLXFLAGS) $(LIBMLX) -o $(NAME) -g
					@echo "Debugables Created!"

clean:
				$(RM) $(OBJ_DIR)
				@make -s -C $(LIBFT_DIR) clean
				@echo "** clean so_long done!**"

fclean:				clean
				$(RM) $(NAME)
				@make -s -C $(LIBFT_DIR) fclean
				-@make -s -C $(MLX_DIR) clean
				-@$(RM) $(MLX_DIR)
				-@$(RM) $(MLX_ZIP)
				@echo "** full clean so_long done!**"

re:				fclean all

.PHONY: 			all clean fclean re debug
