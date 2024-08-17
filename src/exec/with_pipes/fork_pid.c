/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:08:28 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/17 13:37:06 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "execution.h"

void clear_all(t_commande *commands) 
{
    if (commands -> fd_infile >= 0)
        close(commands->fd_infile);
    if (commands->fd_outfile >= 0)
        close(commands->fd_outfile);
//     if (pipex->here_doc)
//         unlink(HEREDOC);
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
void	ft_pid(t_commande *commands)
{
	if (-1 == pipe(commands->fd))
	{
		perror("pipe");
		exit(1);
	}
}

