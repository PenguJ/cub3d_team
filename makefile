# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/21 22:25:00 by jeojeon           #+#    #+#              #
#    Updated: 2023/05/27 13:58:18 by jeojeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
MAND_SRCSDIR = ./mandatory/srcs/
MAND_SRCS = $(addprefix $(MAND_SRCSDIR), \
			main.c \
			create_mlx_win_imgs.c \
			create_screen_img.c \
			exit_process.c \
			game.c \
			init_s_info_2.c \
			init_s_info_3.c \
			init_s_info.c \
			parse_info.c \
			parse_map__check_map.c \
			parse_map__get_map_0.c \
			parse_map__get_map_1.c \
			parse_map.c \
			parse_objs__rgb.c \
			parse_objs__texture.c \
			parse_objs.c \
			parse_uility.c \
			TESTCODE_delete!!!.c \
			)
MAND_OBJS = $(MAND_SRCS:.c=.o)
MAND_INCLUDESDIR = ./mandatory/includes/
RM = rm -f

all : $(NAME)

$(NAME) : $(MAND_OBJS)
	make -C $(MAND_INCLUDESDIR)libft bonus
	make -C $(MAND_INCLUDESDIR)mlx all
	mv $(MAND_INCLUDESDIR)mlx/libmlx.dylib ./
	$(CC) $(CFLAGS) -o $@ $^\
		-L$(MAND_INCLUDESDIR)libft/ -lft \
		-L./ -lmlx \
		-framework OpenGL \
		-framework Appkit
	make -C $(MAND_INCLUDESDIR)libft fclean
	make -C $(MAND_INCLUDESDIR)mlx clean

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(MAND_OBJS)

fclean :
	make clean
	$(RM) $(NAME) libmlx.dylib

re :
	make fclean
	make all

.PHONY : all clean fclean re
