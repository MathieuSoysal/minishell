/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:37:19 by kahoumou          #+#    #+#             */
/*   Updated: 2024/12/12 12:22:48 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec/all_executors/executor.h"
#include "exec/with_pipes/execution.h"
#include "exec/without_pipe/single_exec.h"
#include "minishell.h"
#include "signals/sigint/sigint.h"
#include "structures/commande/commande.h"
#include "structures/env/env.h"
#include "utils/checker/checker.h"
#include "utils/mini_libft/mini_libft.h"
#include "utils/parser/parser.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static void	execute_alll_commands(t_commande **commands, char ***g_env,
		t_fd *fds)
{
	int		j;
	pid_t	result;
	int		status;

	j = command_count(commands);
	process_commands(commands, g_env, fds);
	while (j > 0)
	{
		result = waitpid(0, &status, 0);
		if (result == -1)
		{
			if (errno == EINTR)
				continue ;
			perror("waitpid failed");
			set_exit_status(1);
			return ;
		}
		j--;
	}
	error_all_cmd(status);
}

static bool	is_a_valid_command_line(const char *command_line)
{
	t_syntax_error	error;

	error = check_syntax(command_line);
	if (error != NO_ERROR)
		return (print_error(error), false);
	return (is_not_empty(command_line));
}

static char	*read_command_line(void)
{
	char	*command_line;
	char	*prompt;

	g_sigint = 0;
	prompt = get_prompt();
	rl_readline_name = "minishell";
	command_line = readline(prompt);
	free(prompt);
	if (command_line == NULL)
	{
		free_env(*get_envp(NULL));
		write(1, "exit\n", 6);
		exit(get_exit_status(_LAST_STATUS));
	}
	return (command_line);
}

static void	process_commands_loop(char ***g_env)
{
	char		*command_line;
	t_commande	**commands;
	t_fd		fds;

	command_line = NULL;
	while (1)
	{
		restore_signals_for_readline();
		command_line = read_command_line();
		add_history(command_line);
		if (is_a_valid_command_line(command_line))
		{
			commands = parse_command_line(command_line, *g_env);
			if (commands == NULL)
				continue ;
			if (is_single_command(commands))
				execute_single_command(commands, commands[0], g_env);
			else
			{
				execute_alll_commands(commands, g_env, &fds);
			}
			free_commands(commands);
		}
		free(command_line);
	}
}

int	main(int argc, char const *argv[], char *envp[])
{
	char	***g_env;

	setup_sigint();
	g_env = get_envp(envp);
	arg_is_void_and_signt_init(argc, *argv);
	process_commands_loop(g_env);
	return (rl_clear_history(), free_env(*g_env),
		get_exit_status(_LAST_STATUS));
}
