/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:06:29 by hsoysal           #+#    #+#             */
/*   Updated: 2024/11/09 15:22:57 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char	*tronc_buf_and_get_rest(char *buf)
{
	char	*str;
	char	*rest;

	str = ft_strchr(buf, '\n');
	rest = NULL;
	if (str)
	{
		str++;
		if (*str != '\0')
			rest = ft_strdup(str);
		*str = '\0';
	}
	return (rest);
}

bool	ft_append_to_line(char **rest, char **line, char *buf)
{
	char	*tmp;

	*rest = tronc_buf_and_get_rest(buf);
	if (*line == NULL)
		*line = ft_strdup(buf);
	else
	{
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
		tmp = NULL;
	}
	return (rest == NULL);
}

char	*ft_get_next_line(int fd)
{
	char		*buf;
	int			i;
	static char	*rest[1024];
	char		*line;
	int			can_read;

	line = NULL;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) == -1 || fd < 0)
		return (NULL);
	can_read = 1;
	i = 1;
	while (can_read && i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i > 0)
		{
			can_read = ft_append_to_line(&rest[fd], &line, buf);
			ft_bzero(buf, BUFFER_SIZE + 1);
		}
	}
	return (line);
}
