/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:25:55 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/12 01:22:31 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../structures/commande/commande.h"
#include "../../structures/env/env.h"
#include "execution.h"

void	exec_cmd(t_commande **commands, t_commande *command, char ***g_env)
{
	int	status;

	status = execute_command(command, g_env);
	if (status == -1)
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		free_commands(commands);
		free_env(*g_env);
		exit(127);
	}
	free_commands(commands);
	free_env(*g_env);
	exit(1);
}

void	ft_exec(t_commande **commands, int i, char ***envp)
{
	exec_cmd(commands, commands[i], envp);
	exit(EXIT_FAILURE);
}
