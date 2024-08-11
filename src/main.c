/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:46:57 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/11 04:06:29 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec/executor.h"
#include "exec/without_pipe/single_exec.h"
#include "minishell.h"
#include "signals/sigint/sigint.h"
#include "structures/commande/commande.h"
#include "structures/env/env.h"
#include "utils/checker/checker.h"
#include "utils/mini_libft/mini_libft.h"
#include "utils/parser/parser.h"
#include <stdlib.h>
#include <unistd.h>

static void	execute_alll_commands(t_commande **commands, char ***g_env)
{
	int	i;

	i = -1;
	while (commands[++i])
		execute_single_command(commands[i], g_env);
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
