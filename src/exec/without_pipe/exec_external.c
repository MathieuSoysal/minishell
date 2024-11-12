/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:09:48 by hsoysal           #+#    #+#             */
/*   Updated: 2024/11/12 00:24:14 by hsoysal          ###   ########.fr       */
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

	if (command_get_fd_infile(command) != 0)
		dup2(command_get_fd_infile(command), 0);
	if (command_get_fd_outfile(command) != 1)
		dup2(command_get_fd_outfile(command), 1);
	status = execve(command->path, command->args, *g_env);
	free_env(*g_env);
	if (status == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(command->args[0], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		free_commands(commands);
		exit(127);
	}
	free_commands(commands);
	exit(status);
}

void	execute_external_command(t_commande **commands, t_commande *command,
		char ***g_env)
{
	int	status;
	int	pid;

	pid = fork();
	if (pid == 0)
		execute_external_command_bis(commands, command, g_env);
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && g_sigint == 0)
			get_exit_status(WEXITSTATUS(status));
	}
	else
	{
		ft_putstr_fd("minishell: fork failed\n", 2);
		get_exit_status(1);
	}
}
