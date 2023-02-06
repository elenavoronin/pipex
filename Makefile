# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: evoronin <evoronin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/03 11:47:21 by evoronin      #+#    #+#                  #
#    Updated: 2023/02/06 13:12:07 by evoronin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	

OBJS = $(SRCS:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	@$(CC) -c $(FLAGS) $<

$(NAME): $(OBJS)
	@ ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
