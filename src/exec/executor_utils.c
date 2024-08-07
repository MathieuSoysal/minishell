/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:43:28 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/04 22:47:35 by hsoysal          ###   ########.fr       */
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
	if (equals(command->name, "pwd"))
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

}
