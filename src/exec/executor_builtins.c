/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:43:28 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/08 13:27:54 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins/builtins.h"
#include "../utils/mini_libft/mini_libft.h"
#include "executor.h"

bool	is_builtin(t_commande *command)
{
	if (equals(command->name, "echo"))
		return (true);
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
	return (false);
}

void	execute_builtin(t_commande *command, char ***g_env)
{
	if (equals(command->name, "echo"))
		echo(command);
	else if (equals(command->name, "cd"))
		cd(command, *g_env);
	else if (equals(command->name, "export"))
		export(command, g_env);
	else if (equals(command->name, "unset"))
		unset(command, g_env);
	else if (equals(command->name, "env"))
		env(command, *g_env);
	else if (equals(command->name, "pwd"))
		pwd(command);
}
