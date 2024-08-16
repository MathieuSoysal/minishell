/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:08:28 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/16 22:15:48 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <stdio.h>
#include <stdlib.h>

void	clear_all(t_commande *commands)
{
	if (commands->fd_infile >= 0)
		close(commands->fd_infile);
	if (commands->fd_outfile >= 0)
		close(commands->fd_outfile);
}

int	ft_fork(pid_t pid)
{
	pid = fork();
	if (-1 == pid)
	{
		perror("fork");
		exit(1);
	}
	return (pid);
}

void	ft_pipe(t_commande *commands)
{
	if (-1 == pipe(commands->fd))
	{
		perror("pipe");
		exit(1);
	}
}
