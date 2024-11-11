/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:09:48 by hsoysal           #+#    #+#             */
/*   Updated: 2024/11/11 23:26:21 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../../signals/sigint/sigint.h"
#include "../../structures/commande/commande.h"
#include "../../utils/mini_libft/mini_libft.h"
#include"../../structures/env/env.h"
#include "internal.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>



void comm_free(t_commande **commands)
{
    if (!commands)
        return;

    int i = 0;
    while (commands[i])
    {
        // Libère chaque `t_commande` individuellement
        if (commands[i])
        {
            free(commands[i]->name);
            free(commands[i]->path);

            if (commands[i]->args)
            {
                int j = 0;
                while (commands[i]->args[j])
                {
                    free(commands[i]->args[j]);
                    j++;
                }
                free(commands[i]->args);
            }

            if (commands[i]->infiles)
            {
                int j = 0;
                while (commands[i]->infiles[j])
                {
                    free(commands[i]->infiles[j]); // Ajustez si nécessaire
                    j++;
                }
                free(commands[i]->infiles);
            }

            if (commands[i]->outfiles)
            {
                int j = 0;
                while (commands[i]->outfiles[j])
                {
                    free(commands[i]->outfiles[j]); // Ajustez si nécessaire
                    j++;
                }
                free(commands[i]->outfiles);
            }

            free(commands[i]); // Libère la structure `t_commande`
        }
        i++;
    }

    free(commands); // Libère le tableau de commandes
}

void	execute_external_command_bis(t_commande *command, char ***g_env)
{
	int	status;

	if (command_get_fd_infile(command) != 0)
		dup2(command_get_fd_infile(command), 0);
	if (command_get_fd_outfile(command) != 1)
		dup2(command_get_fd_outfile(command), 1);
	status = execve(command->path, command->args, *g_env);
	if (status == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(command->args[0], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		commands_free(command); 
        free_env(*g_env);
		
		exit(127);
	}
	exit(status);
}

void	execute_external_command(t_commande *command, char ***g_env)
{
	int	status;
	int	pid;

	pid = fork();
	if (pid == 0)
		execute_external_command_bis(command, g_env);
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && g_sigint == 0)
			get_exit_status(WEXITSTATUS(status));
	}
	else
	{
		ft_putstr_fd("minishell: fork failed\n", 2);
		get_exit_status(1);
	}
}
