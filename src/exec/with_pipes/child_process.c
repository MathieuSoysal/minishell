/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:16:23 by kahoumou          #+#    #+#             */
/*   Updated: 2024/12/10 14:11:19 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "execution.h"
#include "internal.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void	child_process(int infile, int outfile, t_commande **commands, t_fd *fds)
{
	setup_command_signals();
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (fds->i > 0)
		dup_two_infile(infile);
	if (commands[fds->i + 1] != NULL)
		dup_fd_one(fds->fd);
	else if (outfile != -1 && outfile != STDOUT_FILENO)
		dup_two_outfile(outfile);
	if (commands[fds->i + 1] != NULL)
		close(fds->fd[0]);
}

void	else_if_in_child_process(int *infile, t_commande **commands, int i,
		int *fd)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_DFL);
	if (*infile > 0)
		close(*infile);
	if (commands[i + 1] != NULL)
	{
		close(fd[1]);
		*infile = fd[0];
	}
}

void	ft_final_close(t_commande **commands, int i, int *fd)
{
	if (commands[i] != NULL && commands[i + 1] != NULL)
		close(fd[0]);
}

// void	ft_final_close(t_commande **commands, int i, int *fds)
// {
// 	int	j;

// 	if (commands[i] != NULL && commands[i + 1] != NULL)
// 		close(fds[0]);
// 	j = 0;
// 	while (j < i)
// 	{
// 		if (fds[j] > 1)
// 			close(fds[j]);
// 		j++;
// 	}
// }

void	outfile_fcnlt(int outfile, t_fd *fds)
{
	outfile = fcntl(fds->fd_outfile, F_DUPFD, 10);
	if (outfile == -1)
	{
		perror("dup failed for outfile");
		exit(EXIT_FAILURE);
	}
	close(fds->fd_outfile);
}
