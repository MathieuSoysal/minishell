/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:35:15 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/17 01:31:16 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "execution.h"
#include "internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

pid_t	*init_pids(t_commande **commands)
{
	pid_t	*pids;
	int		i;

	i = 0;
	while (commands[i])
		i++;
	pids = ft_calloc(sizeof(pid_t), (i + 1));
	return (pids);
}

void	ft_wait(t_commande **commands, pid_t *pids, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (commands[i] != NULL)
		{
			ft_close(commands[i], "in", 1);
			waitpid(pids[i], NULL, 0);
			commands[i]->fd_infile = commands[i]->fd[0];
		}
		i++;
	}
}

void	init_fds(t_commande *command)
{
	command->fd_infile = command_get_fd_infile(command);
	command->fd_outfile = command_get_fd_outfile(command);
}

int	process_command_with_fork(t_commande *command, char ***envp,
		bool is_not_last_command)
{
	pid_t	pid;

	pid = 0;
	ft_pipe(command);
	pid = ft_fork(pid);
	if (0 == pid)
	{
		init_fds(command);
		if (is_not_last_command)
			ft_dup_two(command, "no", 1);
		ft_close(command, "out", 0);
		exec_cmd(command, envp);
	}
	return (pid);
}

void	process_commands(t_commande **commands, char ***envp)
{
	int		i;
	pid_t	*pids;

	i = -1;
	pids = init_pids(commands);
	if (pids == NULL)
		return ;
	while (commands[++i])
	{
		if (command_can_be_executed(commands[i]))
		{
			if (commands[i + 1] != NULL)
				pids[i] = process_command_with_fork(commands[i], envp, true);
			else
				pids[i] = process_command_with_fork(commands[i], envp, false);
		}
	}
	ft_wait(commands, pids, i);
	free(pids);
	ft_dup_two(commands[i], "in", -1);
	ft_dup_two(commands[i], "out", -1);
}
