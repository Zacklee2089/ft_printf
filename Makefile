# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchun-jh <lchun-jh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 15:15:12 by lchun-jh          #+#    #+#              #
#    Updated: 2022/11/07 20:06:17 by lchun-jh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
AR = ar rcs
RM = rm -f

FILES = ft_printf_utils \
			ft_printf \
			ft_printptr \
			ft_printhex \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $@ $^

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY : all clean fclean bonus re
