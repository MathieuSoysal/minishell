/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:10:02 by hsoysal           #+#    #+#             */
/*   Updated: 2024/12/11 19:09:53 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../../signals/sigint/sigint.h"
#include "../../structures/commande/commande.h"
#include "../../structures/env/env.h"
#include "../../utils/checker/checker.h"
#include "../../utils/mini_libft/mini_libft.h"
#include "../../utils/parser/parser.h"
#include "../all_executors/executor.h"
#include "../with_pipes/execution.h"
#include "single_exec.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

bool	is_emptyy(char *str)
{
	int	i;

	i = -1;
	if (str == NULL)
		return (1);
	while (str[++i])
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
	return (1);
}

void	execute_single_command(t_commande **commands, t_commande *command,
		char ***g_env)
{
	if (command_can_be_executed(command) && !is_emptyy(command->name))
	{
		if (is_builtin(command))
		{
			if (ft_strcmp(command->name, "exit") == 0)
				free(commands);
			execute_builtins_without_fork(command, g_env);
		}
		else
			execute_external_command(commands, command, g_env);
	}
	else if (!command || !(command->name))
		get_exit_status(0);
	else
		get_exit_status(1);
}

bool	is_single_command(t_commande **commands)
{
	return (commands[1] == NULL);
}
