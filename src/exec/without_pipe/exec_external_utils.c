/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:18:41 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/29 11:30:07 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../../signals/sigint/sigint.h"
#include "../../structures/commande/commande.h"
#include "../../structures/env/env.h"
#include "../../utils/mini_libft/mini_libft.h"
#include "single_exec.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void	manage_redirections(t_commande *command, t_commande **commands,
		char ***g_env)
{
	handle_input_redirection(command, commands, g_env);
	handle_output_redirection(command, commands, g_env);
}

void	handle_input_redirection(t_commande *command, t_commande **commands,
		char ***g_env)
{
	if (command_get_fd_infile(command) != 0)
	{
		if (dup2(command_get_fd_infile(command), 0) == -1)
		{
			print_redirection_error(command->args[0]);
			free_commands(commands);
			free_env(*g_env);
			exit(1);
		}
	}
}

void	handle_output_redirection(t_commande *command, t_commande **commands,
		char ***g_env)
{
	if (command_get_fd_outfile(command) != 1)
	{
		if (dup2(command_get_fd_outfile(command), 1) == -1)
		{
			print_redirection_error(command->args[0]);
			free_commands(commands);
			free_env(*g_env);
			exit(1);
		}
	}
}

void	handle_execve_failure(t_commande **commands, t_commande *command,
		char ***g_env)
{
	(void)g_env;
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command->args[0], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	free_commands(commands);
	if (errno == EACCES)
		exit(126);
	else if (errno == ENOENT)
		exit(127);
	else
		exit(1);
}
