/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:09:48 by hsoysal           #+#    #+#             */
/*   Updated: 2024/11/30 17:45:12 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../../signals/sigint/sigint.h"
#include "../../structures/commande/commande.h"
#include "../../structures/env/env.h"
#include "../../utils/mini_libft/mini_libft.h"
#include "single_exec.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void	execute_external_command_bis(t_commande **commands, t_commande *command,
		char ***g_env)
{
	int	status;

	printf("pass in excute command bis\n");
	manage_redirections(command, commands, g_env);
	status = execve(command->path, command->args, *g_env);
	free_env(*g_env);
	if (status == -1)
		handle_execve_failure(commands, command, g_env);
	free_commands(commands);
	free_env(*g_env);
	exit(status);
}

void	print_redirection_error(char *cmd_name)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}

void	handle_wait(pid_t pid)
{
	int		status;
	pid_t	result;

	while (1)
	{
		result = waitpid(pid, &status, 0);
		if (result == -1)
		{
			if (errno == EINTR)
				continue ;
			perror("waitpid failed");
			set_exit_status(1);
			return ;
		}
		break ;
	}
	if (WIFEXITED(status) && g_sigint == 0)
		set_exit_status(WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		set_exit_status(128 + WTERMSIG(status));
}

void	handle_fork_error(void)
{
	ft_putstr_fd("minishell: fork failed\n", 2);
	set_exit_status(_EXIT_FORK);
}

void	execute_external_command(t_commande **commands, t_commande *command,
		char ***g_env)
{
	pid_t	pid;

	printf("pass execute_external_command\n");
	pid = fork();
	if (pid == 0)
	{
		printf("pass in  child cond if in execute_external_command\n");
		execute_external_command_bis(commands, command, g_env);
	}
	else if (pid > 0)
		handle_wait(pid);
	else
		handle_fork_error();
}
