/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:43:28 by hsoysal           #+#    #+#             */
/*   Updated: 2024/12/04 13:35:30 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtins/builtins.h"
#include "../../utils/mini_libft/mini_libft.h"
#include "executor_internal.h"

bool	is_builtin(t_commande *command)
{
	printf("pass  in  is builtin  begin\n");
	if (equals(command->name, "echo"))
	{
		printf("pass in echo\n");
		return (true);
	}
	if (equals(command->name, "cd"))
		return (true);
	if (equals(command->name, "export"))
		return (true);
	if (equals(command->name, "unset"))
		return (true);
	if (equals(command->name, "env"))
		return (true);
	if (equals(command->name, "exit"))
		return (true);
	if (equals(command->name, "pwd"))
		return (true);
	printf("pass  in  is builtin  begin end\n");
	return (false);
}

int	execute_builtin(t_commande *command, char ***g_env)
{
	if (equals(command->name, "echo"))
		return (echo(command));
	else if (equals(command->name, "cd"))
		return (cd(command, *g_env));
	else if (equals(command->name, "export"))
		return (export(command, g_env));
	else if (equals(command->name, "unset"))
		return (unset(command, g_env));
	else if (equals(command->name, "env"))
		return (env(command, *g_env));
	else if (equals(command->name, "pwd"))
		return (pwd(command));
	else if (equals(command->name, "exit"))
		return (bultin_exit(command));
	return (0);
}
