SERVER = server
CLIENT = client
FLAGS = -Wall -Wextra -Werror
LIBFT = -L libft/ -lft
CLI = client_code/*.c
SRV = server_code/*.c
CC = gcc

all: $(SERVER) $(CLIENT)

$(SERVER):
	$(CC) -g $(FLAGS) $(LIBFT) server.c $(SRV) -o $(SERVER)

$(CLIENT):
	$(CC) -g $(FLAGS) $(LIBFT) client.c $(CLI) -o $(CLIENT)

fclean:
	rm -f $(SERVER) $(CLIENT)

re: fclean all