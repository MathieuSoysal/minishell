/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:22:41 by hsoysal           #+#    #+#             */
/*   Updated: 2024/11/13 16:21:16 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../structures/env/env.h"
#include "../mini_libft/mini_libft.h"
#include "../parser/internal_parser.h"
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>

int	heredoc(char *delimiter)
{
	int		fd[2];
	char	*line;

	pipe(fd);
	while (1)
	{
		line = readline("heredoc> ");
		if (!line)
			write(1, "\n", 1);
		if (!line || ft_strcmp(line, delimiter) == 0)
			break ;
		line = apply_dollars(line, *get_envp(NULL));
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
	}
	close(fd[1]);
	return (fd[0]);
}
