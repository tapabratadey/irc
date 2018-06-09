/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:04:00 by tadey             #+#    #+#             */
/*   Updated: 2018/06/08 15:04:02 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

// void	chat(t_server *server)
// {

// }

// void	add_connection(int cli_fd)
// {

// }

// void	read_data_reply()
// {

// }

void enter_name(int cli_fd, struct sockaddr_in cli_addr, t_server *server)
{
	ft_putstr("Connection accepted.\n");
	if (write(cli_fd, "Enter name: ", 12) >= 0)
	{
		printf("-- New Connection %d from %s:%hu\n", cli_fd,
			   inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
		FD_SET(cli_fd, &server->status);
		// add_connection(cli_fd);
	}
}

void loop_fd(t_server *server, struct sockaddr_in *cli_addr, socklen_t addr_len)
{
	int i;
	int cli_fd;

	i = 0;
	ft_putstr("hello1");
	while (i < 1024)
	{
		ft_putstr("hello2");
		if (FD_ISSET(i, &server->current))
		{
			ft_putstr("hello3");
			if (i == server->server_socket)
			{
				ft_putstr("hello4");
				if ((cli_fd = accept(server->server_socket,
					(struct sockaddr *)&cli_addr, &addr_len)) < 0)
					error("Couldn't accept connection.\n");
				else if (cli_fd > 1024)
					error("Can't accept new connections.\n");
				else
					enter_name(cli_fd, *cli_addr, server);
			}
		}
		// else
		// 	read_data_reply();
		i++;
	}
}

void server_loop(t_server *server)
{
	struct sockaddr_in cli_addr;
	socklen_t		   addr_len;

	if ((listen(server->server_socket, 10)) == -1)
		error("Couldn't listen on the port.\n");
	addr_len = sizeof(cli_addr);
	FD_ZERO(&server->status);
	FD_SET(server->server_socket, &server->status);
	FD_SET(0, &server->status);
	server->current = server->status;
	while (1)
	{
		ft_putstr("hello");
		if (select(1024, &server->current, NULL, NULL, NULL) == -1)
			error("Select error.\n");
		loop_fd(server, &cli_addr, addr_len);
	}
}

void create_client_server(t_server *server)
{
	struct sockaddr_in serv_addr;

	if ((server->server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		error("Couldn't create a socket.\n");
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(server->port);
	if (bind(server->server_socket, (struct sockaddr *)&serv_addr,
			 sizeof(serv_addr)) == -1)
	{
		printf("%s", strerror(errno));
		error("Couldn't bind to port.\n");
	}
	ft_putstr("Connected to port.\n");
	server_loop(server);
}

int main(int argc, char **argv)
{
	t_server *server;

	server = (t_server *)malloc(sizeof(t_server));
	if (argc != 2)
		error("Usage: ./server <port>\n");
	server->port = ft_atoi(argv[1]);
	create_client_server(server);
	close(server->server_socket);
	return (0);
}

#if 0
void	server_loop(t_server *server)
{
	int					cli_fd;
	struct sockaddr_in	cli_addr;
	socklen_t			addr_len;
	int					in_client;

	listen(server->server_socket, 10);
	in_client = 1;
	addr_len = sizeof(cli_addr);
	while (1)
	{
		if ((cli_fd = accept(server->server_socket,
		(struct sockaddr *)&cli_addr, &addr_len)) < 0)
			error("Couldn't accept connection.\n");
		printf("Connection accepted.\n\n");
		// if (fork() == 0)
		// {
		// 	ft_putendl("Forking for client");
		// 	while (in_client)
		// 		get_from_client(server, cli_fd);
		// }
	}
}

void	create_client_server(t_server *server)
{
	struct sockaddr_in serv_addr;

	if ((server->server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		error("Couldn't create a socket.\n");
	printf("Server socket is created...\n");
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(server->port);
	if (bind(server->server_socket, (struct sockaddr *)&serv_addr,
	sizeof(serv_addr)) == -1)
	{
		printf("%s", strerror(errno));
		error("Couldn't bind to port.\n");
	}
	printf("Connected to port...\n");
	server_loop(server);
}

int		main(int argc, char **argv)
{
	t_server *server;

	server = (t_server *)malloc(sizeof(t_server));
	if (argc != 2)
		error("Usage: ./server <port>\n");
	server->port = ft_atoi(argv[1]);
	create_client_server(server);
	close(server->server_socket);
	return (0);
}
#endif
