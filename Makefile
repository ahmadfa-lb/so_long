# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 06:09:53 by afarachi          #+#    #+#              #
#    Updated: 2024/08/03 14:57:36 by afarachi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
BONUS_NAME		=	so_long_bonus

MANDATORY_DIR	=	mandatory/
BONUS_DIR 		=	bonus/
GNL_DIR			=	libft/get_next_line/
LIBFTPATH 		=	libft
LIBFT 			= 	libft/libft.a
MLX				=   minilibx-linux/

SRCS			=	${MANDATORY_DIR}map_validation1.c \
					${MANDATORY_DIR}free.c \
					${MANDATORY_DIR}keys_management.c \
					${MANDATORY_DIR}maps.c \
					${MANDATORY_DIR}so_long.c \
					${MANDATORY_DIR}utils.c \
					${MANDATORY_DIR}game.c \
					${MANDATORY_DIR}movements_AWDS.c \
					${MANDATORY_DIR}map_validation2.c \
    				${GNL_DIR}get_next_line.c \
    				${GNL_DIR}get_next_line_utils.c

SRCS_BONUS 		=   ${BONUS_DIR}enemy_bonus.c \
					${BONUS_DIR}enemy_movements_bonus.c \
					${BONUS_DIR}free_bonus.c \
					${BONUS_DIR}game_bonus.c \
					${BONUS_DIR}keys_management_bonus.c \
					${BONUS_DIR}map_validation1_bonus.c \
					${BONUS_DIR}map_validation2_bonus.c \
					${BONUS_DIR}maps_bonus.c \
					${BONUS_DIR}movements_AWDS_bonus.c \
					${BONUS_DIR}so_long_bonus.c \
					${BONUS_DIR}utils_bonus.c

OBJS 			=	$(SRCS:.c=.o)
OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)

CC 				=	cc
CFLAGS 			=	-Wall -Wextra -Werror
MLXFLAGS		=	-L ./minilibx-linux/ -lmlx -Ilmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTPATH)
	make -C $(MLX)
	$(CC) $(OBJS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS)
	make -C $(LIBFTPATH)
	make -C $(MLX)	
	$(CC) $(OBJS_BONUS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(BONUS_NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	make -C $(LIBFTPATH) clean
	make -C $(MLX) clean
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	make -C $(LIBFTPATH) fclean
	make -C $(MLX) clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

rebonus: fclean bonus

bonus-re: fclean bonus

.PHONY: all clean fclean re







