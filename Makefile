# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/21 10:49:22 by stakaki           #+#    #+#              #
#    Updated: 2021/07/21 11:42:27 by stakaki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER_NAME = server

CLIENT_NAME = client

SRCS = server.c\
	   client.c\

OBJ = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_NAME): $(OBJ)
	ar rc $(SERVER_NAME) server.o

$(CLIENT_NAME): $(OBJ)
	ar rc $(CLIENT_NAME) client.o

$(NAME): $(SERVER_NAME) $(CLIENT_NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(SERVER_NAME)
	rm -f $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re

