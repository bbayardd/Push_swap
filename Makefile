# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbayard <bbayard@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 21:48:44 by bbayard           #+#    #+#              #
#    Updated: 2021/12/15 21:00:17 by bbayard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	push_swap.c libft.c ft_split.c check_valid_arg.c \
		rules_of_sort_00.c rules_of_sort_01.c sort_00.c \
		sort_01.c stack_manip.c push_w.c \

INCLUDE = push_swap.h

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : 
	$(CC) $(CFLAGS) $(SRCS) -I./include -o $(NAME)

clean :
	@rm -rf 

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean re all