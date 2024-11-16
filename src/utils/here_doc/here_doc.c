/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:22:41 by hsoysal           #+#    #+#             */
/*   Updated: 2024/11/14 08:11:30 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../../signals/sigint/sigint.h"
#include "../../structures/env/env.h"
#include "../mini_libft/mini_libft.h"
#include "../parser/internal_parser.h"
#include <readline/readline.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	signal_sigint_heredoc(int sig)
{
	char	*prompt;

	(void)sig;
	get_exit_status(130);
	prompt = get_prompt();
	rl_set_prompt(prompt);
	rl_replace_line("", 0);
	write(1, "\n", 1);
	free(prompt);
	rl_on_new_line();
	rl_redisplay();
	get_exit_status(130);
	g_sigint = SIGINT;
}

int	heredoc(char *delimiter)
{
	int		fd[2];
	char	*line;

	pipe(fd);
	signal(SIGINT, signal_sigint_heredoc);
	g_sigint = 0;
	while (1)
	{
		if (g_sigint > 0)
			return (close(fd[1]), close(fd[0]) - 1);
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
