/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:46:57 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/11 00:38:41 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec/executor.h"
#include "minishell.h"
#include "signals/sigint/sigint.h"
#include "structures/commande/commande.h"
#include "structures/env/env.h"
#include "utils/checker/checker.h"
#include "utils/mini_libft/mini_libft.h"
#include "utils/parser/parser.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

static void	execute_single_command(t_commande *command, char ***g_env)
{
	int	status;
	int	pid;
	int	exit_status;
	int	fd_in;
	int	fd_out;

	if (command != NULL && command_can_be_executed(command)
		&& command->name != NULL)
	{
		if (is_builtin(command))
		{
			fd_in = command_get_fd_infile(command);
			fd_out = command_get_fd_outfile(command);
			if (fd_in != 0)
				dup2(fd_in, 0);
			if (fd_out != 1)
				dup2(fd_out, 1);
			status = execute_builtin(command, g_env);
			if (fd_in != 0)
				close(fd_in);
			if (fd_out != 1)
				close(fd_out);
			(get_exit_status(status));
			return ;
		}
		pid = fork();
		if (pid == 0)
		{
			if (command_get_fd_infile(command) != 0)
				dup2(command_get_fd_infile(command), 0);
			if (command_get_fd_outfile(command) != 1)
				dup2(command_get_fd_outfile(command), 1);
			status = execute_command(command, g_env);
			if (status == -1)
			{
				ft_putstr_fd("minishell: ", 2);
				ft_putstr_fd(command->args[0], 2);
				ft_putstr_fd(": ", 2);
				ft_putstr_fd(strerror(errno), 2);
				ft_putstr_fd("\n", 2);
				exit(127);
			}
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
				get_exit_status(WEXITSTATUS(status));
		}
		else
		{
			ft_putstr_fd("minishell: fork failed\n", 2);
			get_exit_status(1);
		}
	}
}

static bool	is_single_command(t_commande **commands)
{
	return (commands[1] == NULL);
}

static void	execute_alll_commands(t_commande **commands, char ***g_env)
{
	int	i;

	i = -1;
	while (commands[++i])
	{
		execute_single_command(commands[i], g_env);
	}
}

int	main(int argc, char const *argv[], char *envp[])
{
	char			*command_line;
	t_syntax_error	error;
	t_commande		**commands;
	int				i;
	char			***g_env;

	setup_sigint();
	g_env = get_envp(envp);
	while (1)
	{
		prompt();
		command_line = ft_get_next_line(0);
		if (command_line == NULL)
			return (free_env(*g_env), write(1, "\n", 1),
				get_exit_status(_LAST_STATUS));
		error = check_syntax(command_line);
		if (error != NO_ERROR)
			print_error(error);
		else
		{
			commands = parse_command_line(command_line, *g_env);
			if (is_single_command(commands))
				execute_single_command(commands[0], g_env);
			else
				execute_alll_commands(commands, g_env);
			free_commands(commands);
		}
		free(command_line);
	}
	free_env(*g_env);
	return (get_exit_status(_LAST_STATUS));
}
