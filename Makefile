# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: evoronin <evoronin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/03 11:47:21 by evoronin      #+#    #+#                  #
#    Updated: 2023/02/20 17:09:48 by evoronin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	pipex.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
CFLAGS = -I libft

all: $(NAME)

$(NAME): $(SRCS)
	make -C libft
	@$(CC) $(FLAGS) $(CFLAGS) $(LIBFT) $< -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean re all  #bonus when bonus