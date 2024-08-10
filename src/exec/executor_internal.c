/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_internal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:48:05 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/10 06:02:57 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor_internal.h"
#include <unistd.h>

int	execute_command(t_commande *command, char ***g_env)
{
	if (all_infiles_exist(command) && all_outfiles_have_permissions(command))
	{
		create_all_outfiles(command);
		if (is_builtin(command))
			return (execute_builtin(command, g_env));
		else
			return (execve(command->path, command->args, *g_env));
	}
	return (2);
}

int	execute_command_in_pipe(t_commande *command, char **g_env)
{
	return (execute_command(command, &g_env));
}
