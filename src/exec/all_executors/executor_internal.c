/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_internal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:48:05 by hsoysal           #+#    #+#             */
/*   Updated: 2024/12/12 13:05:23 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../minishell.h"
#include "executor.h"
#include "executor_internal.h"
#include <stdbool.h>
#include <unistd.h>

bool	command_can_be_executed(t_commande *command)
{
	if (command == NULL)
		return (false);
	if (all_infiles_exist(command) && all_outfiles_have_permissions(command))
	{
		create_all_outfiles(command);
		return (command->name != NULL);
	}
	return (false);
}

int	execute_command(t_commande *command, char ***g_env)
{
	int	status;

	if (is_builtin(command))
		return (execute_builtin(command, g_env));
	else
	{
		status = execve(command->path, command->args, *g_env);
		if (status == -1)
			return (status);
		else if (errno == ENOENT)
			return (_EXIT_SUCCESS);
		else
			return (_EXIT_ERROR);
	}
	return (2);
}

int	execute_command_in_pipe(t_commande *command, char **g_env)
{
	return (execute_command(command, &g_env));
}
