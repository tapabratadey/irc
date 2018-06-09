# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tadey <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/08 15:03:42 by tadey             #+#    #+#              #
#    Updated: 2018/06/08 15:03:43 by tadey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
FLAGS = -Wall -Wextra -Werror
LIBFT = -L libft/ -lft
CLI = client_code/*.c
SRV = server_code/*.c
CC = gcc

all: $(SERVER) $(CLIENT)

$(SERVER):
	$(CC) -g $(FLAGS) $(LIBFT) $(SRV) -o $(SERVER)

$(CLIENT):
	$(CC) -g $(FLAGS) $(LIBFT) $(CLI) -o $(CLIENT)

fclean:
	rm -f $(SERVER) $(CLIENT)

re: fclean all
