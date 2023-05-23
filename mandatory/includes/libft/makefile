# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeojeon <jeojeon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 09:21:27 by jeojeon           #+#    #+#              #
#    Updated: 2023/05/23 18:13:59 by jeojeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADERDIR = ./
HEADER = libft.h
SRCSDIR = ./
SRCS = $(addprefix $(SRCSDIR), \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c)
BONUS = $(addprefix $(SRCSDIR), \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c ft_stk.c ft_que.c ft_dque1.c ft_dque2.c \
		ft_delsplit.c ft_allocerr.c ft_rectangle_split.c)
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
ifdef BONUS_FLAG
	ALL_OBJS = $(OBJS) $(BONUS_OBJS)
else
	ALL_OBJS = $(OBJS)
endif
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

all : $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@ -I $(HEADERDIR)

$(NAME) : $(ALL_OBJS)
	$(AR) $@ $^

bonus :
	make BONUS_FLAG=1

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re
