# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csekakul <csekakul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/19 08:58:28 by csekakul          #+#    #+#              #
#    Updated: 2026/03/25 13:46:16 by csekakul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	main.c \
		parsing.c \
		stack.c \
		swap.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		sort_small.c \
		utils.c \
		sort_helpers.c \
		split.c \
		indexing.c \
		strategy.c \
		adaptive_sort.c \
		simple_sort.c \
		medium_sort.c \
		k_sort.c \
		complex_sort.c \
		io_helpers.c \
		bench.c

OBJ = $(SRC:.c=.o)
HEADER = push_swap.h
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
