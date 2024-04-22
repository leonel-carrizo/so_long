# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 17:53:32 by lcarrizo          #+#    #+#              #
#    Updated: 2024/04/22 21:47:35 by lcarrizo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################    SRCS/DIRECTORES   #############################

NAME			= so_long
LIBFT			= lib/libft/libft.a
LIBFT_DIR		= lib/libft/
MLX_URL			= https://github.com/42Paris/minilibx-linux/archive/refs/heads/master.zip
MLX			= mlx
MLX_DIR			= lib/libmlx/
INCLUDE			= include/
UTILS_DIR		= utils/
SRC_DIR			= src/
OBJ_DIR			= .obj/

SRCS_UTILS		= $(wildcard $(UTILS_DIR)*.c)
OBJ_UTILS		= $(addprefix $(OBJ_DIR)utils/, $(notdir $(SRCS_UTILS:.c=.o)))

SRCS			= $(wildcard $(SRC_DIR)*.c)
OBJ			= $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))

#############################    COMMANDS   ##################################

CC			= cc
RM 			= rm -rf
CFLAGS			= -Wall -Werror -Wextra -I$(INCLUDE)
MLXFLAGS		= -L$(MLX_DIR) -l$(MLX) -I$(MLX_DIR) -lXext - lX11 -lm

################################    RULES    ###################################

.SILENT:

all:			$(NAME)

$(LIBFT):
			@make -s -C $(LIBFT_DIR)

$(MLX):
			@wget -q -O ./libmlx.zip $(MLX_URL) 
			@unzip -q libmlx.zip
			@mv minilibx-linux-master $(MLX_DIR)
			$(RM) libmlx.zip
			@make -s -C $(MLX_DIR)

$(NAME):		$(MLX) $(LIBFT) $(OBJ) $(OBJ_UTILS)
			$(CC) $(CFLAGS) $(OBJ) $(OBJ_UTILS) $(LIBFT) $(MLXFLAGS) -o $(NAME) -g
			@echo "so_long executable created!"

$(OBJ_DIR)/%.o:		$(SRC_DIR)%.c
			@mkdir -p $(OBJ_DIR)
			@echo "Object Directory Created!"
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)utils/%.o:	$(UTILS_DIR)%.c
			@mkdir -p $(OBJ_DIR)/utils
			@echo "Object Utils Directory Created"
			$(CC) $(CFLAGS) -c $< -o $@

# create executables which can be debugged with gdb.
debug:			$(LIBFT) $(LIBMLX)
			$(CC) $(CFLAGS) $(SRCS) $(wildcard $(UTILS_DIR)/*.c) $(LIBFT) $(LIBMLX) -o $(NAME) -g
			@echo "Debugables Created!"

clean:		
			$(RM) $(OBJ_DIR)
			@make -s -C $(LIBFT_DIR) clean
			@make -s -C $(MLX_DIR) clean
			@echo "** clean so_long done!**"
			
fclean:			clean
			$(RM) $(NAME)
			@make -s -C $(LIBFT_DIR) fclean
			@$(RM) lib/libmlx
			@echo "** full clean so_long done!**"

re:			fclean all

.PHONY: all clean fclean re
