# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/21 10:49:22 by stakaki           #+#    #+#              #
#    Updated: 2021/07/21 12:52:43 by stakaki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER_NAME = server

CLIENT_NAME = client

OBJ = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(SERVER_NAME) server.c
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) client.c

clean:
	rm -f $(SERVER_NAME)
	rm -f $(CLIENT_NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

