/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:06:29 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/30 15:02:18 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char	*ft_init_line_helper(char **line, char **rest)
{
	char	*str;

	*line = *rest;
	str = ft_strchr(*rest, '\n');
	if (str)
	{
		str++;
		if (*str != '\0')
			*rest = ft_strdup(str);
		else
			*rest = NULL;
		*str = '\0';
	}
	else
		*rest = NULL;
	return (str);
}

bool	ft_init_line(char **rest, char **line)
{
	char	*str;

	str = NULL;
	if (*rest)
		str = ft_init_line_helper(line, rest);
	else
	{
		*line = (char *)malloc(sizeof(char) * 1);
		if (*line == NULL)
			return (false);
		*line[0] = '\0';
	}
	return (str == NULL);
}

bool	ft_append_to_line(char **rest, char **line, char **buf)
{
	char	*str;
	char	*tmp;

	str = ft_strchr(*buf, '\n');
	if (str)
	{
		str++;
		if (*str != '\0')
			*rest = ft_strdup(str);
		*str = '\0';
	}
	tmp = *line;
	*line = ft_strjoin(*line, *buf);
	free(tmp);
	return (str == NULL);
}

char	*ft_get_next_line(int fd)
{
	char		*buf;
	int			i;
	static char	*rest[1024];
	char		*line;
	bool		can_continue;

	if (BUFFER_SIZE < 1 || read(fd, 0, 0) == -1 || fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	can_continue = ft_init_line(&rest[fd], &line);
	i = 1;
	while (can_continue && i && line != NULL)
	{
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
		can_continue = ft_append_to_line(&rest[fd], &line, &buf);
	}
	free(buf);
	if (line == NULL || ft_strlen(line) > 0)
		return (line);
	free(line);
	return (NULL);
}
