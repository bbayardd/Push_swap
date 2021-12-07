NAME = push_swap

SRCS =	push_swap.c libft.c ft_split.c check_valid_arg.c

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