/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:43:28 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/07 19:23:43 by kahoumou         ###   ########.fr       */
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
	return (false);
}

void	execute_builtin(t_commande *command, char **envp)
{
	if (equals(command->name, "echo"))
		echo(command);
	else if (equals(command->name, "cd"))
		cd(command, envp);
}
