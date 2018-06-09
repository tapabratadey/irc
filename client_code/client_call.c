/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_call.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:04:16 by tadey             #+#    #+#             */
/*   Updated: 2018/06/08 15:04:17 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

void	recv_from_server(t_client *client, char *buff)
{
	if ((client->ret_from_server = recv(client->client_socket, buff,
	4096, 0)) <= 0)
	{
		printf("%d", client->ret_from_server);
		error("Couldn't receive a response from server.\n");
		return ;
	}
}

void	prompts(char **line, char ***store, t_client *client)
{
	*(line) = ft_strnew(1);
	ft_putstr("->");
	*(line) = read_user(*line);
	if_quit(client, *line);
	*(store) = ft_strsplit(*line, ' ');
}

void	client_call(t_client *client)
{
	char	*line;
	char	**store;
	int		flag;
	char	buff[4096];

	line = NULL;
	store = NULL;
	flag = 0;
	prompts(&line, &store, client);
    recv_from_server(client, buff);
    buff[client->ret_from_server] = '\0';
    printf("%s\n", buff);
    clear_buff(buff, 4096);
}
