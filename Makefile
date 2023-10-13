# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sikulnok <sikulnok@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 16:26:39 by sikulnok          #+#    #+#              #
#    Updated: 2023/10/14 00:17:01 by sikulnok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = srcs/*.c
INCLUDE = include/

OBJS = *.o

CC = cc
CFLAGS = -Wall -Werror -Wextra

$(NAME):
		$(CC) $(CFLAGS) -c $(SRCS) -I $(INCLUDE)
		ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


