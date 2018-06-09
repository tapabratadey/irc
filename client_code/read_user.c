/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_user.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:04:31 by tadey             #+#    #+#             */
/*   Updated: 2018/06/08 15:04:32 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

char	*read_user(char *line)
{
	int		read_ret;
	char	buff[2];
	char	*old_line;

	read_ret = 0;
	while ((read_ret = read(0, buff, 1)) > 0)
	{
		buff[1] = '\0';
		old_line = line;
		line = ft_strjoin(line, buff);
		free(old_line);
		if (buff[0] == '\n')
			break ;
	}
	return (line);
}
