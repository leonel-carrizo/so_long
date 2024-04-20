# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 17:53:32 by lcarrizo          #+#    #+#              #
#    Updated: 2024/04/20 18:03:30 by lcarrizo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################    SRCS/DIRECTORES   #############################

NAME			= so_long
LIBFT			= lib/libft/libft.a
LIBFT_DIR		= lib/libft/
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

################################    RULES    ###################################

.SILENT:

all:			$(NAME)

$(LIBFT):
			@make -s -C $(LIBFT_DIR)

$(NAME):		$(LIBFT) $(OBJ) $(OBJ_UTILS) 
			$(CC) $(CFLAGS) $(OBJ) $(OBJ_UTILS) $(LIBFT) -o $(NAME)  -g
			@echo "Server executable created!"

$(OBJ_DIR)/%.o:		$(SRC_DIR)%.c
			@mkdir -p $(OBJ_DIR)
			@echo "Object Directory Created!"
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)utils/%.o:	$(UTILS_DIR)%.c
			@mkdir -p $(OBJ_DIR)/utils
			@echo "Object Utils Directory Created"
			$(CC) $(CFLAGS) -c $< -o $@

# create executables which can be debugged with gdb.
debug:			$(LIBFT)
			$(CC) $(CFLAGS) $(SRCS) $(wildcard $(UTILS_DIR)/*.c) $(LIBFT) -o $(NAME) -g
			@echo "Debugables Created!"

clean:		
			$(RM) $(OBJ_DIR)
			@make -s -C $(LIBFT_DIR) clean
			@echo "** clean minitalk done!**"
			
fclean:			clean
			$(RM) $(NAME)
			$(RM) ./libft.a
			@make -s -C $(LIBFT_DIR) fclean
			@echo "** full clean minitalk done!**"

re:			fclean all

.PHONY: all clean fclean re
