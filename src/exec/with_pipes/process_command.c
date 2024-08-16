/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:35:15 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/16 20:39:30 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ft_pid(t_commande  *commands)
{
	if (-1 == pipe(commands -> fd))
	{
		perror("pipe");
		exit(1);
	}
}
void	process_commands(t_commande  *commands, char ***envp)
{
	pid_t  pid;
	int i;
	
	while(commands -> args[i])
	{
		ft_pid(commands);
		if(0 == ft_fork(pid))
		{
			if(commands -> args[i + 1] != NULL)
				ft_dup_two(commands, "no", 1);
				ft_close(commands, "out", 0);
				exec_cmd(commands -> args[i], *envp);
		}
		else
		{
			ft_close(commands, "in", 1);
			waitpid(pid, NULL, 0);
			commands ->  fd_infile  =  commands -> fd[0];
			i ++;
		}
		
	}
	ft_dup_two(commands, "in", -1);
	ft_dup_two(commands, "out", -1);
	// exec_cmd(commands -> args[i], *envp);
}
