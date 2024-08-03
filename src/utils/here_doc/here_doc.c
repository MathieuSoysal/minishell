/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:22:41 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/03 13:14:39 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_libft/mini_libft.h"
#include <stdlib.h>
#include <unistd.h>

int	heredoc(char *delimiter)
{
	int		fd[2];
	char	*line;
	char	*new_delimiter;

	pipe(fd);
	new_delimiter = ft_strjoin(delimiter, "\n");
	while (1)
	{
		write(1, "heredoc> ", 10);
		line = ft_get_next_line(0);
		if (!line)
			write(1, "\n", 1);
		if (!line || ft_strcmp(line, new_delimiter) == 0)
			break ;
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	free(new_delimiter);
	close(fd[1]);
	return (fd[0]);
}
