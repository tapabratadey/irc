/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:05:23 by tadey             #+#    #+#             */
/*   Updated: 2018/06/08 15:05:24 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
#define SERVER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/param.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/select.h>
#include <netinet/ip.h>
#include "../libft/libft.h"

#define FD_MAX 1024

typedef struct s_server
{
    int server_socket;
    int port;
    int ret_recv;
	fd_set status;
	fd_set current;
}   t_server;


//server
void    server_loop(t_server *server);
void create_client_server(t_server *server);
int error(char *str);

void if_ls(int fd);
void if_pwd(int fd);
void create_client_server(t_server *server);
void parse_cd(int fd, t_server *server, char **store);
void clear_buff(char *buf, int size);
void    error_cases(char **store, int fd);
#endif
